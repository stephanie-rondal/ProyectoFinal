#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include <string>
using namespace std;

class Comentario{
    private:
        int numero;
        string texto, usuario;
    public:
        Comentario();
        Comentario(int,string,string);
        void setNumero(int);
        void setTexto(string);
        int getNumero();
        string getTexto();
        void mostrar();
        ~Comentario();
};

#endif