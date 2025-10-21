#include "clases.h"
#include <iostream>
using namespace std;

//-----------Sistema
Sistema::Sistema(){
    
}
void Sistema::registrar(){
    
}

void Sistema::cargarUsuario(){

}

Sistema::~Sistema(){}


//----------- Noticia
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


///--------Comentario
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


//-------Medio
Medio::Medio(){}
Medio::~Medio(){}


//------Persona
Persona::Persona(){}

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

Persona::~Persona(){}


//-------Autor
Autor::Autor(){}

Autor::~Autor(){}


//--------Usuario
Usuario::Usuario(){}

Usuario::~Usuario(){}