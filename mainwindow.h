#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sqlinterpreter.h"
#include <QFileDialog>
#include <QListWidgetItem>
#include <QSystemTrayIcon>
#include <QDesktopServices>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	QSystemTrayIcon a{this};

	SQLInterpreter * __mSQL = nullptr;

	void __intit();
	void __setState(const bool) noexcept;

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void loadOnList();

private slots:

	void on_Button4_clicked();

	void on_Button5_clicked();

	void on_Button2_clicked();

	void on_List1_itemDoubleClicked(QListWidgetItem *item);

	void on_Button1_clicked();


	void on_Button3_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
