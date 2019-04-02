//
// Created by malavassi on 24/03/19.
//


#include "TXT_Manager.h"
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;
TXT_Manager::TXT_Manager(){

}
int TXT_Manager::puntaje_palabra(string word) {
    int acumulador_palabra = 0;
    cout<<"Sacando el puntaje de: "<<word<<"\n";
    for(int i=0; i<word.length();i++){
        acumulador_palabra += asignarptos(word[i]);
        //cout << "palabra[i]: "<<word[i] << "\n" <<"i:"<<i << "\n"; // esta linea imprime elemento por elemento del que se saca puntaje

    }
    cout << "El valor de la palabra es: "<<acumulador_palabra <<" puntos" << "\n";
    return acumulador_palabra;
}

int TXT_Manager::asignarptos(char letra) {
    switch(letra){
        case 'A':
            return 1;
        case 'E':
            return 1;
        case 'O':
            return 1;
        case 'I':
            return 1;
        case 'S':
            return 1;
        case 'N':
            return 1;
        case 'L':
            return 1;
        case 'R':
            return 1;
        case 'U':
            return 1;
        case 'T':
            return 1;
        case '.':
            return 1;
        case 'D':
            return 2;
        case 'G':
            return 2;
        case 'C':
            return 3 ;
        case 'B':
            return 3;
        case 'M':
            return 3;
        case 'P':
            return 3;
        case 'H':
            return 4 ;
        case 'F':
            return 4;
        case 'V':
            return 4;
        case 'Y':
            return 4;
        case 'CH':
            return 5;
        case 'Q':
            return 5;
        case 'J':
            return 8;
        case 'LL':
            return 8;
        case '#':
            return 8;
        case 'RR':
            return 8;
        case 'X':
            return 8;
        case 'Z':
            return 10;
        default:
            return 0;
    }
}
int TXT_Manager::verif_palabra(string palabra) {
    if(busqueda(palabra)){ //corregir
        cout << "SALIDA:" << puntaje_palabra(palabra) <<"\n";
        return puntaje_palabra(palabra);
    }else{
        cout << "SALIDA: 0" <<"\n";
        return 0;
    }
}

bool TXT_Manager::busqueda(string cadena) {
    ifstream fe("/home/malavassi/Escritorio/TXTManager/Diccionario.txt");
    string *a = new string();
    while(!fe.eof()){
        fe >> *a;
        //cout << *a << "\n"; // esta linea imprime todo el diccionario hasta que encuentra la palabra
        if(*a==cadena) {
            cout << "Coincidencia:" << *a << "\n";
            fe.close();
            free(a);
            cout << "Esta en diccionario: TRUE" << "\n";
            return true;
        }
    }
    fe.close();
    free(a);
    cout << "Esta en diccionario: FALSO" << "\n";
    return false;
}

//TESTS
struct TXT_Manager_TEST : public testing::Test{
   TXT_Manager *test;
   void SetUp(){test = new TXT_Manager();}
   void TearDown(){delete test;}
};

TEST_F(TXT_Manager_TEST, puntaje_palabra){
//Arrange //aqui no se usa por ser fixture
//Act
//Assert
ASSERT_EQ(test->puntaje_palabra("YUXTAPOSICION"),27);
}

TEST_F(TXT_Manager_TEST, asignar_ptos){
    //Arrange
    //Act
    //Assert
    ASSERT_EQ(test->asignarptos('A'),1);
}

TEST_F(TXT_Manager_TEST, busqueda){
    //Arrange
    //Act
    //Assert
    ASSERT_EQ(test->busqueda("AVE"), true);
}
TEST_F(TXT_Manager_TEST, verif_palabra){
    //Arrange
    //Act
    //Assert
    ASSERT_EQ(test->verif_palabra("HORSE"),0);
}
//TESTS//
