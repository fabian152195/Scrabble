#include "mainmenu.h"
#include <QApplication>
#include "ficha.h"
#include "jsonparser.h"
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    Ficha ficha1 = Ficha("A",QPoint(1,1));
    Ficha ficha2 = Ficha("B", QPoint(1,2));
    Ficha fichas[] = {ficha1, ficha2};
    std::cout << JsonParser::toJson(fichas);
    return a.exec();
}
