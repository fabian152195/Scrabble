#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <list>
#include <iostream>

using namespace std;
class Collector
{
private:
    std::list<void*> free_space;
public:
    Collector();
    void Delete(void* pointer);
    void* New();
    void display();
};
#endif // COLLECTOR_H
