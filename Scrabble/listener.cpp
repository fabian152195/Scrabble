#include "listener.h"

Listener::Listener()
{

}


void Listener::listen(){
    Client::readFromServer(Client::buffer);

}


/* Voy a tener varios signals segun las diferentes acciones que puedo realizar
 * Voy a tener varios slots en Game segun las diferentes acciones que puedo realizar
*/
