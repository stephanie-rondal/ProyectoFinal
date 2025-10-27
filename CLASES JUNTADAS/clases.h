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

#ifndef AUTOR_H
#define AUTOR_H
#include <iostream>
#include <string>
#include "persona.h"
#include "medio.h"
using namespace std;

class Autor : public Persona{
    private:
        Medio medio; // Composición
    public:
        Autor();
        Autor(string,int,string);
        ~Autor();
};

#endif

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

#ifndef NOTICIA_H
#define NOTICIA_H
#include <iostream>
#include <string>
#include "comentario.h"
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

#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include "persona.h"
#include "comentario.h"
#include "sistemas.h"
using namespace std;

class Usuario : public Persona{
    private:
    int edad;

    public:
    Usuario();
    Usuario(string,int,int);
    void agregarcomentario();
    ~Usuario();
};
#endif

#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <string>
#include "autor.h"
#include "usuario.h"
#include "noticias.h"
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