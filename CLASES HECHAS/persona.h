#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
using namespace std;

class Persona{
    protected:
        int dni;
        string nombre;
    public:
        Persona();
        Persona(string,int);
        void setDni(int);
        void setNombre(string);
        int getDni();
        string getNombre();
        ~Persona();
};

#endif