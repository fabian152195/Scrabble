#ifndef CASILLA_H
#define CASILLA_H

#include <QWidget>
#include <string>
using namespace std;

namespace Ui {
class Casilla;
}

class Casilla
{

private:
    char letra;
    const double ancho = 53.4;
    const double alto = 33.4;
    int my_x;
    int my_y;
    QString getDirections(char letra);
    QWidget *widget;
    void mousePressEvent(QMouseEvent* event);
signals:
    void clicked();
public:
    explicit Casilla(int x, int y, QWidget *parent);
    void setLetra(char letra);
    char getLetra();
    int getAncho();
    int getAlto();
    int getMy_x();
    int getMy_y();

};

#endif // CASILLA_H
