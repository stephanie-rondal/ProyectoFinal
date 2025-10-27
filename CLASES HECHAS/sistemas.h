#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <string>
#include "autor.h"
#include "usuario.h"
#include "noticias.h"
#include "comentario.h"
using namespace std;

class Sistema{
    private:
        // Composición
        Autor autores[20];
        Usuario usuarios[20];
        Noticia noticias[20];
        int contAutor=0, contUsuario=0, contnoticia=0;
    public:
        Sistema();
        Sistema(int,int,int);
        void registrarAutor();
        void registrarUsuario();
        void registrarNoticia();
        void registrarComentario();
        void listarnoticiasanio();
        void listarnoticiasmes();
        void listarnoticiacomentario();
        void listarnoticiaautor();
        ~Sistema();
};
#endif