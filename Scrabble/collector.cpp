#include "collector.h"

Collector::Collector()
{
    free_space = std::list<void *>();
}

void Collector::Delete(void* pointer){
    free_space.push_back(pointer);
}

void* Collector::New(){
    void *result;
    if(free_space.size()>0){
        result = reinterpret_cast<void*>(free_space.front());
        free_space.pop_front();
    }else{
        result = (new int);
    }
    return result;
}
