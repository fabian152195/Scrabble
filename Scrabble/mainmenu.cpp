#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QInputDialog>
#include <iostream>
#include <QMessageBox>
#include "Client.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>

Collector MainMenu::collector = Collector();

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this); 
    Client();
}

MainMenu::~MainMenu()
{
    delete ui;
    delete lobby;
    delete shortcut;
}

void MainMenu::on_btn_create_clicked()
{ 
    // Le digo al servidor que hay un nuevo lobby y le pido el numero de sala
        hide();
        //shortcut = new Game(this);
        //shortcut->show();
        lobby = new Lobby(true,0, this);
        lobby->show();
        lobby->update();
      //  lobby->juego();
}


void MainMenu::on_btn_join_clicked()
{
    //hide();
    int room_code = QInputDialog::getInt(this,"Codigo de sala","Introduzca el codigo de la sal a la que quiere unirse");
    /**
    Ahora toca enviar room_code a server para que lo evalue
    */
    Client::sendToServer("room_j");  //  Envio peticion de join
    Client::readFromServer(Client::buffer); // Confirmacion
    Client::sendToServer(std::to_string(room_code).c_str());
    Client::readFromServer(Client::buffer); // Obtiene aprobacion o denegacion

    string codigo_correcto = Client::buffer; //Proximamente esto sera respuesta del server
    if(strncmp(codigo_correcto.c_str(),"approved",9)==0){  // Si hay aprobacion
        hide();
        //shortcut = new Game(this);
        //shortcut->show();
        lobby = new Lobby(false,room_code,
                          this);
        lobby->show();
       // lobby->juego();

    }else{
        QMessageBox::warning(this, tr("Error"), tr("Sala llena o inexistente"));
    }
}
