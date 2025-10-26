#ifndef MEDIO_H
#define MEDIO_H
#include <iostream>
#include <string>
using namespace std;

class Medio{
    private:
        string nombremedio;
    public:
        Medio();
        Medio(string);
        void setNombremedio(string);
        string getNombre();
        ~Medio();
};
#endif