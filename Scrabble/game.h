#ifndef GAME_H
#define GAME_H

#include "tablero.h"
#include <QDialog>
#include "listamano.h"

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:

    /**
Tengo que crear las 15x15 casillas en cada lugar correspondiente en el builder
*/
    explicit Game(QWidget *parent = nullptr);
    ~Game(){}
    Ui::Game* getUi();

private slots:
    void on_label_2_clicked();

private:
    Ui::Game *ui;
    ListaMano *mano;
    Tablero *tablero;
};

#endif // GAME_H
