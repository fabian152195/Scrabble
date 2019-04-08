//
// Created by fabian on 27/03/19.
//
#include "server.h"



using namespace std;

server::server() {
}

int server::run() {
    //Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux
        int opt = TRUE;
        this->room = new Room();
        int master_socket, addrlen, new_socket, client_socket[5],
                max_clients = 5, activity, i, valread, sd;
        int max_sd;
        struct sockaddr_in address;
        int condicion;
        char buffer[1025];  //data buffer of 1K
        //set of socket descriptors
        fd_set readfds;

        //a message
        char *message = "ECHO Daemon v1.0 \r\n";

        //initialise all client_socket[] to 0 so not checked
        for (i = 0; i < max_clients; i++) {
            client_socket[i] = 0;
        }

        //create a master socket
        if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        //set master socket to allow multiple connections ,
        //this is just a good habit, it will work without this
        if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt,
                       sizeof(opt)) < 0) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }

        //type of socket created
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        cout << inet_ntoa(address.sin_addr) << endl;

    //bind the socket to localhost port 8080
        if (bind(master_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        printf("Listener on port %d \n", PORT);

        //try to specify maximum of 3 pending connections for the master socket
        if (listen(master_socket, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }

        //accept the incoming connection
        addrlen = sizeof(address);
        puts("Waiting for connections ...");

        while (TRUE) {
            //clear the socket set
            FD_ZERO(&readfds);

            //add master socket to set
            FD_SET(master_socket, &readfds);
            max_sd = master_socket;

            //add child sockets to set
            for (i = 0; i < max_clients; i++) {
                //socket descriptor
                sd = client_socket[i];

                //if valid socket descriptor then add to read list
                if (sd > 0)
                    FD_SET(sd, &readfds);

                //highest file descriptor number, need it for the select function
                if (sd > max_sd)
                    max_sd = sd;
            }

            //wait for an activity on one of the sockets , timeout is NULL ,
            //so wait indefinitely

            activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

            if ((activity < 0) && (errno != EINTR)) {
                printf("select error");
            }
            cout << "este: " <<  ntohs(address.sin_port) << endl;
            //If something happened on the master socket ,
            //then its an incoming connection
            if (FD_ISSET(master_socket, &readfds)) {
                if ((new_socket = accept(master_socket,
                                         (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }

                //inform user of socket number - used in send and receive commands
                printf("New connection, socket fd is %d , ip is : %s , port : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

                //add new socket to array of sockets
                for (i = 0; i < max_clients; i++) {
                    //if position is empty
                    if (client_socket[i] == 0) {
                        client_socket[i] = new_socket;
                        printf("Adding to list of sockets as %d\n", i);

                        break;
                    }
                }
            }

            //else its some IO operation on some other socket
            for (i = 0; i < max_clients; i++) {
                cout << "entrooooo"<<endl;
                sd = client_socket[i];

                if (FD_ISSET(sd, &readfds)) {
                    //Check if it was for closing , and also read the
                    //incoming message
                    cout << "valreadAF: " << valread << endl;

                    if ((readFromClient(sd,buffer) == 0)) {
                        //Somebody disconnected , get his details and print
                        cout << "valread M: " << valread << endl;
                        getpeername(sd, (struct sockaddr *) &address, \
                        (socklen_t *) &addrlen);
                        printf("Host disconnected , ip %s , port %d \n",
                               inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                        room->getPlayers().clear();
                        //Close the socket and mark as 0 in list for reuse
                        close(sd);
                        client_socket[i] = 0;
                    }
                        //Echo back the message that came in
                    else {
                        //set the string terminating NULL byte on the end
                        //of the data read
                        if(strncmp(buffer,"room_c",6)==0){ // peticion de creacion
                            cout<<"New room!"<<endl;
                            sendToClient(sd,"name");
                            readFromClient(sd, buffer);
                            cout<<buffer<<endl<<flush;
                            //this->room = new Room(generaCodigo());
                            //rooms.push_back(room);
                            room->setCode(generaCodigo());
                            sendToClient(sd, to_string(room->getCode()).c_str());
                            this->room->addPlayer(new Player(sd, buffer));
                        }else if(strncmp(buffer, "room_j",6)==0){  //peticion de union
                            cout<<"Joining room!"<<endl;
                            sendToClient(sd,"code");
                            readFromClient(sd, buffer);  // Obtiene el codigo
                            bool found = false;
                            if(strncmp(std::to_string(room->getCode()).c_str(),buffer,10)==0){  //Cuando la encuentre...
                                sendToClient(sd,"approved");
                                // readFromClient(sd, buffer); // pong
                                // sendToClient(sd,std::to_string(selected.getCode()).c_str());  // Envia codigo de sala
                                readFromClient(sd,buffer);  // Pide el nombre
                                Player *new_player = new Player(sd, buffer);
                                room->addPlayer(new_player);
                                cout<<"Hay:"<<room->getPlayers().size()<<endl;
                                if(room->getPlayers().size() == 4){
                                    //Empiece el juego hp
                                    cout<< "Ya";
                                    for(Player *player : room->getPlayers()){
                                        sendToClient(player->getClient(), "play");
                                        readFromClient(player->getClient(), buffer); // Sincronizando
                                    }
                                    // Aqui inicia el juego
                                    // Setup
                                    Juego juego = Juego(room->getPlayers());
                                    int j =0;
                                    for(Player *player : room->getPlayers()){
                                        if(j==0){
                                            asignarF(player, juego);
                                        }else {
                                            asignar(player, 7, juego);
                                        }
                                        if(j==0){
                                            sendToClient(player->getClient(), "turn");
                                            readFromClient(player->getClient(), buffer);
                                            sendToClient(player->getClient(), "true");
                                            readFromClient(player->getClient(), buffer); // Fin de la orden
                                        }else{
                                             sendToClient(player->getClient(), "turn");
                                            readFromClient(player->getClient(), buffer);
                                            sendToClient(player->getClient(), "false");
                                            readFromClient(player->getClient(), buffer); // Fin de la orden
                                        }
                                        j++;
                                    }
                                    // Gameloop
                                    bool finished = false;
                                    int current_client;
                                    Player *current_player;
                                    bool new_turn = true;
                                    int pass = 0;
                                    while(!finished) {
                                        // Elijo a quien escuchar (al jugador activo)
                                        if (new_turn) {
                                        int k = 0;
                                        for (Player *player:room->getPlayers()) {
                                            if (k == juego.getJugadorActivo()) {
                                                current_client = player->getClient();
                                                current_player = player;
                                            }
                                            k = (k+1)%4;
                                        }
                                        }else{
                                            new_turn = true;
                                        }
                                        // Recibo jugada
                                        usleep(1000000);
                                        readFromClient(current_client, buffer);  // Jugada
                                        cout<<pass<<flush<<endl;
                                        if(pass==4){
                                            finished = true;
                                            break;
                                        }
                                        if (strncmp(buffer, ".", 2) == 0) {
                                            pass++;
                                            // Pasar turno
                                            juego.setJugadorActivo(1);
                                            i = 0;
                                            for (Player *player:room->getPlayers()) {
                                                if (i == juego.getJugadorActivo()) {
                                                    sendToClient(player->getClient(), "turn");
                                                    readFromClient(player->getClient(), buffer);
                                                    sendToClient(player->getClient(), "true");
                                                    readFromClient(player->getClient(), buffer); // Fin de la orden
                                                } else {
                                                    sendToClient(player->getClient(), "turn");
                                                    readFromClient(player->getClient(), buffer);
                                                    sendToClient(player->getClient(), "false");
                                                    readFromClient(player->getClient(), buffer); // Fin de la orden
                                                }
                                                i++;
                                            }

                                        } else {
                                            pass = 0;
                                        string jugada = buffer;
                                        cout << "Jugada:" << buffer << flush << endl;
                                        list<FichaToSend> fichas_recibidas = JsonParser::toListFicha(buffer);
                                        list<Ficha *> fichas_usadas;  // To do bien hasta aqui
                                        for (FichaToSend ficha:fichas_recibidas) {
                                            for (int i = 0; i < current_player->getFichas().getSize(); i++) {
                                                Ficha *ficha_jugador = current_player->getFichas().findData(
                                                        i)->getData();
                                                if (strncmp(ficha.getLetra().c_str(), ficha_jugador->getLetra().c_str(),
                                                            3) == 0) {
                                                    ficha_jugador->setPosX(ficha.getX());
                                                    ficha_jugador->setPosY(ficha.getY());
                                                    fichas_usadas.push_back(ficha_jugador);
                                                    break;
                                                }
                                            }

                                        }
                                        int puntaje;
                                        string *principal = new string;
                                        *principal = "";
                                        puntaje = juego.nuevaJugada(
                                                fichas_usadas, principal); // Si es 0 la palabra es denegada
                                        if (puntaje != 0) {
                                            sendToClient(current_client, "valido");  // validacion
                                            readFromClient(current_client, buffer);
                                            current_player->setPuntaje(current_player->getPuntaje() + puntaje);
                                            // Asignar puntaje al jugador actual
                                            sendToClient(current_client, "addP");
                                            readFromClient(current_client, buffer);
                                            sendToClient(current_client, to_string(puntaje).c_str());

                                            // Enviar array nuevas a todos los jugadores, dejarlo de ultimo
                                            broadcoast(room->getPlayers(), "updateM");
                                            usleep(10000);
                                            broadcoast(room->getPlayers(), jugada.c_str());
                                            //Quitar las fichas usadas al jugador actual
                                            /* for(FichaToSend ficha:fichas_recibidas){
                                                 std::list<Ficha*>::iterator i = current_player->getFichas().begin();
                                                 while (i != current_player->getFichas().end())
                                                 {
                                                     if (strncmp((**i).getLetra().c_str(), ficha.getLetra().c_str(), 3)==0)
                                                     {
                                                         current_player->getFichas().erase(i++);  // alternatively, i = items.erase(i);
                                                         break;
                                                     }
                                                     else
                                                     {
                                                         ++i;
                                                     }
                                                 }
                                             }
                                             */
                                            DoublyLinkedList<Ficha *> nuev_ficha = DoublyLinkedList<Ficha *>();

                                            DoublyLinkedList<Ficha *> *cochinada = new DoublyLinkedList<Ficha *>();
                                            *cochinada = current_player->getFichas();

                                            for (int i = 0; i < current_player->getFichas().getSize(); i++) {
                                                Ficha *ficha_player = current_player->getFichas().findData(
                                                        i)->getData();
                                                for (FichaToSend ficha:fichas_recibidas) {
                                                    if (strncmp(ficha_player->getLetra().c_str(),
                                                                ficha.getLetra().c_str(), 2) == 0) {
                                                        cochinada->deleteDataByLetter(ficha_player->getLetra());
                                                        break;
                                                    }
                                                }
                                            }

                                            current_player->setFichas(*cochinada);
                                            // Bien hasta aqui, tiene solo la cantidad de fichas que le quedan despues de usarlas
                                            // Darle mas fichas al jugador actual
                                            usleep(1000000);
                                            sendToClient(current_client, "addFi");
                                            readFromClient(current_client, buffer);
                                            juego.agregarFichas(current_player, fichas_recibidas.size());
                                            FichaToSend ficha_send[7];
                                            for (int i = 0; i < current_player->getFichas().getSize(); i++) {
                                                Ficha *ficha = current_player->getFichas().findData(i)->getData();
                                                ficha_send[i] = FichaToSend(ficha->getLetra(), ficha->getPosX(),
                                                                            ficha->getPosY());
                                            }
                                            string message = JsonParser::toJson(ficha_send, 7);
                                            cout << message << endl << flush;
                                            sendToClient(current_player->getClient(), message.c_str());
                                            readFromClient(current_player->getClient(), buffer);   // Fin de la orden


                                            // Pasar turno
                                            juego.setJugadorActivo(1);
                                            i = 0;
                                            for (Player *player:room->getPlayers()) {
                                                if (i == juego.getJugadorActivo()) {
                                                    sendToClient(player->getClient(), "turn");
                                                    readFromClient(player->getClient(), buffer);
                                                    sendToClient(player->getClient(), "true");
                                                    readFromClient(player->getClient(), buffer); // Fin de la orden
                                                } else {
                                                    sendToClient(player->getClient(), "turn");
                                                    readFromClient(player->getClient(), buffer);
                                                    sendToClient(player->getClient(), "false");
                                                    readFromClient(player->getClient(), buffer); // Fin de la orden
                                                }
                                                i++;
                                            }
                                        } else {
                                            // mensaje de error
                                            sendToClient(current_client, "firstbad");
                                            readFromClient(current_client, buffer);
                                            if(strncmp(buffer, "262144",7)!=0){
                                                // Enviar al experto
                                                Arduino_Manager arduino = Arduino_Manager();
                                                bool experto = arduino.verificar(*principal);
                                                if(experto && juego.valEjes(fichas_usadas)){
                                                    list<Ficha*> nueva = list<Ficha*>();
                                                    sendToClient(current_client,"correcta");
                                                    //Agregar al diccionario
                                                }else{
                                                    sendToClient(current_client, "repeat");
                                                    readFromClient(current_client, buffer);
                                                    new_turn = false;
                                                }
                                            }else{
                                                sendToClient(current_client, "repeat");
                                                readFromClient(current_client, buffer);
                                                new_turn = false;
                                            }
                                        }
                                    }

                                        //break;  // comentar
                                       /*
                                        * Todo:
                                        *   - Recibir jugada
                                        *   - Procesar jugada
                                        *   - Si esta bien:
                                        *     x Decirle al cliente activo correcta
                                        *     x Modificar la matriz local
                                        *     x Broadcast de la matriz modificada
                                        *   - Si esta mal:
                                        *     x Decirle al cliente especifico esta mal
                                        *     x Esperar experto o nueva palabra
                                        *     x Si experto:
                                        *       . Enviar palabra a experto
                                        *       . Esperar validacion
                                        *       . Si correcta:
                                        *         * Enviar correcta a cliente
                                        *         * Modificar matriz local
                                        *         * Broadcast de la matriz modificada
                                        *       . Si incorrecta:
                                        *         * Notificar fallida absoluta
                                        *         * Volver al inicio
                                        *     x Si repetir:
                                        *       . Volver al inicio
                                        * */
//                                       readFromClient();
                                    }
                                    broadcoast(room->getPlayers(),"finish");

                                }
                            }else{
                                sendToClient(sd,"rejected");
                            }
                        }
                    }
                }
            }
        }
}

void server::asignar(Player *player, int n, Juego juego) {
    juego.asignarFichas(n, player);
    cout << "Envio addf" << endl;
    sendToClient(player->getClient(), "addF");
    readFromClient(player->getClient(), buffer);
    FichaToSend ficha_send[7];
    for(int i=0;i<player->getFichas().getSize();i++){
        Ficha *ficha = player->getFichas().findData(i)->getData();
        ficha_send[i] = FichaToSend(ficha->getLetra(), ficha->getPosX(), ficha->getPosY());
    }
    string message = JsonParser::toJson(ficha_send, 7);
    cout << message << endl << flush;
    //usleep(1000000);
    sendToClient(player->getClient(), message.c_str());
    readFromClient(player->getClient(), buffer);   // Fin de la orden
}

void server::asignarF(Player *player, Juego juego){
    juego.asignarF(player);
    cout << "Envio addf" << endl;
    sendToClient(player->getClient(), "addF");
    readFromClient(player->getClient(), buffer);
    FichaToSend ficha_send[7];
    for(int i=0;i<player->getFichas().getSize();i++){
        Ficha *ficha = player->getFichas().findData(i)->getData();
        ficha_send[i] = FichaToSend(ficha->getLetra(), ficha->getPosX(), ficha->getPosY());
    }
    string message = JsonParser::toJson(ficha_send, 7);
    cout << message << endl << flush;
    //usleep(1000000);
    sendToClient(player->getClient(), message.c_str());
    readFromClient(player->getClient(), buffer);   // Fin de la orden
}

int server::sendToClient(int server_fd, const char* mensaje) {
    return send(server_fd,mensaje,strlen(mensaje),0);
}



int server::readFromClient(int client_fd, char* buffer) {
    int valread= read(client_fd, buffer, 1024);
    buffer[valread] = '\0';
    return valread;
}

void server::broadcoast(int client_socket[5], char * mensaje){
    for(int i = 0; i<5; i++){
        if (client_socket[i]!=0){
            send(client_socket[i],mensaje,strlen(mensaje),0);
        }
    }
}

void server::broadcoast(list<Player*> players, const char *mensaje) {
    for(Player *player:players){
        sendToClient(player->getClient(), mensaje);
    }
}


int server::generaCodigo() { //genera codigo de acceso, que es un numero randon entre 100000 y 999999

    int codigo = rand() % 900000 + 100000;
    return codigo;
}

