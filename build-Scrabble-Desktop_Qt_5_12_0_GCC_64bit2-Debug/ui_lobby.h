/********************************************************************************
** Form generated from reading UI file 'lobby.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_H
#define UI_LOBBY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lobby
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *tabla;
    QPushButton *pushButton_2;
    QLabel *player_image;
    QLabel *player_name;
    QLabel *room_number;

    void setupUi(QDialog *Lobby)
    {
        if (Lobby->objectName().isEmpty())
            Lobby->setObjectName(QString::fromUtf8("Lobby"));
        Lobby->resize(800, 600);
        Lobby->setStyleSheet(QString::fromUtf8("#Lobby{background-image: url(:/images/rsz_1textura-verde-turquesa-1575.jpg);}"));
        pushButton = new QPushButton(Lobby);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 350, 80, 25));
        label = new QLabel(Lobby);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 700, 550));
        label->setStyleSheet(QString::fromUtf8("#label{\n"
"background-image: url(:/images/lobby.png);\n"
"}"));
        verticalLayoutWidget = new QWidget(Lobby);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 230, 421, 281));
        tabla = new QVBoxLayout(verticalLayoutWidget);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(Lobby);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(650, 550, 89, 25));
        player_image = new QLabel(Lobby);
        player_image->setObjectName(QString::fromUtf8("player_image"));
        player_image->setGeometry(QRect(570, 170, 100, 100));
        player_name = new QLabel(Lobby);
        player_name->setObjectName(QString::fromUtf8("player_name"));
        player_name->setGeometry(QRect(600, 280, 81, 20));
        room_number = new QLabel(Lobby);
        room_number->setObjectName(QString::fromUtf8("room_number"));
        room_number->setGeometry(QRect(90, 540, 67, 17));
        label->raise();
        pushButton->raise();
        verticalLayoutWidget->raise();
        pushButton_2->raise();
        player_image->raise();
        player_name->raise();
        room_number->raise();

        retranslateUi(Lobby);

        QMetaObject::connectSlotsByName(Lobby);
    } // setupUi

    void retranslateUi(QDialog *Lobby)
    {
        Lobby->setWindowTitle(QApplication::translate("Lobby", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Lobby", "Play", nullptr));
        label->setText(QString());
        pushButton_2->setText(QApplication::translate("Lobby", "Back", nullptr));
        player_image->setText(QString());
        player_name->setText(QApplication::translate("Lobby", "TextLabel", nullptr));
        room_number->setText(QApplication::translate("Lobby", "Numero de sala:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lobby: public Ui_Lobby {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_H
