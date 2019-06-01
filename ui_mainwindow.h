/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Button4;
    QLineEdit *SourcePathDisplay;
    QLineEdit *DestinationPathDisplay;
    QPushButton *Button5;
    QTextEdit *Text1;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QListWidget *List1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(608, 267);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Button4 = new QPushButton(centralWidget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setGeometry(QRect(350, 170, 40, 22));
        SourcePathDisplay = new QLineEdit(centralWidget);
        SourcePathDisplay->setObjectName(QString::fromUtf8("SourcePathDisplay"));
        SourcePathDisplay->setGeometry(QRect(20, 170, 320, 22));
        SourcePathDisplay->setToolTipDuration(10);
        SourcePathDisplay->setReadOnly(true);
        DestinationPathDisplay = new QLineEdit(centralWidget);
        DestinationPathDisplay->setObjectName(QString::fromUtf8("DestinationPathDisplay"));
        DestinationPathDisplay->setGeometry(QRect(20, 200, 320, 22));
        DestinationPathDisplay->setToolTipDuration(10);
        DestinationPathDisplay->setReadOnly(true);
        Button5 = new QPushButton(centralWidget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setGeometry(QRect(350, 200, 40, 22));
        Text1 = new QTextEdit(centralWidget);
        Text1->setObjectName(QString::fromUtf8("Text1"));
        Text1->setGeometry(QRect(20, 10, 371, 151));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 230, 289, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Button1 = new QPushButton(layoutWidget);
        Button1->setObjectName(QString::fromUtf8("Button1"));

        horizontalLayout->addWidget(Button1);

        Button2 = new QPushButton(layoutWidget);
        Button2->setObjectName(QString::fromUtf8("Button2"));

        horizontalLayout->addWidget(Button2);

        Button3 = new QPushButton(layoutWidget);
        Button3->setObjectName(QString::fromUtf8("Button3"));

        horizontalLayout->addWidget(Button3);

        List1 = new QListWidget(centralWidget);
        List1->setObjectName(QString::fromUtf8("List1"));
        List1->setGeometry(QRect(400, 10, 201, 251));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SQL Serial Query Generator", nullptr));
        Button4->setText(QApplication::translate("MainWindow", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        SourcePathDisplay->setToolTip(QApplication::translate("MainWindow", "\"Source File\"", nullptr));
#endif // QT_NO_TOOLTIP
        SourcePathDisplay->setText(QString());
#ifndef QT_NO_TOOLTIP
        DestinationPathDisplay->setToolTip(QApplication::translate("MainWindow", "Destination File (will be recreated)", nullptr));
#endif // QT_NO_TOOLTIP
        DestinationPathDisplay->setText(QString());
        Button5->setText(QApplication::translate("MainWindow", "...", nullptr));
        Button1->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        Button2->setText(QApplication::translate("MainWindow", "Show example", nullptr));
        Button3->setText(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
