#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include "persona.h"
using namespace std;

class Usuario : public Persona{
    private:
    int edad;

    public:
    Usuario();
    Usuario(string,int,int);
    ~Usuario();
};
#endif