#include <string>
#include <QPushButton>
#include <QMessageBox>
#include "game.h"
#include "ui_game.h"
#include <QDebug>

Game::Game(QWidget *parent):QDialog(parent), ui(new Ui::Game){
    ui->setupUi(this);

    /* Setup: puesta en punto con el server
     * Paseme mi jugador, sus puntos y la cantidad de fichas que hay
*/
    update();

    // Mano
    mano = new ListaMano(this);
    mano->setGeometry(250,530,321,50);
    mano->addFicha(QPixmap(":/images/B.png"), QPoint(0,0), QChar('A'));

    //Tablero
   tablero = new Tablero(this);
   tablero->setGeometry(0,0,800,500);



}


void Game::update(){
    //Server shit
    remaining = 100;
    player_points = 10;
    player_name = "Ronaldo";
    ui->player_points->setText(QString(std::to_string(player_points).c_str()));
    ui->player_name->setText(player_name);
    ui->remaining->setText(QString(std::to_string(remaining).c_str()));

    //Tambien deberia actualizarse la mano
}

void Game::on_label_2_clicked(){
   bool validation = sendServer();
   if(validation){
       QMessageBox *success = new QMessageBox(this);
       success->setText("Su palabra ha sido confirmada!");
       qDebug() << "Add Puntos";
       success->show();
   }else{
       int question = QMessageBox::critical(this, "Palabra invalida", "La palabra que ingreso no esta registrada "
                                                       "¿desea validarla con un experto?"
                             , QMessageBox::Retry, QMessageBox::Abort);
       if(question == 524288){
           if(sendServer("palabraaca")){
               qDebug() << "Add puntos";
               clearNuevas();
           }else{
               //Rechazo

           }
       }else{
           //rechazo
       }
       // 262144: Abort, 524288: Retry
   }
}

void Game::returnNuevas(){
    for(Ficha i:nuevas){
        mano->addFicha(i.getPos(),i.getLetra());
        // Borrar del tablero
    }
}

// BIG PROBLEM
void Game::addNuevas(Ficha item){
   nuevas.push_back(item);
   int arr[15][15];
   *(*(arr+1)+1) = 1;
   *(*(Game::getDisponibles()+item.getPos().x()/53)+item.getPos().y()/33) = false;
}

bool *Game::getDisponibles(){
    return *disponibles;
}

void Game::clearNuevas(){
    nuevas.clear();
}

void Game::undoNuevas(){
    nuevas.pop_back();
}

bool Game::sendServer(){
    // enviar las lista de nuevas
    return false;
}

bool Game::sendServer(QString word){
   // Enviar al experto
    return true;
}

/**
  Es mejor pintar la imagen de las fichas en el tablero que agregar
  Label, porque en el momento de borrar es mas facil hacerlo con pinturas
  que con Labels
*/

/**
Plan:
    Paso al server las nuevas letras agregadas
    - Hago un array con las nuevas letras
    - Cada vez que agrego o quito una letra al tablero
      la agrego o la quito del array nuevas letras
    - Limpiar el array cada vez que recibo respuesta del server
*/
