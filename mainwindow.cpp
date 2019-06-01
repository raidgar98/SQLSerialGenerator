#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::__intit()
{
	cout << this << "Initializing...";
	__mSQL = new SQLInterpreter(ui->SourcePathDisplay->text(), ui->DestinationPathDisplay->text(), ui->Text1, this);
	if(__mSQL->isOk) loadOnList();
	__setState(true);
}

void MainWindow::__setState(const bool src) noexcept
{
	ui->Button1->setEnabled(src);
	ui->Button2->setEnabled(src);
	ui->Text1->setEnabled(src);
}

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	__setState(false);
	//	a.show();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_Button4_clicked()
{
	//Open Dialog and get path
	QString path = QFileDialog::getOpenFileName(this, "Open list", "/home/raidg", "Text Files (*.txt)");

	//If path is NULL QString return and set path as not setted
	if(path != QString())
	{
		//We changing path, so let's recreate engine again
		if(__mSQL != nullptr)
		{
			__setState(false);
			__mSQL->disconnect();
			delete __mSQL;
			__mSQL = nullptr;
		}

		//Testing is everythink good with this file
		std::ifstream * tempInput = new std::ifstream(path.toStdString());

		//If yes put it on screen
		if(tempInput->good()) ui->SourcePathDisplay->setText(path);
		else
		{
			QMessageBox a(QMessageBox::Icon::Critical, "Błąd Pliku", "Brak Możliwości Otworzenia");
			a.show();
			a.exec();
			return;
		}

		tempInput->close();

		//Securing pointer
		delete tempInput;
		tempInput = nullptr;

		//If everythink is set let's init
		if(ui->SourcePathDisplay->text() != "" && ui->DestinationPathDisplay->text() != "") __intit();

	}else
	{
		ui->SourcePathDisplay->setText("");
		return;
	}
}

void MainWindow::loadOnList()
{
	cout << this << "loadOnList activated";
	ui->List1->clear();
	ui->List1->addItem("'::0' -> [val1, val2 ...]");

	for(int i = 1; i < __mSQL->howManyColumns()+1 ;i++)
		ui->List1->addItem(QString("'::" + QString(i>9 ? "x" : "") + QString::number(i) + "' -> '" + (*__mSQL)["::"+QString(i>9 ? "x" : "")+ QString::number(i)] + "'"));
}

void MainWindow::on_Button5_clicked()
{
	//Open Dialog and get path
	QString path = QFileDialog::getOpenFileName(this, "Open destination", "/home/raidg", "All Files (*.*)");

	//If path is NULL QString return and set path as not setted
	if(path != QString())
	{
		//We changing path, so let's create engine again
		if(__mSQL != nullptr)
		{
			__setState(false);
			__mSQL->disconnect();
			delete __mSQL;
			__mSQL = nullptr;
		}

		//Testing is everythink good with this file
		std::ofstream * tempOutput = new std::ofstream(path.toStdString());

		//If yes put it on screen
		if(tempOutput->good()) ui->DestinationPathDisplay->setText(path);
		else
		{
			QMessageBox a(QMessageBox::Icon::Critical, "Błąd Pliku", "Brak Możliwości Otworzenia");
			a.show();
			a.exec();
			return;
		}

		tempOutput->close();

		//Securing pointer
		delete tempOutput;
		tempOutput = nullptr;

		//If everythink is set let's init
		if(ui->SourcePathDisplay->text() != "" && ui->DestinationPathDisplay->text() != "") __intit();

	}else
	{
		ui->DestinationPathDisplay->setText("");
		return;
	}
}

void MainWindow::on_Button2_clicked()
{
	if(__mSQL == nullptr) return;

	QMessageBox msg(QMessageBox::Icon::Information, "Example Query", __mSQL->example(), QMessageBox::Button::Close);
	msg.show();
	//msg.topLevelWidget();
	msg.exec();
}

void MainWindow::on_List1_itemDoubleClicked(QListWidgetItem *item)
{
	QString temp = item->text();
	temp.resize(4);
	temp.remove(0,1);
	qDebug() << this << " Resize effect: "<<temp;
	ui->Text1->append(temp);
}

void MainWindow::on_Button1_clicked()
{
	if(__mSQL == nullptr) return;

	__mSQL->save();
	a.show();
	a.showMessage("Zakończono", "Pomyślnie Zakończono Generowanie Kodu SQL.", QSystemTrayIcon::Information, 3500);
	a.hide();
	//a.deleteLater();
}


void MainWindow::on_Button3_clicked()
{
	QString msg =

			QString("0) If you want nice place to generate data go to: generatedata.com and after you decide what data you like, select 'Export as CSV' and reformat file like instruction says further\n") +
			QString("\n1) First import *.txt file that is formatted like this:\n\n ")+
			QString("\t;colName1;colName2;colName3;\n")+
			QString("\ta1;a2;a3;\n")+
			QString("\tb1;b2;b3;\n")+
			QString("\t...\n")+
			QString("\tz1;z2;z3;\n")+
			QString("\t!END\n\n")+
			QString("2) Select file to insert result. It will be recreated, so current data on that file will be lost\n")+
			QString("\n3) Now you can write your SQL querry. Wherever you want to insert data from imnported file, write '::x', where x is column number for example:\n\n")+
			QString("\tDELETE FROM 'tableName' WHERE colName='::1'\n\n")+
			QString("Gives result like this:\n\n")+
			QString("\tDELETE FROM 'tableName' WHERE colName='a1'\n\n")+
			QString("If you type '::0' all values will be inserted there in format:\n\n") +
			QString("\t\t'a1', 'a2', a3'\n\n")+
			QString("So it's perfect for INSERT INTO usage for example:\n\n\t 'INSERT INTO 'tableName' VALUES(::0);' \n") +
			QString("\n4) When you press example you will see how it will look like, based on first data line from your file\n") +
			QString("\n5) If you are sure that everythink is correct just click 'Generate' button, and when job is done popup will show\n")+
			QString("\n6) If you want to correct query, just correct it in text box and press again 'Generate' button. File will be overrided\n") +
			QString("\n\nPROTIP: If you doubleclick on item in list box, it will enter propor identifer in the querty");


	QMessageBox a(QMessageBox::Icon::Information, "Help", msg, QMessageBox::StandardButton::Close);
	a.show();
	a.exec();

}
