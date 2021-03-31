#ifndef QUERYTHREAD_H
#define QUERYTHREAD_H

#include <QThread>
#include <QSqlQueryModel>

class QueryThread : public QThread
{
	Q_OBJECT
public:
	explicit QueryThread(QObject* parent = 0);
	void setSql(QString sql);
	void setFileName(QString fileName);
	static quint32 id;
	// QThread interface
protected:
	void run();
private:
	QString m_strSql;
	QString m_strFileName;
signals:
	void queryFinished(QSqlQueryModel* model);
};

#endif // QUERYTHREAD_H
