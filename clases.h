#include <iostream>
using namespace std;

class Sistema{
    private:
        // Composición
        Autor autores[20];
        Usuario usuarios[20];
        Noticia noticias[20];
    public:
        Sistema();
        void registrar();
        void cargarUsuario();
        void cargarAutor();
        void registrarNoticia();
        void registrarComentario();
        ~Sistema();
};

class Noticia{
    private:
        string titulo;
        string detalle;
        int dia, mes, año;
        Autor autor;
        Comentario comentarios[20];
    public:
        Noticia();
        void setTitulo(string);
        void setDetalle(string);
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        string getTitulo();
        string getDetalle();
        int getDia();
        int getMes();
        int getAnio();
        ~Noticia();
};

class Comentario{
    private:
        int numero;
        string texto;
        Usuario usuario;
    public:
        Comentario();
        void setNumero(int);
        void setTexto(string);
        int getNumero();
        string getTexto();
        ~Comentario();
};

class Medio{
    private:
        string nombre;
    public:
        Medio();
        string getNombre();
        ~Medio();
};

class Persona{
    protected:
        int dni;
        string nombre;
    public:
        Persona();
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