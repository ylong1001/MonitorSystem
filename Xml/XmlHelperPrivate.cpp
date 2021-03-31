#include "XmlHelperPrivate.h"

#include <QtCore/QTextStream>
#include <QtCore/QDateTime>


XmlHelperPrivate::XmlHelperPrivate()
    :m_valid(false)
{
}

XmlHelperPrivate::~XmlHelperPrivate()
{
}

bool XmlHelperPrivate::beginIO(const QString &fp,
                               const bool create,
                               const QString &root)
{
    m_valid = false;
    if (fp.isEmpty()) {
        m_errorString = "File name cannot be empty.";
        return false;
    }
    m_filepath = fp;
    m_rootNodeName = root;

    m_domdoc.clear();
    m_xmlFile.setFileName(fp);
    if (!m_xmlFile.exists()) {
        if (!create) {
            m_errorString = "Xml file not exist and not set the create flag";
            return false;
        }
        m_valid = createFile();
    }
    else {
        m_valid = openFile(QFile::ReadOnly);
    }

    return true;
}

bool XmlHelperPrivate::saveIO()
{
    if (!m_xmlFile.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)) {
        m_errorString = m_xmlFile.errorString();
        return false;
    }

    QTextStream stream(&m_xmlFile);
    stream.setCodec("UTF-8");
    m_domdoc.save(stream, 4, QDomNode::EncodingFromTextStream);
    m_xmlFile.close();

    return true;
}

bool XmlHelperPrivate::endIO()
{
    m_xmlFile.close();
    m_filepath.clear();
    m_errorString.clear();
    m_valid = false;
    return true;
}

bool XmlHelperPrivate::createFile()
{
    const QString cfg = "version=\"1.0\" encoding = \"UTF-8\"";
    QDomProcessingInstruction header = m_domdoc.createProcessingInstruction("xml", cfg);
    m_domdoc.appendChild(header);

    //root
    QDomElement root = m_domdoc.createElement(m_rootNodeName);
    m_domdoc.appendChild(root);

    return saveIO();
}

bool XmlHelperPrivate::openFile(const QIODevice::OpenMode flags)
{
    if (!m_xmlFile.open(flags)) {
        m_errorString = m_xmlFile.errorString();
        return false;
    }

    int row = 0, column = 0;
    bool ok = m_domdoc.setContent(&m_xmlFile, false,
                                  &m_errorString, &row, &column);
    m_xmlFile.close();
    if (!ok) {
        QString detailError = QString("row: %1, col: %2").arg(row).arg(column);
        m_errorString.append(detailError);

        m_domdoc.clear();
        return false;
    }

    if (m_domdoc.elementsByTagName(m_rootNodeName).isEmpty()) {
        m_errorString = "The root node's name not \"" + m_errorString + "\"";
        return false;
    }

    return true;
}

QStringList XmlHelperPrivate::getElemValue(const QString &elemName)
{
    QStringList valList;
    if (!m_valid) return valList;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList,strmap_t)) {
        return valList;
    }

    foreach (QDomElement elem, elemList) {
        valList << elem.text();
    }

    return valList;
}

QString XmlHelperPrivate::getFirstElemValue(const QString &elemName)
{
    QStringList valList = getElemValue(elemName);

    return valList.isEmpty() ? "" : valList.first();
}

bool XmlHelperPrivate::findElement(const QString &elemName,
                                   const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;
    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) {
        return false;
    }

    return elemList.size() != 0;
}

QStringList XmlHelperPrivate::getAttrValue(const QString &elemName,
                                           const QString &attrName,
                                           const QMap<QString, QString> &ctx)
{
    QStringList valList;
    if (!m_valid) return valList;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) {
        return valList;
    }

    foreach (QDomElement elem, elemList) {
        if (elem.hasAttribute(attrName)) {
            valList << elem.attribute(attrName);
        }
    }

    return valList;
}

QString XmlHelperPrivate::getFirstAttrValue(const QString &elemName,
                                            const QString &attrName,
                                            const QMap<QString, QString> &ctx)
{
    QStringList valList = getAttrValue(elemName, attrName, ctx);

    return valList.isEmpty() ? "" : valList.first();
}

