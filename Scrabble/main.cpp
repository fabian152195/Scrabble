#include "mainmenu.h"
#include <QApplication>
#include "ficha.h"
#include "jsonparser.h"
#include <QtDebug>
#include "fichatosend.h"
#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    Ficha ficha1 = Ficha("A",QPoint(1,1));
    Ficha ficha2 = Ficha("B", QPoint(1,2));
    Ficha fichas[] = {ficha1, ficha2};

    std::cout << JsonParser::toJson(fichas);

    list<FichaToSend> probe = JsonParser::toListFicha("[{letra:\"A\",x:255,y:255},{letra:\"B\",x:1,y:1}]");

    qDebug() << probe.size();
    return a.exec();
}
