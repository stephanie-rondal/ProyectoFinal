#include "comentario.h"

Comentario::Comentario(){
    numero=0;
    texto="";
    usuario="";
}
Comentario::Comentario(int _numero,string _texto, string _usuario){
    numero=_numero;
    texto=_texto;
    usuario = _usuario;
}
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
void Comentario::mostrar() {
    cout<<"Comentario "<<numero<<": "<<texto<<endl<<"Usuario: "<<usuario<<endl;
}
Comentario::~Comentario(){}
