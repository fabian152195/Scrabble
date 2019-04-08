#include <string>
#include <QPushButton>
#include <QMessageBox>
#include "game.h"
#include "ui_game.h"
#include <QDebug>

List Game::nuevas = List();

Game::Game(QString name,QImage my_image,QWidget *parent):QDialog(parent), ui(new Ui::Game){
    ui->setupUi(this);
    *my_turn = false;
    /* Setup: puesta en punto con el server
     * Paseme mi jugador, sus puntos y la cantidad de fichas que hay
*/
    // Conectar slots y signals
    listen = new QThread();
    Listener *listener = new Listener();
    listener->moveToThread(listen);  // Se mueve al nuevo hilo
    connect(listen, &QThread::finished, listener, &QObject::deleteLater);  // Borra listener cuanod termina hilo
    connect(this, &Game::startListen, listener, &Listener::listen); // linkea la sennal con la que inicia el escucha
    // De aqui en mas se conectan las sennales de listener con los slots de game
    // para realizar acciones

    // Para pasar parametros los signals y slots correspondientes tienen que tener
    // el mismo tipo y cantidad de parametros
    connect(listener, &Listener::addFichas, this, &Game::addFichas);
    connect(listener, &Listener::modTurn, this, &Game::modTurn);
    connect(listener, &Listener::addPuntaje, this, &Game::addPuntaje);
    connect(listener, &Listener::confirmacionPalabra, this, &Game::confirmacionPalabra);
    connect(listener, &Listener::updateM, this, &Game::updateM);
    connect(listener, &Listener::addFichasB, this, &Game::addFichasB);
    connect(listener, &Listener::firstBad, this, &Game::firstBad);
    connect(listener, &Listener::correcta, this, &Game::correcta);
    connect(listener, &Listener::repeat, this, &Game::repeat);

    listen->start();  //Inicia el hilo
    emit startListen();

    update();

    ui->player_name->setText(name);
    ui->player_image->setPixmap(QPixmap::fromImage(my_image.scaled(70,50)));

    // Mano
    mano = new ListaMano(this);
    mano->setGeometry(200,520,431,50);

    //Tablero
    tablero = new Tablero(my_turn, this);
    tablero->setGeometry(0,0,800,500);
}

Game::~Game(){
    delete ui;
    delete tablero;
    delete mano;
}

void Game::firstBad(){
    // 262144 : Abort
    // 1024: Accept
    int question = QMessageBox::critical(this, "Palabra invalida", "La palabra que ingreso no esta registrada "
                                                       "¿desea validarla con un experto?"
                             , QMessageBox::Ok, QMessageBox::Abort);
    cout<<question<<flush<<endl;
    Client::sendToServer(to_string(question).c_str());

}

void Game::modTurn(bool turn){
    cout<<"Changing turn"<<flush<<endl;
    *my_turn = turn;
}

void Game::addFichasB(list<Ficha> fichas){
    mano->clear();
    this->addFichas(fichas);
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

void Game::addFichas(list<Ficha> fichas){
    for(Ficha ficha:fichas){
        mano->addFicha(ficha.getPixmap(),ficha.getPos(),ficha.getLetra());
    }
    tablero->update();
}

void Game::on_label_2_clicked(){
    const int tmp = nuevas.size();
    Ficha nuevas_arr[tmp];
    int i=0;
    for(Ficha ficha:nuevas){
        nuevas_arr[i] = ficha;
        i++;
    }
    string message = JsonParser::toJson(nuevas_arr, tmp);
    Client::sendToServer(message.c_str());

    // De aqui a abajo en un slot
}

void Game::addPuntaje(int puntaje){
    int points = ui->player_points->text().toInt()+puntaje;
    ui->player_points->setNum(points);
}

void Game::updateM(list<Ficha> fichas){
    for(Ficha ficha:fichas){
        Tablero::toDraw.push_back(ficha);
    }
    tablero->update();
}

void Game::correcta(){
    QMessageBox *success = new QMessageBox(this);
    success->setText("Su palabra ha sido aceptada!");
    success->show();
}

void Game::repeat(){
    //rechazo
           for(Ficha ficha:nuevas){
               if(ficha.getJoker()){
                   mano->addFicha(QPoint(0,0),"_");
               }else{
                   mano->addFicha(QPoint(0,0), ficha.getLetra());
               }
           }
           nuevas.clear(tablero);

}

void Game::confirmacionPalabra(bool valid){
   bool validation = valid;
   if(validation){
       QMessageBox *success = new QMessageBox(this);
       success->setText("Su palabra ha sido confirmada!");
       qDebug() << "Add Puntos";
       success->show();
   }else{
       int question = QMessageBox::critical(this, "Palabra invalida", "La palabra que ingreso no esta registrada "
                                                       "¿desea validarla con un experto?"
                             , QMessageBox::Ok, QMessageBox::Abort);
       if(question == 524288){
           if(sendServer("palabraaca")){
               qDebug() << "Add puntos";
               clearNuevas();
           }else{
               //Rechazo
               nuevas.clear(tablero);
               for(Ficha ficha:nuevas){
                   if(ficha.getJoker()){
                       mano->addFicha(QPoint(0,0), "_");
                   }else{

                   mano->addFicha(QPoint(0,0),ficha.getLetra());
                   }
               }
           }
       }else{
           //rechazo
           for(Ficha ficha:nuevas){
               if(ficha.getJoker()){
                   mano->addFicha(QPoint(0,0),"_");
               }else{
                   mano->addFicha(QPoint(0,0), ficha.getLetra());
               }
           nuevas.clear(tablero);
       }
       // 262144: Abort, 524288: Retry
   }
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
   Game::nuevas.push_back(item, tablero);
}

void Game::clearNuevas(){
    Game::nuevas.clear(tablero);
}

void Game::undoNuevas(){
    Game::nuevas.pop_back(tablero);
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

void Game::on_Pasar_clicked()
{

    Client::sendToServer(".");

}
