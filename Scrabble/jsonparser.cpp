#include "jsonparser.h"
#include <QtDebug>

JsonParser::JsonParser()
{

}

string JsonParser::toJson(Ficha fichas[]){
    string result = "[";
    int array_size = sizeof(fichas)/sizeof(int);  //Porque son punteros
   // qDebug() << sizeof (int);
    for(int i=0;i<array_size;i++){
        result = result + "{letra:\"" + fichas[i].getLetra().toStdString()+"\""
                +",x:"+to_string(fichas[i].getPos().x())+
                ",y:"+to_string(fichas[i].getPos().x())+
                +"}";
        if(i!=array_size-1){
            result+=",";
        }
    }
    result = result + "]";
    return result;
}
