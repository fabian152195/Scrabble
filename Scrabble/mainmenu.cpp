#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QInputDialog>
#include <iostream>
#include <QMessageBox>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this); 
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_btn_create_clicked()
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
        shortcut = new Game(this);
        shortcut->show();
    }else{
        QMessageBox::warning(this, tr("Error"), tr("Sala llena o inexistente"));
    }

}






