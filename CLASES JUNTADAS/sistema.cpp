#include "clases.h" // Se asume que ahora todas las cabeceras se incluyen desde "clases.h"

// Implementación de Persona
Persona::Persona(){
    dni=0;
    nombre="";
}

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
Persona::~Persona(){}


// Implementación de Comentario
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


// Implementación de Medio
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


// Implementación de Autor
Autor::Autor(){
    nombre = "";
    dni=0;
}
Autor::Autor(string n, int doc, string m):Persona(n, doc){
    nombre=n;
    dni=doc;
    medio=m;
}
Autor::~Autor(){}


// Implementación de Noticia
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


// Implementación de Usuario
Usuario::Usuario(){
    edad=0;
}
Usuario::Usuario(string _nombre, int _dni, int _edad):Persona(_nombre,_dni){
    edad=_edad;
}
Usuario::~Usuario(){}


// Implementación de Sistema
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
void Sistema::listarnoticiasanio(){
    try{
        if (contnoticia>0){
            int anio;
            cout<<"Elegir el año de la noticia buscada: "; cin>>anio;
            for (int i=0; i<contnoticia;i++){
                if (anio==noticias[i].getAnio()){
                    cout<<"Noticia encontrada"<<endl;
                    cout<<"FECHA: "<<noticias[i].getDia()<<"/"<<noticias[i].getMes()<<"/"<<noticias[i].getAnio()<<endl;
                    cout<<"TITULO: "<<noticias[i].getTitulo()<<endl;
                    cout<<"DETALLE: "<<noticias[i].getDetalle()<<endl;
                }
            }
        }else{
            cout<<"No hay noticias cargadas todavía."<<endl;
        }
    }catch(...){
        cout<<"Error al listar la noticia."<<endl;
    }
}
void Sistema::listarnoticiasmes(){
    try{
        int k=0;
        if (contnoticia>0){
            int mes, anio;
            cout<<"Mes actual: ";cin>>mes;
            while (mes>12 || mes<0){
                cout<<"Error, no existe ese mes. Cárguelo de nuevo: ";
                cin>>mes;
            }
            cout<<"Año actual: ";cin>>anio;
            while (anio>2025 || anio<0){
            cout<<"Año incorrecto, no pasó o es negativo. Cargue nuevamente: ";
            cin>>anio;
            }
            int mesanterior=mes-1;
            if (mesanterior=0){
                mesanterior=12;
                anio=anio-1;
            }for (int i=0; i<contnoticia;i++){
                if (noticias[i].getMes()==mesanterior && noticias[i].getAnio()==anio){
                    noticias[i].mostrar();
                    k++;
                }
            }
        }else{
            cout<<"No hay noticias cargadas todavía."<<endl;
        }if (k=0){
            cout<<"No se encontraron noticias en ese mes."<<endl;}
    }catch(...){
        cout<<"Error al encontrar noticia."<<endl;
    }
}
void Sistema::listarnoticiacomentario(){
    try{
        if (contnoticia>0){
                string titulo;
                cout<<"Indique el título de la noticia: ";
                cin>>titulo;
            for (int i=0; i<contnoticia; i++){
                if (noticias[i].getTitulo()==titulo){
                    noticias[i].mostrar();
                }
            }
        }else{
            cout<<"No hay noticias cargadas."<<endl;
        }
    }catch(...){
        cout<<"Error al cargar la noticia con comentarios.";
    }
}
void Sistema::listarnoticiaautor(){
    try{
        if (contnoticia>0){
            int p=0;
            string autor;
            cout<<"Diga el nombre del autor: ";cin>>autor;
            for (int i=0; i<contAutor; i++){
                if (noticias[i].getAutor()==autor){
                    noticias[i].mostrar();
                    p=p+1;
                }
            }if (p==0){
            cout<<"No se encontraron noticias del autor."<<endl;
        }}else{
            cout<<"No hay noticias registradas."<<endl;
        }
        
    }catch(...){
        cout<<"Error al encontrar al autor y su noticia."<<endl;
    }
}
Sistema::~Sistema(){}