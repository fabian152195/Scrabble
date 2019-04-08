#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include "Ficha.h"
#include "fichatosend.h"
#include <list>

using namespace std;


class JsonParser
{
public:
    static string toJson(FichaToSend ficha[], int size);
    static FichaToSend toFicha(const char input[]);
    static list<FichaToSend> toListFicha(const char input[]);
private:
    JsonParser();
};

#endif // JSONPARSER_H
