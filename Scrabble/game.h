#ifndef GAME_H
#define GAME_H

#include "tablero.h"
#include <QDialog>
#include "listamano.h"
#include "ficha.h"
#include "list.h"

using namespace std;

namespace Ui {
class Game;
}



class Game : public QDialog
{
    Q_OBJECT

public:
    /**
     * Tengo que crear las 15x15 casillas en cada lugar correspondiente en el builder
    */
    explicit Game(QWidget *parent = nullptr);
    ~Game(){}
    Ui::Game* getUi();
    /**
      Agrega fichas a la lista Nuevas
      @param item Ficha a agregar
*/
    void addNuevas(Ficha item);
    /**
      Limpia la lista de fichas nuevas
*/
    void clearNuevas();
    /**
      Quita la ultima ficha agregada a la lista de Nuevas
*/
    void undoNuevas();

    /**
      Devuelve todo el array de nuevas a la mano
*/
    void returnNuevas(); 
    static List nuevas; /** Lista que maneja las fichas agregadas en el turno presente */

private slots:
    void on_label_2_clicked();

private:
    Tablero *tablero; /** Widget del tablero donde se van a poner las fichas*/
    Ui::Game *ui;
    QString player_name;
    int player_points;
    int remaining;
    void update();
    ListaMano *mano;  /** Lista encargada de manejar las fichas de la mano del jugador*/

    bool sendServer(); /** Funcion que envia al server */
    bool sendServer(QString word);
};


#endif // GAME_H
