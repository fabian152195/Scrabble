#include "matrizgrafica.h"
#include <iostream>
#include "game.h"

MatrizGrafica::MatrizGrafica()
{
    // Inicializa la matriz de espacios
    for(int i = 0; i<15;i++){
        for(int j = 0;j<15;j++){
            espacios[i][j] = '.'; // C++ no permite char vacios, entonces como valor vacio se usara un .
        }
    }
}

void MatrizGrafica::actualizarMatriz(int x, int y, char letter)
{
    espacios[x][y] = letter;
}

void MatrizGrafica::actualizarMatriz(int x, int y, int direction, char word[])
{
    switch(direction){
    case 1:
        // Itero la x, no la y
        for(int i=x;i<(sizeof (word)/sizeof (*word));i++){
            espacios[i][y] = word[i];  // En espacios x,y pongo la laetra word[i]
        }
        break;
    case 2:
        // Itero la y, no la x
        for(int i=y;i<(sizeof (word)/sizeof (*word));i++){
            espacios[x][i] = word[i];  // En espacios x,y pongo la laetra word[i]
        }
        break;
    }
}

/**
Problema actual: frame solo se pude definir una vez
Posible solucion: definir una lista global de frames, uno en cada espacio del tablero donde cada frame sea una clase
Cuando se quiere poner una letra en ese tablero se cambia el atributo letra a la letra a elegir e inmediatamente se
dibuja sobre la pantalla
No se necesitaria el metodo paint
El switch podria ser util, no borrar
Las siete fichas del usuario tambien deberian ser frames, para que almacenen letras
*/
void MatrizGrafica::paint(Game *game){
    QWidget *frame = new QWidget(game);
    for(int i = 0; i<15; i++){
        for(int j = 0; j<15; j++){
            switch (espacios[i][j]) {
            case 'A':
                frame->setGeometry(i*53,j*33,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/A.png)");
                break;
            case 'B':
                frame->setGeometry(i*53,j*33,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/B.png)");
                break;
            case 'C':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/C.png)");
                break;
            case 'D':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/D.png)");
                break;
            case 'E':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/E.png)");
                break;
            case 'F':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/F.png)");
                break;
            case 'G':
                frame->setGeometry(i*10,j*10,53,30); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/G.png)");
                break;
            case 'H':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/H.png)");
                break;
            case 'J':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/J.png)");
                break;
            case 'K':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/K.png)");
                break;
            case 'L':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/L.png)");
                break;
            case 'M':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/M.png)");
                break;
            case 'N':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/N.png)");
                break;
            case 'O':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/O.png)");
                break;
            case 'P':
                frame->setGeometry(i*10,j*10,53,30); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/P.png)");
                break;
            case 'Q':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/Q.png)");
                break;
            case 'R':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/R.png)");
                break;
            case 'S':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/S.png)");
                break;
            case 'T':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/T.png)");
                break;
            case 'U':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/U.png)");
                break;
            case 'V':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/V.png)");
                break;
            case 'W':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/W.png)");
                break;
            case 'X':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/X.png)");
                break;
            case 'Y':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/Y.png)");
                break;
            case 'Z':
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/Z.png)");
                break;
            case '$': // LL
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/$.png)");
                break;
            case '!': // RR
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/!.png)");
                break;
            case '%': //CH
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/%.png)");
                break;
            case '#': // enie
                frame->setGeometry(i*10,j*10,53,33); //Especificar mejor las dimensiones
                frame->setStyleSheet("background-image: url(:/images/#.png)");
                break;
            }
        }
    }
}
