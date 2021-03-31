#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include "sqliteutil.h"


SqliteUtil::SqliteUtil(const QString& strDatabase, const QString& strConn) :
	m_strDatabase(strDatabase), m_strConn(strConn)
{
	createConnection();
}

SqliteUtil::SqliteUtil()
{

}

SqliteUtil::~SqliteUtil()
{
	m_db.close();
}

QSqlDatabase SqliteUtil::getSqlDb()
{
	return m_db;
}

//创建SQLite连接
bool SqliteUtil::createConnection()
{
	//与数据库建立连接
	if (QSqlDatabase::contains(m_strConn))
	{
		m_db = QSqlDatabase::database(m_strConn);//返回已存在的my_conn连接
	}
	else
	{
		m_db = QSqlDatabase::addDatabase("QSQLITE", m_strConn);//返回新加的名称为my_conn的连接
	}
	//设置数据库名，如果数据库不存在则创建，":memory:" 为内存数据库，此函数要在open前
	m_db.setDatabaseName(m_strDatabase);
	//打开数据库
	if (!m_db.open())
	{
		qDebug() << "Open database failed!";
		return false;
	}
	else
	{
		return true;
	}
}

void SqliteUtil::closeConnection()
{
	if (m_db.isOpen())
	{
		m_db.close();
	}
}


//执行SQL语句
QSqlRecord SqliteUtil::ExecuteRecord(const QString& strQuery)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.exec();
	return query.record();
}

//执行SQL语句(包含多个占位符)
QSqlRecord SqliteUtil::ExecuteRecord(const QString& strQuery, QList<QVariant> lstParameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	for (int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	query.exec();
	return query.record();
}

//执行SQL语句(包含一个占位符)
QSqlRecord SqliteUtil::ExecuteRecord(const QString& strQuery, QVariant Parameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	query.exec();
	return query.record();
}

//执行单向前查询(包含多个占位符)
QSqlQuery SqliteUtil::ExecuteSqlQuery(const QString& strQuery, QList<QVariant> lstParameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.setForwardOnly(true);
	query.prepare(strQuery);
	for (int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	query.exec();
	return query;
}

//执行单向前查询(包含一个占位符)
QSqlQuery SqliteUtil::ExecuteSqlQuery(const QString& strQuery, QVariant Parameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.setForwardOnly(true);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	query.exec();
	return query;
}

//执行单向前查询语句(无占位符)
QSqlQuery SqliteUtil::ExecuteSqlQuery(const QString& strQuery)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.setForwardOnly(true);
	query.prepare(strQuery);
	if (!query.exec()) {
		lastSqlString = strQuery;
		lastErrorText = query.lastError().text();
		qDebug() << "ExecuteSqlQuery failed!SQL string :" << lastSqlString << endl;
		qDebug() << "Error text:" << lastErrorText << endl;

	}
	return query;
}

//执行语句返回Int
int SqliteUtil::ExecuteInt(const QString& strQuery)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.exec();
	int ID = 0;
	while (query.next())
	{
		ID = query.value(0).toInt();
	}
	return ID;
}
//执行语句返回Int
int SqliteUtil::ExecuteInt(const QString& strQuery, QList<QVariant> lstParameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	for (int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	query.exec();
	int ID = 0;
	while (query.next())
	{
		ID = query.value(0).toInt();
	}
	return ID;
}
//执行语句返回Int
int SqliteUtil::ExecuteInt(const QString& strQuery, QVariant Parameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	query.exec();
	int ID = 0;
	while (query.next())
	{
		ID = query.value(0).toInt();
	}
	return ID;
}

//执行语句(一个占位符)
bool SqliteUtil::Execute(const QString& strQuery, QVariant Parameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	return query.exec();
}

//执行语句(多个占位符)
bool SqliteUtil::Execute(const QString& strQuery, QList<QVariant> lstParameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	for (int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	return query.exec();
}

//执行语句返回字符串
void SqliteUtil::ExecuteString(const QString& strQuery)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	if (!query.exec()) {
		lastSqlString = strQuery;
		lastErrorText = query.lastError().text();
		qDebug() << "ExecuteString failed!SQL string :" << lastSqlString << endl;
		qDebug() << "Error text:" << lastErrorText << endl;
	}
}

void SqliteUtil::ExecuteQueryModel(QSqlQueryModel* p_queryModel, const QString& strQuery)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	p_queryModel->setQuery(strQuery, m_db);
}

