#ifndef XmlHelperPrivate_h__
#define XmlHelperPrivate_h__

#include <QtCore/QString>
#include <QtCore/QMap>
#include <QtCore/QFile>
#include <QtXml/QDomDocument>
#include <QStringList>

class XmlHelperPrivate
{

public:
    XmlHelperPrivate();
    ~XmlHelperPrivate();
    QMap<QString, QString>  strmap_t;
    QList< QMap<QString, QString> > strmaplist_t;

    bool beginIO(const QString &fp, const bool create, const QString &root);
    bool saveIO();
    bool endIO();

    bool createFile();
    bool openFile(const QIODevice::OpenMode flags);

    QStringList getElemValue(const QString &elemName);
    QString getFirstElemValue(const QString &elemName);

    bool findElement(const QString &elemName,
                     const QMap<QString, QString> &ctx);

    QStringList getAttrValue(const QString &elemName,
                             const QString &attrName,
                             const QMap<QString, QString> &ctx);
    QString getFirstAttrValue(const QString &elemName,
                              const QString &attrName,
                              const QMap<QString, QString> &ctx);

    bool getAllSpecifyElem(const QString &elemName,
                           QList<QDomElement> &elemList,
                           const QMap<QString, QString> &ctx);
    bool getSpecifyElem(const QString &elemName,
                        const bool create,
                        QDomElement &domElem,
                        bool &newElem);
    bool getSpecifyElem(QDomElement &elem,
                        QStringList tagList,
                        QList<QDomElement> &elemList);
    bool isSpecifyElement(const QDomElement &elem,
                          const QMap<QString, QString> &ctx);

    bool updateElem(const QString &elemName,
                    const QString &value,
                    const bool create = false);
    bool updateAttr(const QString &elemName,
                    const QMap<QString, QString> &attrmap,
                    const QMap<QString, QString> &ctx);

    bool addChildTextNode(const QString &elemName,
                          const QString &childName,
                          const QString &childValue,
                          const QMap<QString, QString> &ctx);
    bool addChildAttrNode(const QString &elemName,
                          const QString &childName,
                          const QMap<QString, QString> &attrmap,
                          const QMap<QString, QString> &ctx);

    QStringList getChildTextNodeValue(const QString &elemName,
                                      const QMap<QString, QString> &ctx);

    QList< QMap<QString, QString> > getChildAttrNodeAttr(const QString &elemName,
                                      const QMap<QString, QString> &ctx);

    bool removeElem(const QString &elemName,
                    const QMap<QString, QString> &ctx);

    bool removeAttr(const QString &elemName,
                    const QString &attrName,
                    const QMap<QString, QString> &ctx);

    bool toComment(const QString &elemName,
                   const bool reviseTime,
                   const QMap<QString, QString> &ctx);

private:

    QString        m_filepath;
    QString        m_rootNodeName;
    QFile          m_xmlFile;
    QDomDocument   m_domdoc;

    bool m_valid;

    QString m_errorString;

};

#endif // XmlHelperPrivate_h__