bool XmlHelperPrivate::getAllSpecifyElem(const QString &elemName,
                                         QList<QDomElement> &elemList,
                                         const QMap<QString, QString> &ctx)
{
    QStringList tagList = elemName.split("/");
    if (tagList.isEmpty()) return false;

    QList<QDomElement> elemListtmp;
    QDomElement root = m_domdoc.documentElement();
    if (root.tagName() == elemName) {
        elemList << root;
        return true;
    }

    if (root.tagName() == tagList.first()) {
        tagList.removeFirst();
    }

    getSpecifyElem(root, tagList, elemListtmp);

    foreach (QDomElement elem, elemListtmp) {
        if (isSpecifyElement(elem, ctx)) {
            elemList << elem;
        }
    }
    return elemList.size() != 0;
}

bool XmlHelperPrivate::getSpecifyElem(const QString &elemName,
                                      const bool create,
                                      QDomElement &domElem,
                                      bool &newElem)
{
    QStringList tagNameList = elemName.split("/");
    if (tagNameList.isEmpty()) return false;

    domElem = m_domdoc.documentElement();

    foreach (QString tagName, tagNameList) {
        if (tagName.isEmpty()) continue;
        QDomNodeList nodeListtmp = domElem.elementsByTagName(tagName);

        if (!nodeListtmp.isEmpty()) {
            QDomElement nodeTmp_ = nodeListtmp.at(0).toElement();
            domElem = nodeTmp_;
        }
        else {
            if (!create) {
                m_errorString = QString("Element \"%1\" was not found.")
                    .arg(elemName);
                return false;
            }
            else {
                QDomElement elemtmp = m_domdoc.createElement(tagName);
                domElem.appendChild(elemtmp);
                domElem = elemtmp;
                newElem = true;
            }
        }
    }

    return true;
}

bool XmlHelperPrivate::getSpecifyElem(QDomElement &elem,
                                      QStringList tagList,
                                      QList<QDomElement> &elemList)
{
    if (tagList.isEmpty()) {
        elemList.append(elem);
        return true;
    }

    QStringList taglisttmp = tagList;
    QDomNodeList nodelist = elem.elementsByTagName(taglisttmp.first());
    taglisttmp.removeFirst();
    for (int i = 0; i < nodelist.size(); ++i) {
        QDomElement elemtmp = nodelist.at(i).toElement();
        getSpecifyElem(elemtmp, taglisttmp, elemList);
    }

    return true;
}

bool XmlHelperPrivate::isSpecifyElement(const QDomElement &elem,
                                        const QMap<QString, QString> &ctx)
{
    if (ctx.empty()) return true;

    QString key, val;
    QMap<QString, QString>::const_iterator iter = ctx.begin();
    for (; iter != ctx.end(); ++iter) {
        key = iter.key();
        val = iter.value();
        if (!elem.hasAttribute(key) || elem.attribute(key) != val) {
            return false;
        }
    }

    return true;
}

bool XmlHelperPrivate::updateElem(const QString &elemName,
                                  const QString &value,
                                  const bool create)
{
    if (!m_valid) return false;

    QDomElement domElem;
    bool newElem = false;
    if (!getSpecifyElem(elemName, create, domElem, newElem)) {
        return false;
    }

    if (newElem) {
        QDomText domText_ = m_domdoc.createTextNode(value);
        domElem.appendChild(domText_);
    }
    else {
        domElem.firstChild().setNodeValue(value);
    }

    return true;
}

bool XmlHelperPrivate::updateAttr(const QString &elemName,
                                  const QMap<QString, QString> &attrmap,
                                  const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) return false;

    foreach (QDomElement elem, elemList) {
        QMap<QString, QString>::const_iterator iter = attrmap.begin();
        for (; iter != attrmap.end(); ++iter) {
            QString attr = iter.key();
            QString val = iter.value();
            if (attr.isEmpty()) continue;
            elem.setAttribute(attr, val);
        }
    }

    return true;
}

bool XmlHelperPrivate::addChildTextNode(const QString &elemName,
                                        const QString &childName,
                                        const QString &childValue,
                                        const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) return false;

    foreach (QDomElement elem, elemList) {
        QDomElement childElem = m_domdoc.createElement(childName);
        QDomText domText = m_domdoc.createTextNode(childValue);
        childElem.appendChild(domText);
        elem.appendChild(childElem);
    }

    return true;
}

bool XmlHelperPrivate::addChildAttrNode(const QString &elemName,
                                        const QString &childName,
                                        const QMap<QString, QString> &attrmap,
                                        const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) return false;

    foreach (QDomElement elem, elemList) {
        QDomElement childElem = m_domdoc.createElement(childName);
        QMap<QString, QString>::const_iterator iter = attrmap.begin();
        for (; iter != attrmap.end(); ++iter) {
            QDomAttr attrNode = m_domdoc.createAttribute(iter.key());
            attrNode.setValue(iter.value());
            childElem.setAttributeNode(attrNode);
        }
        elem.appendChild(childElem);
    }

    return true;
}