void SqliteUtil::ExecuteQueryModel(QSqlQueryModel* p_queryModel, const QString& strQuery,
	QList<QVariant> lstParameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	for (int i = 0; i < lstParameter.count(); i++)
		query.bindValue(i, lstParameter[i]);
	p_queryModel->setQuery(query);
}

void SqliteUtil::ExecuteQueryModel(QSqlQueryModel* p_queryModel, const QString& strQuery,
	QVariant Parameter)
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query(m_db);
	query.prepare(strQuery);
	query.bindValue(0, Parameter);
	p_queryModel->setQuery(query);
}

/**
 * @brief SqlHelp::createTable 创建表
 * @param tableName 表名称
 * @param fdNameTypePairs 字段名，字段值类型对。比如表字段为 id，name，类型分别为int primary key,varchar
 * 那么 fdNameTypePairs 数组的值依次设置为"id","int primary key","name","varchar"
 */
void SqliteUtil::createTable(QString tableName, QVector<QString> fdNameTypePairs)
{

	//检查表是否已存在
	QVector<QString> existTables = getAllTableName();
	if (existTables.indexOf(tableName) >= 0) {
		return;
	}

	QString createStr = "create table " + tableName;
	QString nameTypeStr;
	if (fdNameTypePairs.count() % 2) {
		qDebug() << "fdNameTypePairs count error" << endl;
		return;
	}
	for (int i = 0; i < fdNameTypePairs.count(); i += 2) {
		nameTypeStr += fdNameTypePairs.at(i) + " " + fdNameTypePairs.at(i + 1) + ",";
	}
	nameTypeStr = nameTypeStr.mid(0, nameTypeStr.length() - 1);//remove last ","
	QString sqlStr = createStr + " (" + nameTypeStr + ")";

	ExecuteString(sqlStr);
}

void SqliteUtil::deleteTable(QString tableName)
{
	QString sqlStr = "drop table " + tableName;

	ExecuteString(sqlStr);
}

//获取数据库中所有的表名
QVector<QString> SqliteUtil::getAllTableName()
{
	/*
		SQLite数据库中一个特殊的表叫 sqlite_master，sqlite_master的结构。
		CREATE TABLE sqlite_master (
		type TEXT,
		name TEXT,
		tbl_name TEXT,
		rootpage INTEGER,
		sql TEXT
		);
		我们可以通过查询这个表来获取数据库所有的表名：
		SELECT name FROM sqlite_master WHERE type='table' ORDER BY name;
		*/
	QVector<QString> result;
	QString sqlStr = "SELECT name FROM sqlite_master WHERE type='table' ORDER BY name";
	if (!m_db.isOpen())
	{
		createConnection();
	}
	QSqlQuery query = ExecuteSqlQuery(sqlStr);

	while (query.next()) {
		result.append(query.value(0).toString());
	}
	return result;
}

/**
 * @brief SqlHelp::addRecord 向表中添加一条记录
 * @param tableName 操作的表名
 * @param fdNameValuePairs 字段名，字段值对。比如添加项为 id=1 name="zhangshan"
 * 那么fdNameValuePairs数组的值依次设置为"id","1","name","'zhangshan'",注意字符串类型的值要加上'
 */
void SqliteUtil::addRecord(QString tableName, QVector<QString> fdNameValuePairs)
{
	//INSERT INTO table_name (列1, 列2,...) VALUES (值1, 值2,....)
	//QString("INSERT INTO %1 ( %2 ) VALUES ( %3 )").arg(tableName).arg(nameStr).arg(valueStr);

	if (fdNameValuePairs.count() % 2) {
		qDebug() << "fdNameTypePairs count error" << endl;
		return;
	}
	QVector<QString> names;
	QVector<QString> values;
	for (int i = 0; i < fdNameValuePairs.count(); i += 2) {
		names.append(fdNameValuePairs.at(i));
		values.append(fdNameValuePairs.at(i + 1));
	}

	QString nameStr;
	QString valueStr;
	//拼接 name
	for (int i = 0; i < names.count(); ++i) {
		nameStr += names.at(i) + ",";
	}
	nameStr = nameStr.mid(0, nameStr.length() - 1);//remove last ","
	//拼接 value
	for (int i = 0; i < values.count(); ++i) {
		valueStr += values.at(i) + ",";
	}
	valueStr = valueStr.mid(0, valueStr.length() - 1);//remove last ","

	QString sqlStr = QString("INSERT INTO %1 ( %2 ) VALUES ( %3 )").arg(tableName).arg(nameStr).arg(valueStr);

	ExecuteString(sqlStr);
}

