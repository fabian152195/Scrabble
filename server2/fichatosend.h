#ifndef FICHATOSEND_H
#define FICHATOSEND_H

#include <string>
using namespace std;

class FichaToSend
{
public:
    FichaToSend();
    FichaToSend(string letra, int x, int y);
    int getX();
    int getY();
    string getLetra();
    void setX(int x);
    void setY(int y);
    void setLetra(string letra);
private:
    string letra;
    int x;
    int y;
};

#endif // FICHATOSEND_H
