#include "clases1.h"

Sistema::Sistema(){
    contAutor=0;
    contUsuario=0;
    contnoticia=0;


}

Persona::Persona(){}

Persona::Persona(string _nombre, int _dni){
    nombre=_nombre;
    dni=_dni;
}

void Persona::setNombre(string n){
    nombre = n;
}
void Persona::setDni(int d){
    dni = d;
}

string Persona::getNombre(){
    return nombre;
}
int Persona::getDni(){
    return dni;
}

Autor::Autor(){
    nombre = " ";
    dni=0;
}
Autor::Autor(string n, int doc, string m):Persona(n, doc){
    nombre=n;
    dni=doc;
    medio=m;
}

Usuario::Usuario(string _nombre, int _dni, int _edad):Persona(_nombre,_dni){
    edad=_edad;
}

Comentario::Comentario(){}

void Comentario::setNumero(int n){
    numero = n;
}
void Comentario::setTexto(string t){
    texto = t;
}

int Comentario::getNumero(){
    return numero;
}
string Comentario::getTexto(){
    return texto;
}

Comentario::~Comentario(){}

Noticia::Noticia(){}

void Noticia::setTitulo(string t){
    titulo = t;
}
void Noticia::setDetalle(string d){
    detalle = d;
}
void Noticia::setDia(int d){
    dia = d;
}
void Noticia::setMes(int m){
    mes = m;
}
void Noticia::setAnio(int a){
    año = a;
}

string Noticia::getTitulo(){
    return titulo;
}
string Noticia::getDetalle(){
    return detalle;
}
int Noticia::getDia(){
    return dia;
}
int Noticia::getMes(){
    return mes;
}
int Noticia::getAnio(){
    return año;
}

Noticia::~Noticia(){}


void Sistema::registrarAutor(){
    try{
    if (contAutor<20){ //Si contador es menor a la cantidad del vector no cargará nada.
        int dni;
        string nom, med;
        cout<<"Registre su nombre: "; cin>>nom;
        cout<<"Diga su DNI: "; cin>>dni;
        cout<<"¿Para qué medio trabaja?: ";cin>>med;
        autores[contAutor]=Autor(nom, dni, med);
        contAutor++;
    }else{
        cout<<"La cantidad de AUTORES está llena. No se cargará su usuario.";
    }}catch (...){
        cout<<"Error al registrar AUTOR.";
    }
}
void Sistema::registrarUsuario(){
    try{
    if (contUsuario<20){ //Si contador es menor a la cantidad del vector no cargará nada.
        int dni, edad;
        string nom;
        cout<<"Registre su nombre: "; cin>>nom;
        cout<<"Diga su DNI: "; cin>>dni;
        cout<<"¿Qué edad tiene? : ";cin>>edad;
        usuarios[contUsuario]=Usuario(nom, dni, edad);
        contUsuario++;
    }else{
        cout<<"La cantidad de USUARIO está llena. No se cargará su usuario.";
    }}catch (...){
        cout<<"Error al registrar USUARIO.";
    }   
}
void Sistema::registrarNoticia(){
    try{
        if (contAutor>0 && contnoticia<20){
            string titulo, detalle;
            int dia, mes, anio, nn;
            cout<<"----------- Cargar datos de la noticia. -----------"<<endl;
            cout<<"Día: ";cin>>dia;
            cout<<"Mes: ";cin>>mes;
            cout<<"Año: ";cin>>anio;
            cout<<"Título: ";cin>>titulo;
            cout<<"Detalle de la noticia: ";cin>>detalle;
            cout<<"Número de noticia: "; cin>>nn;

            noticias[contnoticia] = Noticia(titulo, detalle, dia, mes, anio, nn);
        }else{
            cout<<"No hay autores registrados o la cantidad de noticias está llena."<<endl;
        }
    }catch(...){
        cout<<"Error al cargar la NOTICIA.";
    }
}
void Sistema::registrarComentario(){
    try{
        if (contnoticia>0 && contUsuario>0){
            int numero, i=0;
            string texto, usuario;
            cout<<"Número de noticia para comentar: "; cin>>numero;
            while (i<contnoticia && noticias[i].getNN()!=numero){
                i++;
            }
            if (i<contnoticia){
                cout<<"Nombre de usuario que comenta: ";cin>>usuario; cout<<endl;
                cout<<"Comentario: "; cin>>texto;
                Comentario c(i+1, texto, usuario);
                noticias[i].agregarcomentario(c);
            }else{
                cout<<"Noticia no encontrada."<<endl;
            }        
        }else{
            cout<<"No se han encontrado noticias o usuarios."<<endl;
        }

    }catch(...){
        cout<<"Error al publicar el comentario.";
    }
}




