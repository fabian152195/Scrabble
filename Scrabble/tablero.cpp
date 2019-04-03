#include <stdio.h>
#include "tablero.h"
#include <ctype.h>
#include "ficha.h"
#include <QLabel>
#include <QDebug>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include "game.h"
#include <QInputDialog>

list<Ficha> Tablero::toDraw = List();
list<Ficha> Tablero::toErase = List();

Tablero::Tablero(QWidget* parent):QWidget(parent)
{
    setMinimumSize(800,500);
    setMaximumSize(800,500);
    setAcceptDrops(true);
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            disponibles[i][j] = true;
        }
    }
}

void Tablero::dropEvent(QDropEvent *event){
    qDebug()<<"Yey";
    int x,y;
    x = event->pos().x()/53*53.4;
    y = event->pos().y()/33*33.4;

    if(event->mimeData()->hasFormat("image") && disponibles[x/53][y/33]){ 
        qDebug()<<x<<","<<y;
        qDebug()<<x/53<<","<<y/33;
        qDebug()<<"Debug1";
        QString lettre;
        QString joker;
        QByteArray pieceData = event->mimeData()->data("image");
        QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint location;
        dataStream >> pixmap >> location >> lettre >> joker;  //Recibe en el orden en que envia

        if(lettre == '_'){
            lettre = QInputDialog::getText(this,"Joker","Ingrese la letra que desea utilizar");
            while(!(isalpha((int)*lettre.toStdString().c_str()) || lettre == '%' || lettre=='!' || lettre=='$'||lettre=='#')){
                lettre = QInputDialog::getText(this,"Joker","Ingrese una letra");
            }
        }

        Ficha newFicha = Ficha(lettre, QPoint(x,y));
        Game::nuevas.push_back(newFicha, this);
       /* QLabel *label = new QLabel(this);
        label->setPixmap(pixmap);
      //  label->setText("aa");
        label->setGeometry(x, y, 53, 33);
        label->show();
       */ disponibles[x/53][y/33] = false;
    }
    event->accept();

}

void Tablero::dragEnterEvent(QDragEnterEvent *event)  // Se dispara cuando se esta haciendo un drag y se pasa encima del widget
{
    int x,y;
    x = event->pos().x()/53*53.4;
    y = event->pos().y()/33
            *33.4;

    if (event->mimeData()->hasFormat("image") &&disponibles[x/53][y/33])
        event->accept();
    else
        event->ignore();
}

void Tablero::dragLeaveEvent(QDragLeaveEvent *event)
{
        event->accept();
}

void Tablero::dragMoveEvent(QDragMoveEvent *event)  // Se efectua cuando estoy moviendo cosas dentro del widget
{
    int x,y;
    x = event->pos().x()/53*53.4;
    y = event->pos().y()/33*33.4;

    if (event->mimeData()->hasFormat("image") && disponibles[x/53][y/33]){  // El drag trae una pieza y no hay piezas donde tengo el mouse?


                event->accept();


    } else {
        event->ignore();
    }

}

void Tablero::paintEvent(QPaintEvent *event){

    // Hay que pintar el fondo y la cuadricula cada vez que se borra
    QPainter painter;
    painter.begin(this);

    qDebug() << "Painting!";

    for(Ficha ficha:Tablero::toErase){
        painter.eraseRect(ficha);
        Tablero::toDraw.remove(ficha);
        disponibles[ficha.getPos().x()/53][ficha.getPos().y()/33] = true;
    }
    Tablero::toErase.clear();

    painter.drawPixmap(this->pos(), QPixmap(":/images/rsz_1textura-verde-turquesa-1575.jpg"));
    painter.drawPixmap(this->pos(), QPixmap(":/images/grid.png"));

    for(Ficha ficha:Tablero::toDraw){
        QPixmap pix = ficha.getPixmap();
        qDebug() << "Painting "<<pix;
        painter.drawPixmap(ficha, pix);

    }

    painter.end();


}

#include <QObject>
#include <QWidget>
