#include "autor.h"

Autor::Autor(){
    nombre = "";
    dni=0;
}

void Autor::registrarNoticia(){
    try{
        Sistema *p;
        if (p->getcontAutor()>0 && p->getcontnoticia()<20){
            string titulo, detalle, autor;
            int dia, mes, anio, t=0;
            cout<<"----------- Cargar datos de la noticia. -----------"<<endl;
            cout<<"Día: ";cin>>dia;
            cout<<"Mes: ";cin>>mes;
            cout<<"Año: ";cin>>anio;
            cout<<"Título: ";cin>>titulo;
            cout<<"Detalle de la noticia: ";cin>>detalle;
            cout<<"Autor de la noticia: "; cin>>autor;
            while (t<p->getcontAutor() && autor!=autores[t].getNombre()){
                t++;
            }
            if (t<contAutor){
                noticias[contnoticia] = Noticia(titulo, detalle, dia, mes, anio, autor);
                contnoticia++;
            }else{
                cout<<"No se ha encontrado al autor."<<endl;
            }
        }else{
            cout<<"No hay autores registrados o la cantidad de noticias está llena."<<endl;
        }
    }catch(...){
        cout<<"Error al cargar la NOTICIA.";
    }
}

Autor::Autor(string n, int doc, string m):Persona(n, doc){
    nombre=n;
    dni=doc;
    medio=m;
}
Autor::~Autor(){}