#include "clases.h"
#include <iostream>
using namespace std;

Sistema::Sistema(){
    for (int i = 0; i < 20; i++)
    {
        autores[i] = '\0';
        usuarios[i] = '\0';
        noticias[i] = '\0';
    }
    
}
void Sistema::registrar(){
    
}

void Sistema::cargarUsuario(){

}

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
Comentario::Comentario(){

}