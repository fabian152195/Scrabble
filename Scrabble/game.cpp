#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent):QDialog(parent), ui(new Ui::Game){
    ui->setupUi(this);

    // Mano
    mano = new ListaMano(this);
    mano->setGeometry(250,530,321,50);
    mano->addFicha(QPixmap(":/images/B.png"), QPoint(0,0), QChar('A'));

    //Tablero
   tablero = new Tablero(this);
   tablero->setGeometry(0,0,800,500);
}

void Game::on_label_2_clicked(){
}




/**
Plan:
    Paso al server las nuevas letras agregadas
    - Hago un array con las nuevas letras
    - Cada vez que agrego o quito una letra al tablero
      la agrego o la quito del array nuevas letras
    - Si hay un error devolver solo las letras de dicho array
      a la mano
    - Limpiar el array cada vez que recibo respuesta del server

    Es mejor, antes de hacer todas las otras tareas, terminar la relativa al drag:

    - Entender bien bien bien signals y slots
    - Entender el ejemplo a la perfeccion
    - Implementarlo
*/
