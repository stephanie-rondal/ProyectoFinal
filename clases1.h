#include <iostream>
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
        void registrarAutor();
        void registrarUsuario();
        void registrarNoticia();
        void registrarComentario();
        void listarnoticiasanio();
        void listarnoticiasmes();
        ~Sistema();
};

class Noticia{
    private:
        string titulo, detalle;
        int dia, mes, anio, nn;
        Autor autor;
        Comentario comentarios[20];
    public:
        Noticia();
        Noticia(string,int,int,int,int,int);
        void setTitulo(string);
        void setDetalle(int);
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        string getTitulo();
        string getDetlle();
        int getDia();
        int getMes();
        int getAmio();
        int getNN();
        void agregarcomentario(Comentario);
        ~Noticia();
};

class Comentario{
    private:
        int numero;
        string texto, usuario;
        Usuario usuario;
    public:
        Comentario();
        Comentario(int,string,string);
        void setNumero(int);
        void setTexto(string);
        int getNumero();
        string getTexto();
        ~Comentario();
};

class Medio{
    private:
        string nombremedio;
    public:
        Medio();
        Medio(string);
        string getNombre();
        ~Medio();
};

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

class Autor : public Persona{
    private:
        Medio medio; // Composición
    public:
        Autor();
        Autor(string,int,string);
        ~Autor();
};

class Usuario : public Persona{
    private:
    int edad;

    public:
    Usuario();
    Usuario(string,int,int);
    ~Usuario();
};