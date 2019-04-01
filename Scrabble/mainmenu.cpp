#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QInputDialog>
#include <iostream>
#include <QMessageBox>

Collector MainMenu::collector = Collector();

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this); 
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
        }







void MainMenu::on_btn_join_clicked()
{
    //hide();
    QInputDialog *inputD = new QInputDialog();
    int room_code = QInputDialog::getInt(this,"Hey","ha");
    /**
    Ahora toca enviar room_code a server para que lo evalue
    */
    bool codigo_correcto = true; //Proximamente esto sera respuesta del server
    if(codigo_correcto){
        hide();
        //shortcut = new Game(this);
        //shortcut->show();
        lobby = new Lobby(false,room_code,
                          this);
        lobby->show();

    }else{
        QMessageBox::warning(this, tr("Error"), tr("Sala llena o inexistente"));
    }
}