void SqliteUtil::delRecord(QString tableName, QString condition)
{
	//DELETE FROM 表名称 WHERE 列名称 = 值
	QString sqlStr;
	if (condition.isEmpty()) {
		sqlStr = QString("DELETE FROM %1").arg(tableName);
	}
	else {
		sqlStr = QString("DELETE FROM %1 WHERE %2").arg(tableName).arg(condition);
	}
	ExecuteString(sqlStr);
}

void SqliteUtil::setRecord(QString tableName, QVector<QString> fdNameValuePairs, QString condition)
{
	//参数说明
	//condition为空时，应用到所有列
	//返回值


	//更新某一行中的若干列
	//UPDATE Person SET Address = 'Zhongshan 23', City = 'Nanjing' WHERE LastName = 'Wilson'
	//QString("UPDATE %1 SET %2 WHERE %3").arg(tableName).arg(nameValueStr).arg(condition);
	QString nameValueStr;
	if (fdNameValuePairs.count() % 2) {
		return;
	}
	QVector<QString> names;
	QVector<QString> values;
	for (int i = 0; i < fdNameValuePairs.count(); i += 2) {
		names.append(fdNameValuePairs.at(i));
		values.append(fdNameValuePairs.at(i + 1));
	}
	//拼接 name = value
	for (int i = 0; i < names.count(); ++i) {
		nameValueStr += names.at(i) + " = " + values.at(i) + ",";
	}
	nameValueStr = nameValueStr.mid(0, nameValueStr.length() - 1);//remove last ","

	QString sqlStr;
	if (condition.isEmpty()) {
		sqlStr = QString("UPDATE %1 SET %2 ").arg(tableName).arg(nameValueStr);
	}
	else
	{
		sqlStr = QString("UPDATE %1 SET %2 WHERE %3").arg(tableName).arg(nameValueStr).arg(condition);
	}
	ExecuteString(sqlStr);
}

QVector<QString> SqliteUtil::getFirstRecord(QString tableName, QVector<QString> fdNames, QString condition)
{
	//condition为空时，应用到所有列
	//SELECT LastName,FirstName FROM Persons
	QVector<QString> fdValues;
	QString nameStr = vectorToString(fdNames, ",");
	QString sqlStr;
	if (condition.isEmpty()) {
		sqlStr = QString("SELECT %1 FROM %2 ").arg(nameStr).arg(tableName);
	}
	else {
		sqlStr = QString("SELECT %1 FROM %2 WHERE %3").arg(nameStr).arg(tableName).arg(condition);
	}
	QSqlQuery query = ExecuteSqlQuery(sqlStr);

	if (query.first()) {
		for (int i = 0; i < fdNames.count(); ++i) {
			fdValues.append(query.value(i).toString());
		}
		return fdValues;
	}
	return fdValues;
}

QString SqliteUtil::vectorToString(const QVector<QString>& list, QString split) const
{
	QString result;//转化成val1,val2,val3
	for (int i = 0; i < list.count(); ++i) {
		result += list.at(i) + split;
	}
	int index = result.lastIndexOf(split);
	result.remove(index, split.length());
	return result;
}

QString SqliteUtil::getLastSqlString() const
{
	return lastSqlString;
}

QString SqliteUtil::getLastErrorText() const
{
	return lastErrorText;
}

QSqlDatabase SqliteUtil::getSqlDatabase() const
{
	return m_db;
}

bool SqliteUtil::beginTransaction()
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	return m_db.transaction();
}

bool SqliteUtil::commitTransaction()
{
	if (!m_db.isOpen())
	{
		createConnection();
	}
	return m_db.commit();
}




