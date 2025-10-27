#include "noticias.h"

Noticia::Noticia(){
    titulo="";
    detalle="";
    dia=0;
    mes=0;
    anio=0;
    autor="";
    cantcomentario=0;
}

Noticia::Noticia(string _titulo,string _detalle,int _dia,int _mes,int _anio,string _autor){
    titulo=_titulo;
    detalle=_detalle;
    dia=_dia;
    mes=_mes;
    anio=_anio;
    autor=_autor;
    cantcomentario=0;
}

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
    anio = a;
}
void Noticia::setAutor(string _au){
    autor=_au;    
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
    return anio;
}
string Noticia::getAutor(){
    return autor;
}
void Noticia::agregarcomentario(Comentario _c){
    try{
        if (cantcomentario<20){
            comentarios[cantcomentario]= _c;
            cantcomentario++;
        }else{
            cout<<"Ya no se pueden cargar más comentarios."<<endl;
        }
    }catch(...){
        cout<<"Error al cargar el comentario"<<endl;
    }
}
void Noticia::mostrar() {
    cout << "TITULO: " << titulo << endl;
    cout << "DETALLE: " << detalle << endl;
    cout << "FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout << "AUTOR: "<<autor<< endl;
    
    cout << "***Comentarios***" << endl;
    for (int i = 0; i < cantcomentario; i++) {
        comentarios[i].mostrar();
    }
}
Noticia::~Noticia(){}