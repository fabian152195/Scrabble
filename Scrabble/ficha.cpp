#include "ficha.h"
#include "QDebug"

Ficha::Ficha(QChar letra, QPoint pos):QRect (pos, QSize(53,33))
{
    this->letra = letra;
    this->pos = pos;
    this->pixmap = QPixmap(":/image/"+QString(letra)+".png");
    joker = false;
}

Ficha::Ficha(QString letra, QPoint pos):QRect (pos, QSize(53,33))
{
    this->letra = letra;
    this->pos = pos;
    if(letra == "_"){
        joker = true;
    }else{
        joker = false;
    }
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

bool Ficha::getJoker(){
    return joker;
}

void Ficha::setJoker(bool joker){
    this->joker = joker;
}
