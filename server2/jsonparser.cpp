#include "jsonparser.h"
#include <iostream>
#include <cstring>

JsonParser::JsonParser()
{

}


// Pasa de array de fichas a json
string JsonParser::toJson(FichaToSend fichas[], int size){
    string result = "[";
   // qDebug() << sizeof (int);
    for(int i=0;i<size;i++){
        result = result + "{letra:\"" + fichas[i].getLetra()+"\""
                +",x:"+to_string(fichas[i].getX())+
                ",y:"+to_string(fichas[i].getY())+
                +"}";
        if(i!=size-1){
            result+=",";
        }
    }
    return result;
}

FichaToSend JsonParser::toFicha(const char input[]){
    FichaToSend newFicha = FichaToSend();
    for(int i=0;i<sizeof(input);i++){
        if(input[i] == '{'){
            i+=8;
            newFicha.setLetra(string(1,input[i])); // Poniendo letra
//            qDebug() << input[i];
            i+=5; //i = primer numero de x
            string x_num;
            while(input[i]!=','){
                x_num += (input[i]);
                i++;
            }
            newFicha.setX(std::atoi(x_num.c_str())); // Poniendo x
            // here input[i] = ,
            i+=3; // i = primer numero de y
            string y_num;
            while(input[i] != '}'){
                y_num += input[i];
                i++;
            }
            newFicha.setY(std::atoi(y_num.c_str())); // Poniendo y
            // input[i] = }
        }
    }
    return newFicha;
}

list<FichaToSend> JsonParser::toListFicha(const char input[]){
    string jsonFicha;
    list<FichaToSend> result = list<FichaToSend>();
    FichaToSend ficha;
   // qDebug() << "Special:"<<strlen(input);
    for(int j=0;j<strlen(input);j++){
        jsonFicha = "";
        if(input[j]=='{'){
            while(input[j]!='}'){
                jsonFicha+=input[j];
                j++;
            }
            //input[i] = }
            jsonFicha+=input[j];
            ficha = toFicha(jsonFicha.c_str());
            result.push_back(ficha);
        }
    }
    return result;
}