QStringList XmlHelperPrivate::getChildTextNodeValue(const QString &elemName,
                                                    const QMap<QString, QString> &ctx)
{
    if (!m_valid) return QStringList();

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) {
        return QStringList();
    }

    QStringList valList;
    foreach (QDomElement elem, elemList) {
        QDomNodeList childNodeList = elem.childNodes();
        for (int i = 0; i < childNodeList.size(); ++i) {
            valList << childNodeList.at(i).toElement().text();
        }
    }

    return valList;
}

QList< QMap<QString, QString> > XmlHelperPrivate::getChildAttrNodeAttr(const QString &elemName,
                                                    const QMap<QString, QString> &ctx)
{
    QList< QMap<QString, QString> > attrmapList;
    if (!m_valid) return attrmapList;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) return attrmapList;



    foreach (QDomElement elem, elemList) {
        QDomNodeList childNodeList = elem.childNodes();
        for (int i = 0; i < childNodeList.size(); ++i) {
            QDomNode childNode_ = childNodeList.at(i);
            QDomNamedNodeMap attrList = childNode_.attributes();
            QMap<QString, QString> attrmap;
            for (int i = 0; i < attrList.size(); ++i) {
                QDomAttr attr = attrList.item(i).toAttr();
                attrmap[attr.name()] = attr.value();
            }
            if (!attrmap.isEmpty()) {
                attrmapList << attrmap;
            }
        }
    }

    return attrmapList;
}

bool XmlHelperPrivate::removeElem(const QString &elemName,
                                  const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;

    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) return true;

    foreach (QDomElement elem,elemList) {
        QDomNode parentNode = elem.parentNode();
        parentNode.removeChild(elem);
        if (parentNode.childNodes().isEmpty()&& parentNode != m_domdoc.documentElement()) {
            parentNode.parentNode().removeChild(parentNode);
        }
    }

    return true;
}

bool XmlHelperPrivate::removeAttr(const QString &elemName,
                                  const QString &attrName,
                                  const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;

    QList<QDomElement> elemList_;
    if (!getAllSpecifyElem(elemName, elemList_, ctx)) return true;

    foreach (QDomElement elem, elemList_) {
        elem.removeAttribute(attrName);
    }

    return true;
}

bool XmlHelperPrivate::toComment(const QString &elemName,
                                 const bool reviseTime,
                                 const QMap<QString, QString> &ctx)
{
    if (!m_valid) return false;
    QList<QDomElement> elemList;
    if (!getAllSpecifyElem(elemName, elemList, ctx)) {
        m_errorString = QString("Element \"%1\" was not found.").arg(elemName);
        return false;
    }

    //add commnet datetime;
    if (reviseTime) {
        const char *format = "yyyy-MM-dd hh:mm:ss";
        foreach (QDomElement var, elemList) {
            QDomElement parent = var.parentNode().toElement();
            QString dt = QDateTime::currentDateTime().toString(format);
            QDomComment cmt = m_domdoc.createComment(dt);
            parent.insertBefore(cmt, var);
        }
        //if add the new element, get the specify element again;
        elemList.clear();
        getAllSpecifyElem(elemName, elemList, ctx);
    }

    //replace the string for comment;
    const int identity = 4;
    QString xmlText;
    QTextStream xmlStream(&xmlText);
    m_domdoc.save(xmlStream, identity);

    bool ok = true;
    foreach (QDomElement var, elemList) {
        QString oldNodeStr;
        QTextStream oldNodeStream(&oldNodeStr);
        var.save(oldNodeStream, identity);

        int idx = xmlText.indexOf(oldNodeStr);
        if (idx == -1) {
            ok = false;
            continue;
        }

        QString newNodeStr = oldNodeStr;
        newNodeStr.insert(identity + 1, "!--");
        newNodeStr.insert(newNodeStr.length() - 2, "--");

        xmlText.replace(idx, oldNodeStr.length(), newNodeStr);
    }

    //reset the cotent to xml domdocument;
    int row = 0, column = 0;
    bool okII_ = m_domdoc.setContent(xmlText, false,
                                     &m_errorString, &row, &column);
    if (!okII_) {
        m_errorString += QString(", row: %1, col: %2").arg(row).arg(column);
        return false;
    }

    return ok;
}
