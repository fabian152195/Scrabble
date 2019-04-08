//
// Created by malavassi on 07/04/19.
//

#include "Arduino_Manager.h"

using namespace std;
/**
 * Inicializa las variables necesarias para la comunicacion serial
 */
void Arduino_Manager::inicializar() {

    memset (&tty, 0, sizeof tty);

/* Error Handling */
    if ( tcgetattr ( USB, &tty ) != 0 ) {
        cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << endl;
    }

/* Save old tty parameters */
    tty_old = tty;

/* Set Baud Rate */
    cfsetospeed (&tty, (speed_t)B9600);
    cfsetispeed (&tty, (speed_t)B9600);

/* Setting other Port Stuff */
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;

    tty.c_cflag     &=  ~CRTSCTS;           // no flow control
    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

/* Make raw */
    cfmakeraw(&tty);

/* Flush Port, then applies attributes */
    tcflush( USB, TCIFLUSH );
    if ( tcsetattr ( USB, TCSANOW, &tty ) != 0) {
        cout << "Error " << errno << " from tcsetattr" << endl;
    }
}
/**
 * Lee lo que se recibe en el puerto serial
 * @return char paran diferenciar la entrada que se obtuvo
 */
char Arduino_Manager::leer() {
    spot = 0;
/*Whole response*/
    char response[500];
    memset(response, '\0', sizeof response);

    do {
        n = read( USB, &buf, 1 );
        sprintf( &response[spot], "%c", buf );
        spot += n;
    } while( buf != '.' && n > 0);
    if (n < 0) {
        cout << "Error reading: " << strerror(errno) << endl;
    }
    else if (n == 0) {
        cout << "Read nothing!" << endl;
    }
    else {
        cout << "Response: " << response << endl;
        return response[0];
    }
}
/**
 * Envia datos al arduino a traves del puerto serial
 * @param cmd array de caracteres que se reciben a traves del puerto serial
 * @param size tamano del array cmd
 */
void Arduino_Manager::escribir(unsigned char* cmd, int size) {
    int n_written = 0,
            spot = 0;
    usleep(1750000);
    while (spot < size) {
        n_written = write(USB, &cmd[spot], 1);
        spot += n_written;
        usleep(2000);
    }
} /**
 * Envia una palabra al arduino para mostrarla en la pantalla LCD
 * @param cadena palabra que se envia al arduino
 */
void Arduino_Manager::enviar_palabra(string cadena) {
    cadena += '.';
    unsigned char cadena1[cadena.size()];
    for(int i = 0; i < cadena.size();i++){
        cadena1[i] = cadena[i];
    }
    escribir(cadena1, cadena.size());
    }

    /**
     * Recibe datos de los botones
     * @return booleano para identificar el boton que se oprime
     */
bool Arduino_Manager::entrada() {
    char aux = this->leer();
    if (aux == '2') {
        cout << "RETORNA FALSO" << endl;
        return false;
    } else if (aux == '1') {
        cout << "RETORNA VERDADERO" << endl;
    }
}
/**
 * Metodo que muestra una palabra en la pantalla LCD y le permite al usuario aceptarla o rechazarla
 * @param palabra palabra por mostrar en la pantalla LCD
 * @return booleano que identifica el boton que se oprimio
 */
bool Arduino_Manager::verificar(string palabra){
        this->inicializar();
        this->enviar_palabra(palabra);
        bool a = this->entrada();
        this->enviar_palabra(palabra);
        if(a) {
            this->enviar_palabra("ACEPTADA");
        }else{
            this->enviar_palabra("DENEGADA");
        }
    return a;
    }

