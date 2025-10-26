#include "medio.h"

Medio::Medio(){
    nombremedio="";
}
Medio::Medio(string _nmedio){
    nombremedio=_nmedio;
}
void Medio::setNombremedio(string _nm){
    nombremedio=_nm;
}
string Medio::getNombre(){
    return nombremedio;
}
Medio::~Medio(){}