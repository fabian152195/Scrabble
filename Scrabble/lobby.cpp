#include "lobby.h"
#include "ui_lobby.h"

Lobby::Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::on_pushButton_clicked()
{
   hide();
   game = new Game(this);
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
