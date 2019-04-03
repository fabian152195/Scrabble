#include "ficha.h"
#include "QDebug"

Ficha::Ficha(QChar letra, QPoint pos):QRect (pos, QSize(53,33))
{
    this->letra = letra;
    this->pos = pos;
    this->pixmap = QPixmap(":/image/"+QString(letra)+".png");
}

Ficha::Ficha(QString letra, QPoint pos):QRect (pos, QSize(53,33))
{
    this->letra = letra;
    this->pos = pos;
    QString direction = ":/images/"+letra+".png";
    this->pixmap = QPixmap(direction);
    qDebug()<<direction;
}

QPoint Ficha::getPos(){
    return pos;
}

QString Ficha::getLetra(){
    return letra;
}

QPixmap Ficha::getPixmap(){
    return pixmap;
}
