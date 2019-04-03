//
// Created by fabian on 27/03/19.
//
#include "server.h"



using namespace std;
using namespace rapidjson;

server::server() {
    opt=1;
    hello = (char*) "Hello from client";
    mensaje = new Mensaje("Hellou from client");
}

int server::run() {
    //Example code: A simple server side code, which echos back the received message.
//Handle multiple socket connections with select and fd_set on Linux
        int opt = TRUE;
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

                //send new connection greeting message
                if (sendToClient(new_socket, message) != strlen(message)) {
                    perror("send");
                }

                puts("Welcome message sent successfully");

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
                        //Close the socket and mark as 0 in list for reuse
                        close(sd);
                        client_socket[i] = 0;
                    }
                        //Echo back the message that came in
                    else {
                        //set the string terminating NULL byte on the end
                        //of the data read

                        cout << "envia o recibe: " << generaCodigo() << endl;
                        cin >> condicion;


                        if (condicion == 1) {
                            //char * mensajeX = "HELLOU";
                            broadcoast(client_socket, "HELLOU");
                            printf("message sent\n");

                        } else if (condicion == 2) {
                            printf("%s\n", buffer);
                        } else{}
                    }
                }
            }
        }
}

int server::sendToClient(int server_fd, char* mensaje) {
    return send(server_fd,mensaje,strlen(mensaje),0);
}

int server::readFromClient(int client_fd, char* buffer) {
    int valread= read(client_fd, buffer, 1024);
    buffer[valread] = '\0';
    return valread;
}

int server::broadcoast(int client_socket[5], char * mensaje){
    for(int i = 0; i<5; i++){
        if (client_socket[i]!=0){
            send(client_socket[i],mensaje,strlen(mensaje),0);
        }
    }
}


int server::generaCodigo() { //genera codigo de acceso, que es un numero randon entre 100000 y 999999

    int codigo = rand() % 900000 + 100000;
    return codigo;
}

