cmake_minimum_required(VERSION 3.13)
project(server2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(server2

    CMakeLists.txt
    DoublyLinkedList.h
    Ficha.cpp
    Ficha.h
    Juego.cpp
    Juego.h
    Jugador.cpp
    Jugador.h
    ListaFichas.cpp
    ListaFichas.h
    main.cpp
    Node.h
    Player.cpp
    Player.h
    Room.cpp
    Room.h
    server.cpp
    server.h
    TXT_Manager.cpp
    TXT_Manager.h)
add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)

include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(server2 gtest gtest_main)