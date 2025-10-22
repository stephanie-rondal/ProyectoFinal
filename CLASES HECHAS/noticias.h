#ifndef NOTICIA_H
#define NOTICIA_H
#include <iostream>
#include <string>
#include "comentario.h"
#include "autor.h"
using namespace std;

class Noticia{
    private:
        string titulo, detalle, autor;
        int dia, mes, anio, cantcomentario=0;
        Comentario comentarios[20];
    public:
        Noticia();
        Noticia(string,string,int,int,int,string);
        void setTitulo(string);
        void setDetalle(string);
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        void setAutor(string);
        string getTitulo();
        string getDetalle();
        int getDia();
        int getMes();
        int getAnio();
        string getAutor();
        void agregarcomentario(Comentario);
        void mostrar();
        ~Noticia();
};
#endif