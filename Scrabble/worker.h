#ifndef WORKER_H
#define WORKER_H
#include <QObject>
#include "Client.h"

class Worker : public QObject
{
    Q_OBJECT
public slots:
    void doWork() {
        QString result;
        std::cout<<"Inicia"<<std::endl;
        /* ... here is the expensive or blocking operation ... */
        Client::readFromServer(Client::buffer);
        std::cout<<"Finaliza";
        emit resultReady(result);
    }

signals:
    void resultReady(const QString &result);
};

#endif // WORKER_H
