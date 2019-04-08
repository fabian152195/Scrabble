#include "jsonparser.h"
#include <QtDebug>
#include <iostream>

JsonParser::JsonParser()
{

}

string JsonParser::toJson(Ficha fichas[], int size){
    string result = "[";
    //int array_size = sizeof(fichas)/sizeof(int);  //Porque son punteros
   // qDebug() << sizeof (int);
    for(int i=0;i<size;i++){
        result = result + "{letra:\"" + fichas[i].getLetra().toStdString()+"\""
                +",x:"+to_string(int(fichas[i].getPos().x()/53))+
                ",y:"+to_string(int(fichas[i].getPos().y()/33))+
                +"}";
        if(i!=size-1){
            result+=",";
        }
    }
    result = result + "]";
    cout<<result<<flush<<endl;
    return result;
}

FichaToSend JsonParser::toFicha(const char input[]){
    FichaToSend newFicha = FichaToSend();
    for(int i=0;i<sizeof(input);i++){
        if(input[i] == '{'){
            i+=8;
            string a = string(1, input[i]);
            if(strncmp(a.c_str(),"LL",3)==0){
             newFicha.setLetra("$"); // Poniendo letra
            }else if(strncmp(a.c_str(),"Ñ",2)==0){
                newFicha.setLetra("#"); // Poniendo letra

            }else if(strncmp(a.c_str(),"RR",3)==0){
                newFicha.setLetra("!"); // Poniendo letra

            }else if(strncmp(a.c_str(),"CH",3)==0){
               newFicha.setLetra("%"); // Poniendo letra

            }else{
              newFicha.setLetra(string(1,input[i])); // Poniendo letra

            }
            newFicha.setLetra(string(1,input[i])); // Poniendo letra
            qDebug() << input[i];
            i+=5; //i = primer numero de x
            string x_num;
            while(input[i]!=','){
                x_num += (input[i]);
                i++;
            }
            newFicha.setX(std::atoi(x_num.c_str())*53.4); // Poniendo x
            // here input[i] = ,
            i+=3; // i = primer numero de y
            string y_num;
            while(input[i] != '}'){
                y_num += input[i];
                i++;
            }
            newFicha.setY(std::atoi(y_num.c_str())*33.4); // Poniendo y
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
