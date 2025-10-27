#ifndef AUTOR_H
#define AUTOR_H
#include <iostream>
#include <string>
#include "persona.h"
#include "medio.h"
#include "sistemas.h"
using namespace std;

class Autor : public Persona{
    private:
        Medio medio; // Composición
    public:
        Autor();
        Autor(string,int,string);
        void registrarNoticia();
        ~Autor();
};

#endif