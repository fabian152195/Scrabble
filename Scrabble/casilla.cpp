#include "casilla.h"
#include <QWidget>
#include <iostream>
#include <string>

using namespace std;

Casilla::Casilla(int x, int y, QWidget *padre)
{
    my_x = x;
    my_y = y;
    letra = '.';
    widget = new QWidget(padre);
    widget->setGeometry(x,y,53,33);
    //QWidget *prueba = new QWidget(padre);
    //prueba->setGeometry(my_x, my_y, 55,33);
    //prueba->setStyleSheet("background-image:url("+getDirections('A')+")");
}

void Casilla::setLetra(char letra){
    this->letra = letra;
    widget->setGeometry(this->my_x, this->my_y, this->ancho, this->alto);
    if(letra != '.'){  // En caso de que sea un punto, o sea este vacia, no agregar nada
        QString direction = "background-image:url(" + getDirections(letra) + ")";
        widget->setStyleSheet(direction);
    }
}

int Casilla::getAncho(){
    return ancho;
}

int Casilla::getAlto(){
    return alto;
}

char Casilla::getLetra(){
    return letra;
}

QString Casilla::getDirections(char letra){
    QString result;
        switch (letra) {
            case 'A':
                result =  ":/images/A.png";
                break;
            case 'B':
                result = ":/images/B.png)";
                break;
            case 'C':
                result = ":/images/C.png)";
            break;
            case 'D':
                result = ":/images/D.png)";
            break;
            case 'E':
                result = ":/images/E.png)";
            break;
            case 'F':
                result = ":/images/F.png";
            break;
            case 'G':
                result = ":/images/G.png";
            break;
            case 'H':
                result = ":/images/H.png";
            break;
            case 'J':
                result = ":/images/J.png";
            break;
            case 'K':
                result = ":/images/K.png";
            break;
            case 'L':
                result = ":/images/L.png";
            break;
            case 'M':
                result = ":/images/M.png";
            break;
            case 'N':
                result = ":/images/N.png";
            break;
            case 'O':
                result = ":/images/O.png";
            break;
            case 'P':
                result = ":/images/P.png";
            break;
            case 'Q':
                result = ":/images/Q.png";
            break;
            case 'R':
                result = ":/images/R.png";
            break;
            case 'S':
                result = ":/images/S.png";
            break;
            case 'T':
                result = ":/images/T.png";
            break;
            case 'U':
                result = ":/images/U.png";
            break;
            case 'V':
                result = ":/images/V.png";
            break;
            case 'W':
                result = ":/images/W.png";
            break;
            case 'X':
                result = ":/images/X.png";
            break;
            case 'Y':
                 result = ":/images/Y.png";
            break;
            case 'Z':
                result = ":/images/Y.png";
            break;
            case '$': // LL
                result = ":/images/$.png";
            break;
            case '!': // RR
                result = ":images/!.png";
            break;
            case '%': //CH
                result = ":/images/%.png";
            break;
            case '#': // enie
                result = ":/images/#.png";
            break;
            }
        return result;
}

void Casilla::mousePressEvent(QMouseEvent *event){
    emit clicked();
    std::cout<<"Clicked1";
}
