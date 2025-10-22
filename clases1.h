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
        Noticia(string t, int d, int day, int mon, int an, int nn);
        void setTitulo(string t);
        void setDetalle(int d);
        void setDia(int day);
        void setMes(int mon);
        void setAnio(int an);
        string getTitulo();
        string getDetlle();
        int getDia();
        int getMes();
        int getAmio();
        int getNN();
        void agregarcomentario(Comentario com);
        ~Noticia();
};

class Comentario{
    private:
        int numero;
        string texto, usuario;
        Usuario usuario;
    public:
        Comentario();
        Comentario(int num, string tex, string usu);
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
        Medio(string n);
        string getNombre();
        ~Medio();
};

class Persona{
    protected:
        int dni;
        string nombre;
    public:
        Persona();
        Persona(string n, int doc){
            nombre=n;
            dni=doc;
        }

        ~Persona();
};

class Autor : public Persona{
    private:
        Medio medio; // Composición
    public:
        Autor();
        Autor(string n, int doc, string m);
        ~Autor();
};

class Usuario : public Persona{
    private:
    int edad;

    public:
    Usuario();
    Usuario(string n, int doc, int e);
    ~Usuario();
};