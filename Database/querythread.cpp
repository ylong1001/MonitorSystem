#include "querythread.h"
#include "sqliteutil.h"
#include <QDebug>
quint32 QueryThread::id = 0;
QueryThread::QueryThread(QObject* parent) :QThread(parent)
{
    //一个QObject正在接受事件队列时如果中途被你销毁掉了，出问题，deleteLater让所有事件都发送完一切处理好后再释放
	connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}

void QueryThread::setSql(QString sql)
{
	m_strSql = sql;
}

void QueryThread::setFileName(QString fileName)
{
	m_strFileName = fileName;
}

void QueryThread::run()
{
	SqliteUtil sql(m_strFileName, QString::number(id++));
	QSqlQueryModel* model = new QSqlQueryModel();
	model->setQuery(m_strSql, sql.getSqlDb());
	while (model->canFetchMore())  //不加只显示256行
		model->fetchMore();
	emit queryFinished(model);
}
