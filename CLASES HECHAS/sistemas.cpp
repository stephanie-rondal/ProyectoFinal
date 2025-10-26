#include "sistemas.h"

Sistema::Sistema(){
    contAutor=0;
    contUsuario=0;
    contnoticia=0;
}
Sistema::Sistema(int _autor,int _usuario,int _noti){
    contAutor=_autor;
    contUsuario=_usuario;
    contnoticia=_noti;
}
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
            string titulo, detalle, autor;
            int dia, mes, anio, t;
            cout<<"----------- Cargar datos de la noticia. -----------"<<endl;
            cout<<"Día: ";cin>>dia;
            cout<<"Mes: ";cin>>mes;
            cout<<"Año: ";cin>>anio;
            cout<<"Título: ";cin>>titulo;
            cout<<"Detalle de la noticia: ";cin>>detalle;
            cout<<"Autor de la noticia: "; cin>>autor;
            while (t<contAutor && autor!=autores[t].getNombre()){
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
void Sistema::registrarComentario(){
    try{
        if (contnoticia>0 && contUsuario>0){
            int i=0, j=0;
            string texto, usuario, titulo;
            cout<<"Título de noticia para comentar: "; cin>>titulo;
            while (i<contnoticia && noticias[i].getTitulo()!=titulo){
                i++;
            }
            if (i<contnoticia){
                cout<<"Nombre de usuario que comenta: ";cin>>usuario;            
                while (j<contUsuario && usuarios[j].getNombre()!=usuario){
                    j++;
                }
                if (j<contUsuario){
                    cout<<"Comentario: "; cin>>texto;
                    Comentario c(i+1, texto, usuario);
                    noticias[i].agregarcomentario(c);
                }else{
                    cout<<"Usuario no registrado."<<endl;
                }   
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
void Sistema::listarnoticiasanio(int e){
    try{
        for (int i=0; i<contnoticia;i++){
            if (e==noticias[i].getAnio()){
                cout<<"Noticia encontrada"<<endl;
                cout<<"FECHA: "<<noticias[i].getDia()<<"/"<<noticias[i].getMes()<<"/"<<noticias[i].getAnio()<<endl;
                cout<<"TITULO: "<<noticias[i].getTitulo()<<endl;
                cout<<"DETALLE: "<<noticias[i].getDetalle()<<endl;
            }
        }
    }catch(...){
        cout<<"Error al listar la noticia."<<endl;
    }
}
void Sistema::listarnoticiasmes(int mes, int anio){
    try{
        int mesanterior=mes-1, k=0;
        if (mesanterior=0){
            mesanterior=12;
            anio=anio-1;
        }for (int i=0; i<contnoticia;i++){
            if (noticias[i].getMes()==mesanterior && noticias[i].getAnio()==anio){
                cout<<"FECHA: "<<noticias[i].getDia()<<"/"<<noticias[i].getMes()<<"/"<<noticias[i].getAnio()<<endl;
                cout<<"TITULO: "<<noticias[i].getTitulo()<<endl;
                cout<<"DETALLE: "<<noticias[i].getDetalle()<<endl;
                k++;
            }
        }if (k=0){
            cout<<"No se encontraron noticias en ese mes."<<endl;
        }
    }catch(...){
        cout<<"Error al encontrar noticia."<<endl;
    }
}
void Sistema::listarnoticiacomentario(string tit){
    try{
        if (contnoticia>0){
            for (int i=0; i<contnoticia; i++){
                if (noticias[i].getTitulo()==tit){
                    noticias[i].mostrar();
                }
            }
        }
    }catch(...){
        cout<<"Error al cargar la noticia con comentarios.";
    }
}
void Sistema::listarnoticiaautor(string a){
    try{
        int p=0;
        while (p<contAutor){
            p++;
        }
        if (p<contAutor){
            for (int e=0; e<contAutor;e++){
            if (noticias[e].getAutor()==a){
                noticias[e].mostrar();
            }}
        }else{
                cout<<"No se han encontrado los autores."<<endl;
    }}catch(...){
        cout<<"Error al encontrar al autor y su noticia."<<endl;
    }
}
Sistema::~Sistema(){}


