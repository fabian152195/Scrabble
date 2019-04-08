//
// Created by malavassi on 07/04/19.
//

#ifndef UNTITLED1_ARDUINO_MANAGER_H
#define UNTITLED1_ARDUINO_MANAGER_H
using namespace std;

class Arduino_Manager {
public:
    struct termios tty;
    struct termios tty_old;
    int USB = open( "/dev/ttyACM1", O_RDWR| O_NOCTTY );
    int n = 0,
    spot = 0;
    char buf = '\0';
void escribir(unsigned char cmd[], int size);
char leer();
void inicializar();
void enviar_palabra(string cadena);
bool entrada();
void verificar(string palabra);
};


#endif //UNTITLED1_ARDUINO_MANAGER_H
