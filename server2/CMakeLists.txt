cmake_minimum_required(VERSION 3.13)
project(server2)

set(CMAKE_CXX_STANDARD 14)

add_executable(server2 main.cpp DoublyLinkedList.h Ficha.h Ficha.cpp ListaFichas.h ListaFichas.cpp Jugador.h Jugador.cpp
        Node.h TXT_Manager.h TXT_Manager.cpp server.h server.cpp Room.h Room.cpp Player.cpp Player.h Juego.cpp Juego.h)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(server2 gtest gtest_main)