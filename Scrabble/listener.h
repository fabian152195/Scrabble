#ifndef LISTENER_H
#define LISTENER_H

#include <QObject>
#include "Client.h"

class Listener : public QObject
{
    Q_OBJECT
public:
    Listener();
public slots:
    void listen();
signals:
    void action();
};

#endif // LISTENER_H
