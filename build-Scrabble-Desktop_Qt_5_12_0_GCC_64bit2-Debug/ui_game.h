/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QLabel *label;
    ClickableLabel *label_2;
    QLabel *player_image;
    QLabel *player_name;
    QLabel *player_points;
    QLabel *remaining;
    QLabel *hand_grid;

    void setupUi(QDialog *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(800, 600);
        Game->setStyleSheet(QString::fromUtf8("QDialog{ background-image: url(:/images/rsz_1textura-verde-turquesa-1575.jpg);}"));
        label = new QLabel(Game);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 800, 500));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/grid.png")));
        label_2 = new ClickableLabel(Game);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(610, 500, 181, 101));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/images/scrabble_button.png);\n"
""));
        player_image = new QLabel(Game);
        player_image->setObjectName(QString::fromUtf8("player_image"));
        player_image->setGeometry(QRect(10, 510, 70, 50));
        player_name = new QLabel(Game);
        player_name->setObjectName(QString::fromUtf8("player_name"));
        player_name->setGeometry(QRect(10, 570, 71, 31));
        player_points = new QLabel(Game);
        player_points->setObjectName(QString::fromUtf8("player_points"));
        player_points->setGeometry(QRect(110, 530, 67, 16));
        remaining = new QLabel(Game);
        remaining->setObjectName(QString::fromUtf8("remaining"));
        remaining->setGeometry(QRect(110, 570, 67, 17));
        hand_grid = new QLabel(Game);
        hand_grid->setObjectName(QString::fromUtf8("hand_grid"));
        hand_grid->setGeometry(QRect(250, 530, 321, 34));
        hand_grid->setStyleSheet(QString::fromUtf8("#hand_grid{\n"
"     background-image: url(:/images/hand_grid.png);\n"
"}"));
        hand_grid->raise();
        label->raise();
        label_2->raise();
        player_image->raise();
        player_name->raise();
        player_points->raise();
        remaining->raise();

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QDialog *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        player_image->setText(QApplication::translate("Game", "Imagen", nullptr));
        player_name->setText(QApplication::translate("Game", "Nombre", nullptr));
        player_points->setText(QApplication::translate("Game", "Puntos", nullptr));
        remaining->setText(QApplication::translate("Game", "remaining", nullptr));
        hand_grid->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
