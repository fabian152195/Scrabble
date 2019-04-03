/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralWidget;
    ClickableLabel *btn_create;
    QLabel *label;
    ClickableLabel *btn_join;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 600);
        MainMenu->setStyleSheet(QString::fromUtf8("#centralWidget{background-image: url(:/images/rsz_1textura-verde-turquesa-1575.jpg);}"));
        centralWidget = new QWidget(MainMenu);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_create = new ClickableLabel(centralWidget);
        btn_create->setObjectName(QString::fromUtf8("btn_create"));
        btn_create->setGeometry(QRect(260, 280, 300, 91));
        btn_create->setMaximumSize(QSize(16777215, 16777215));
        btn_create->setStyleSheet(QString::fromUtf8("background-image: url(:/images/make_button.png);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 50, 600, 150));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/images/scrabble.png);"));
        btn_join = new ClickableLabel(centralWidget);
        btn_join->setObjectName(QString::fromUtf8("btn_join"));
        btn_join->setEnabled(true);
        btn_join->setGeometry(QRect(260, 400, 300, 81));
        btn_join->setMaximumSize(QSize(13223132, 13123213));
        btn_join->setStyleSheet(QString::fromUtf8("background-image: url(:/images/join_button.png);\n"
""));
        MainMenu->setCentralWidget(centralWidget);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "MainMenu", nullptr));
        btn_create->setText(QString());
        label->setText(QString());
        btn_join->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
