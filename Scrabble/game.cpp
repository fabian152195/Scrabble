#include "game.h"
#include "casilla.h"
#include "ui_game.h"

Game::Game(QWidget *parent):QDialog(parent), ui(new Ui::Game){
    ui->setupUi(this);
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            casilla_juego[i][j] = new Casilla(i*53.4,j*33.4,this);
        }
    }
    for(int i=0;i<7;i++){
        casilla_mano[i] = new Casilla(ui->hand_grid->x()+i*53.4,
                                      ui->hand_grid->y(), this);
    }

    // Pruebas
    casilla_mano[0]->setLetra('A');
    casilla_mano[6]->setLetra('A');
    casilla_mano[5]->setLetra('A');
    casilla_mano[4]->setLetra('A');
    casilla_mano[3]->setLetra('A');
    casilla_mano[2]->setLetra('A');
    casilla_mano[1]->setLetra('A');
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
*/
