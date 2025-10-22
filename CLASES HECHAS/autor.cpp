#include "autor.h"

Autor::Autor(){
    nombre = "";
    dni=0;
}
Autor::Autor(string n, int doc, string m):Persona(n, doc){
    nombre=n;
    dni=doc;
    medio=m;
}