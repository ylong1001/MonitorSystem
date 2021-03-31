/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Mar 31 17:08:01 2021
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *Label_showDateTime;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#MainWindow {\n"
"	border:2px groove blue;\n"
"	border-radius:10px;\n"
"}\n"
"\n"
"QToolButton {\n"
"	border:0;\n"
"}\n"
"\n"
"QToolButton#closeBtn {\n"
"	background-image: url(:/images/close.png);\n"
"}\n"
"\n"
"QToolButton#closeBtn:hover {\n"
"	background-image: url(:/images/close_h.png);\n"
"}\n"
"QToolButton#closeBtn:pressed {\n"
"	background-image: url(:/images/close_p.png);\n"
"}\n"
"\n"
"QToolButton#minBtn {\n"
"	background-image: url(:/images/min.png);\n"
"}\n"
"\n"
"QToolButton#minBtn:hover {\n"
"	background-image: url(:/images/min_h.png);\n"
"}\n"
"QToolButton#minBtn:pressed {\n"
"	background-image: url(:/images/min_p.png);\n"
"}\n"
"\n"
"QLabel {\n"
"	color:gray;\n"
"	font:12pt;\n"
"}\n"
"\n"
"QToolBox  {\n"
"    padding: 5px;\n"
"    border: 10px transparent black;\n"
"	min-height:30px; \n"
"}\n"
"\n"
"QToolBox::tab {\n"
"    color:white;\n"
"font:10pt;\n"
"	background-color: rgb(0, 0, 255);\n"
"    border: 1px solid #76797C;\n"
"    border-bottom: 1px transparent #31363b;\n"
"}\n"
"\n"
"QTo"
                        "olBox::tab:selected { /* italicize selected tabs */\n"
"    font: italic;\n"
"   	\n"
"	background-color: rgb(0, 0, 255);\n"
"    border-color: #3daee9;\n"
" }\n"
"\n"
"\n"
"\n"
"QToolButton::menu-button {\n"
"         border: 2px solid gray;\n"
"        border-top-right-radius: 6px;\n"
"         border-bottom-right-radius: 6px;\n"
"         width: 16px;\n"
"}\n"
"QToolButton::menu-arrow:open {\n"
"         top: 1px; left: 1px; /* shift it a bit */\n"
"}\n"
"QTableView {\n"
"	selection-background-color:rgb(131,168,238)\n"
"}\n"
"QLineEdit {\n"
"	color:rgb(127,0,63);\n"
"	border:2px groove gray;\n"
"	border-radius:6px;\n"
"	selection-color: white;\n"
"    selection-background-color: rgb(191, 31, 127);\n"
"}\n"
"QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"	min-height:20px;\n"
"	min-width:50px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
""
                        "	background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"	\n"
"border-style: inset;\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Label_showDateTime = new QLabel(centralWidget);
        Label_showDateTime->setObjectName(QString::fromUtf8("Label_showDateTime"));
        Label_showDateTime->setGeometry(QRect(640, 670, 361, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Label_showDateTime->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
