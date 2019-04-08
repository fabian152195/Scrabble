#include "listener.h"

Listener::Listener()
{
}
    Q_DECLARE_METATYPE(list<Ficha>);
void Listener::listen(){
    Client::sendToServer("ping");
//    cout<<"Escuchando"<<flush<<endl;
    qRegisterMetaType<list<Ficha>>();
    Client::readFromServer(Client::buffer);
    while(strncmp(Client::buffer,"finish",7)!=0){
    if(strncmp(Client::buffer,"addF",5)==0){  // Si le esta pasando la orden de agregar fichas...
        cout<<"AddF"<<flush<<endl;
        Client::sendToServer("ping");
        Client::readFromServer(Client::buffer);
        list<FichaToSend> fichasS = JsonParser::toListFicha(Client::buffer);
        list<Ficha> fichas = list<Ficha>();
        for(FichaToSend ficha:fichasS){
            fichas.push_back(Ficha(ficha.getLetra().c_str(), QPoint(ficha.getX(),ficha.getY())));
        }
        emit addFichas(fichas);
        Client::sendToServer("ping");
    }else if(strncmp(Client::buffer,"addFi",6)==0){
        Client::sendToServer("ping");
        Client::readFromServer(Client::buffer);
        list<FichaToSend> fichasS = JsonParser::toListFicha(Client::buffer);
        list<Ficha> fichas = list<Ficha>();
        for(FichaToSend ficha:fichasS){
            fichas.push_back(Ficha(ficha.getLetra().c_str(), QPoint(ficha.getX(),ficha.getY())));
        }
        emit addFichasB(fichas);
        Client::sendToServer("ping");
    }else if(strncmp(Client::buffer,"turn",5)==0){  // Orden turn
        cout<<"turn order"<<flush<<endl;
        Client::sendToServer("ping");
        Client::readFromServer(Client::buffer);  // true or false dependiendo si es mi turno o no
        bool turn;
        turn = strncmp(Client::buffer, "true",5)==0;
        emit modTurn(turn);
        Client::sendToServer("ping");
    }else if(strncmp(Client::buffer,"valido",7)==0){
        Client::sendToServer("ping");
        emit confirmacionPalabra(true);
    }else if(strncmp(Client::buffer, "addP",5)==0){
        Client::sendToServer("ping");
        Client::readFromServer(Client::buffer);
        emit addPuntaje(atoi(Client::buffer));
    }else if(strncmp(Client::buffer, "updateM",8)==0){
        Client::readFromServer(Client::buffer);
        list<FichaToSend> fichasS = JsonParser::toListFicha(Client::buffer);
        list<Ficha> fichas = list<Ficha>();
        for(FichaToSend ficha:fichasS){
            fichas.push_back(Ficha(ficha.getLetra().c_str(), QPoint(ficha.getX(),ficha.getY())));
        }
        emit updateM(fichas);
    }else if(strncmp(Client::buffer, "firstbad",9)==0){
        emit firstBad();
    }else if(strncmp(Client::buffer, "correcta",9)==0){
        emit correcta();
    }else if(strncmp(Client::buffer,"repeat",7)==0){
        emit repeat();
    }
    Client::readFromServer(Client::buffer);
    }
    emit final();

}


/* Voy a tener varios signals segun las diferentes acciones que puedo realizar
 * Voy a tener varios slots en Game segun las diferentes acciones que puedo realizar
*/
