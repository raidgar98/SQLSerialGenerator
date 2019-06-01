#ifndef SQLINTERPRETER_H
#define SQLINTERPRETER_H

#include <fstream>
#include <string>
#include <QTextEdit>
#include <QMessageBox>
#include <QMap>
#include <QMainWindow>

#include <QDebug>

#define cout qDebug()

//class MainWindow : public QMainWindow {};

class SQLInterpreter final : public QObject
{
	Q_OBJECT

private:

	QString			__mInputPath		{""};
	QString			__mOutputPath		{""};
	QTextEdit	  *	__mSrc				{nullptr};

	QMap<QString, QString> __mSymbols;
	void __compile(const char separator, std::list<QString>& paramList, QString& query, const std::string & buff) const noexcept;

public:

	SQLInterpreter() = delete;
	SQLInterpreter(const SQLInterpreter&) = delete;
	SQLInterpreter(SQLInterpreter&&) = delete;
	~SQLInterpreter();

	void operator delete(void *);

	SQLInterpreter(const QString& , const QString& , QTextEdit * , QObject * = nullptr) noexcept;

	bool save();
	QString example();
	size_t howManyColumns() const;
	QString operator[](const QString) const;

	bool isOk = false;
};

#endif // SQLINTERPRETER_H
