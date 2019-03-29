#include "tablero.h"
#include <QLabel>
#include <QDebug>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include "game.h"
#include <QInputDialog>

Tablero::Tablero(QWidget* parent):QWidget(parent)
{
    setMinimumSize(800,500);
    setMaximumSize(800,500);
    setAcceptDrops(true);
}

void Tablero::dropEvent(QDropEvent *event){
    qDebug()<<"Yey";
    int x,y;
    x = event->pos().x()/53*53;
    y = event->pos().y()/33*33;

    if(event->mimeData()->hasFormat("image") && Game::disponibles[x/53][y/33]){
        qDebug()<<"Debug1";
        QString lettre, joker;
        QByteArray pieceData = event->mimeData()->data("image");
        QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint location;
        dataStream >> pixmap >> location >> lettre >> joker;  //Recibe en el orden en que envia
        QLabel *label = new QLabel(this);
        label->setPixmap(pixmap);
      //  label->setText("aa");
        label->setGeometry(x, y, 53, 33);
        label->show();
    }
    event->accept();

}

void Tablero::dragEnterEvent(QDragEnterEvent *event)  // Se dispara cuando se esta haciendo un drag y se pasa encima del widget
{
    int x,y;
    x = event->pos().x()/53*53;
    y = event->pos().y()/33*33;

    if (event->mimeData()->hasFormat("image") && Game::disponibles[x/53][y/33])
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
    x = event->pos().x()/53*53;
    y = event->pos().y()/33*33;

    if (event->mimeData()->hasFormat("image") && Game::disponibles[x/53][y/33] ){  // El drag trae una pieza y no hay piezas donde tengo el mouse?


                event->accept();


    } else {
        event->ignore();
    }

}

#include <QObject>
#include <QWidget>
