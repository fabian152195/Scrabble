#ifndef GAME_H
#define GAME_H

#include "tablero.h"
#include <QDialog>
#include "listamano.h"
#include "ficha.h"
#include "list.h"
#include <QThread>
#include "listener.h"

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
    explicit Game(QString name,QImage my_image,QWidget *parent = nullptr);
    ~Game();
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
    void addFichas(list<Ficha> fichas);
    void modTurn(bool turn);
    void confirmacionPalabra(bool valid);
    void addPuntaje(int puntos);
    void updateM(list<Ficha> fichas);
    void addFichasB(list<Ficha> fichas);
    void on_Pasar_clicked();
    void firstBad();
    void correcta();
    void repeat();
    void final();
signals:
    void startListen();

private:
    Tablero *tablero; /** Widget del tablero donde se van a poner las fichas*/
    Ui::Game *ui;
    bool *my_turn = new bool;
    QString player_name;
    int player_points;
    int remaining;
    void update();
    ListaMano *mano;  /** Lista encargada de manejar las fichas de la mano del jugador*/

    bool sendServer(); /** Funcion que envia al server */
    bool sendServer(QString word);
    QThread *listen;
};


#endif // GAME_H
