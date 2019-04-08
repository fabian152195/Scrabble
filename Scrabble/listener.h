#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include "Client.h"
#include "ficha.h"
#include "jsonparser.h"
#include <list>

using namespace  std;
class Listener : public QObject
{
    Q_OBJECT
public:
    Listener();
public slots:
    void listen();
signals:
    void action();
    void addFichas(list<Ficha> fichas);
    void modTurn(bool turn);
    void confirmacionPalabra(bool valid);
    void addPuntaje(int puntos);
    void updateM(list<Ficha> fichas);

};

#endif // LISTENER_H
