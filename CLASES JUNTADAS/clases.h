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


class Autor : public Persona{
    private:
        Medio medio;
    public:
        Autor();
        Autor(string,int,string);
        ~Autor();
};

class Comentario{
    private:
        int numero;
        string texto, usuario;
    public:
        Comentario();
        Comentario(int,string,string);
        void setNumero(int);
        void setTexto(string);
        void setUsuario(string);
        int getNumero();
        string getTexto();
        string getUsuario();
        void mostrar();
        ~Comentario();
};

class Noticia{
    private:
        string titulo, detalle, autor;
        int dia, mes, anio, cantcomentario=0;
        int maxComentarios;   // Capacidad máxima de comentarios para poder crear el arreglo dinámico de comentarios
        Comentario *comentarios;    // Declaré la composición por referencia (puntero)
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

class Usuario : public Persona{
    private:
        int edad;
    public:
        Usuario();
        Usuario(string,int,int);
        void agregarcomentario();
        ~Usuario();
};


class Sistema{
    private:
        Autor *autores;
        Usuario *usuarios;
        Noticia *noticias;
        int maxAutores, maxUsuarios, maxNoticias; // Capacidad maxima para poder crear los arreglos dinámicos
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