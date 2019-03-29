#ifndef FICHA_H
#define FICHA_H
#include <QRect>
#include <QPoint>

class Ficha : public QRect
{
public:
    Ficha(char letra, QPoint pos);
    char getLetra();
    QPoint getPos();
private:
    char letra;
    QPoint pos;
};

#endif // FICHA_H

/**
  Hacer que ficha herede de rectangulo, la idea es que la lista nuevas
  de Game sea mi referencia para pintar, cada vez que agrego una ficha
  a esta lista, pinto, cada vez que borro una ficha de la lista, borro
  lo pintado y asi.
*/
