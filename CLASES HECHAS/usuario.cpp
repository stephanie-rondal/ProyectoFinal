#include "usuario.h"

Usuario::Usuario(){
    edad=0;
}
Usuario::Usuario(string _nombre, int _dni, int _edad):Persona(_nombre,_dni){
    edad=_edad;
}