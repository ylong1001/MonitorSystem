#ifndef SQLITEUTIL_H
#define SQLITEUTIL_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlRecord>

class SqliteUtil
{
public:
	explicit SqliteUtil(const QString& strDatabase, const QString& strConn);
	SqliteUtil();
	~SqliteUtil();
	QSqlDatabase getSqlDb();
	bool createConnection();
	void closeConnection();
	QSqlRecord ExecuteRecord(const QString& strQuery);
	QSqlRecord ExecuteRecord(const QString& strQuery, QList<QVariant> lstParameter);
	QSqlRecord ExecuteRecord(const QString& strQuery, QVariant Parameter);

	QSqlQuery ExecuteSqlQuery(const QString& strQuery, QList<QVariant> lstParameter);
	QSqlQuery ExecuteSqlQuery(const QString& strQuery, QVariant Parameter);
	QSqlQuery ExecuteSqlQuery(const QString& strQuery);

	int ExecuteInt(const QString& strQuery);
	int ExecuteInt(const QString& strQuery, QList<QVariant> lstParameter);
	int ExecuteInt(const QString& strQuery, QVariant Parameter);

	bool Execute(const QString& strQuery, QVariant Parameter);
	bool Execute(const QString& strQuery, QList<QVariant> lstParameter);

	void ExecuteString(const QString& strQuery);

	void ExecuteQueryModel(QSqlQueryModel* p_queryModel, const QString& strQuery);
	void ExecuteQueryModel(QSqlQueryModel* p_queryModel, const QString& strQuery,
		QList<QVariant> lstParameter);
	void ExecuteQueryModel(QSqlQueryModel* p_queryModel, const QString& strQuery, QVariant Parameter);

	void createTable(QString tableName, QVector<QString> fdNameTypePairs);//fdNameTypePairs 字段名称，类型对列表
	void deleteTable(QString tableName);
	QVector<QString> getAllTableName();

	void addRecord(QString tableName, QVector<QString> fdNameValuePairs);
	void delRecord(QString tableName, QString condition);
	void setRecord(QString tableName, QVector<QString> fdNameValuePairs, QString condition);
	QVector<QString> getFirstRecord(QString tableName, QVector<QString> fdNames, QString condition);

	QString vectorToString(const QVector<QString>& list, QString split) const;
	QString getLastSqlString() const;
	QString getLastErrorText() const;
	QSqlDatabase getSqlDatabase() const;
	bool beginTransaction();
	bool commitTransaction();


private:
	QSqlDatabase m_db;
	QString m_strDatabase;
	QString m_strConn;
	QString lastSqlString;
	QString lastErrorText;
};

#endif // SQLITEUTIL_H
