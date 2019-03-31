#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include "ficha.h"
#include "fichatosend.h"
#include <list>

using namespace std;


class JsonParser
{
public:
    static string toJson(Ficha ficha[]);
    static FichaToSend toFicha(const char input[]);
    static list<FichaToSend> toListFicha(const char input[]);
private:
    JsonParser();
};

#endif // JSONPARSER_H
