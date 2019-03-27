#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "casilla.h"

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
    Casilla *casilla_juego[15][15];
    Casilla *casilla_mano[7];
    explicit Game(QWidget *parent = nullptr); 
    ~Game(){};
    Ui::Game* getUi();

private slots:
    void on_label_2_clicked();

private:
    Ui::Game *ui;

};

#endif // GAME_H
