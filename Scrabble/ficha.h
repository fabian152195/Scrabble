#ifndef FICHA_H
#define FICHA_H
#include <QRect>
#include <QPoint>
#include <QPixmap>

class Ficha : public QRect
{
public:
    Ficha(){}
    Ficha(QChar letra, QPoint pos);
    Ficha(QString letra, QPoint pos);
    QString getLetra();
    QPoint getPos();
    Ficha *getNext();
    QPixmap getPixmap();
    bool joker;
    bool getJoker();
    void setJoker(bool joker);
private:
    QString letra;
    QPoint pos;
    QPixmap pixmap;
};

#endif // FICHA_H

/**
  Hacer que ficha herede de rectangulo, la idea es que la lista nuevas
  de Game sea mi referencia para pintar, cada vez que agrego una ficha
  a esta lista, pinto, cada vez que borro una ficha de la lista, borro
  lo pintado y asi.
*/
