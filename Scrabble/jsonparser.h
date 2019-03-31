#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <string>
#include "ficha.h"

using namespace std;


class JsonParser
{
public:
    static string toJson(Ficha ficha[]);
private:
    JsonParser();
};

#endif // JSONPARSER_H
