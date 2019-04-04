#include "Client.h"
#include <QThread>
#include "lobby.h"
#include <QInputDialog>
#include "ui_lobby.h"
#include <QtDebug>
#include <QHBoxLayout>
#include <thread>
#include <cstring>
#include "worker.h"




Lobby::Lobby(bool newLobby,int room_number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    c_players = 1;
    //ui->room_number->setNum(room_number);
    my_name = QInputDialog::getText(this,"Nombre","Ingrese su nombre a continuacion");
    if(newLobby){
        addPlayer(my_name);
        Client::sendToServer("room_c");
        Client::readFromServer(Client::buffer);
        Client::sendToServer(my_name.toStdString().c_str());
        char room_number[50];
        Client::readFromServer(room_number);
        ui->room_number->setText(room_number);
    }else{
        Client::sendToServer(my_name.toStdString().c_str());  // envio nombre 
    }
    QImage default_user = QImage(":/images/default_user.png");
    QImage def_user = default_user.scaled(100,100,Qt::KeepAspectRatio);
    ui->player_image->setPixmap(QPixmap::fromImage(def_user));
    my_image = def_user;
    players = list<QHBoxLayout*>();
    ui->player_name->setText(my_name);
    //Client::readFromServer(Client::buffer);
    //std::thread t1(&Lobby::reposoLobby, this);
    QThread *workerThread = new QThread();
    Worker *worker = new Worker();
    worker->moveToThread(workerThread);
    connect(workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Lobby::operate, worker,&Worker::doWork);
    connect(worker, &Worker::resultReady, this, &Lobby::on_pushButton_clicked);
    workerThread->start();
    emit operate();
}

void Lobby::juego(){
    /*
    Client::readFromServer(Client::buffer);
    cout<<"Empieza!"<<endl<<flush;
    on_pushButton_clicked();*/
}

Lobby::~Lobby()
{
    delete ui;
    delete game;
}

void Lobby::on_pushButton_clicked()
{
   hide();
   game = new Game(my_name,my_image,this);
   game->show();
}


/**
Memento: Cada vez que voy a agregar un nuevo jugador,
agregar un horizontal layout al layout 'tabla'
donde el miembro derecho es el nombre del jugador
y el izquierdo es el numero o turno
*/

void Lobby::on_pushButton_2_clicked()
{
    parentWidget()->show();
    close();
}

void Lobby::addPlayer(QString name){
    QHBoxLayout *player_container = new QHBoxLayout();
    ui->tabla->addLayout(player_container);
    //player_container->setGeometry(ui->);
    //player_container
    players.push_back(player_container);
    QLabel *Lname = new QLabel(this);
    QLabel *Lnumber = new QLabel(this);
    Lname->setText(name);
    Lnumber->setNum(c_players++);
    Lname->setAlignment(Qt::AlignCenter);
    Lnumber->setAlignment(Qt::AlignCenter);
    player_container->addWidget(Lname);
    player_container->addWidget(Lnumber);
}


void Lobby::removePlayer(QString number){
    clearLayout(players.back());
    ui->tabla->removeItem(players.back());
}

void Lobby::clearLayout(QLayout *layout){
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}

/**


**/
