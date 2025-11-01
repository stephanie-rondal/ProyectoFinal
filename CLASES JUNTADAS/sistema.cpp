#include "clases.h" 

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
void Comentario::setUsuario(string u){
    usuario = u;
}
int Comentario::getNumero(){
    return numero;
}
string Comentario::getTexto(){
    return texto;
}
string Comentario::getUsuario(){
    return usuario;
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
Autor::Autor() : Persona(), medio(""){ //Se llama a los contrcutores de persona y medio, 
}
Autor::Autor(string n, int doc, string m):Persona(n, doc), medio(m){; //Se llama a los contrctores parametrizados
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
        //Redefiní los contructores creando un arreglo dinámico
    maxComentarios = 20;  //Valor que podemos cambiar
    comentarios = new Comentario[maxComentarios]; // La capacidad máxima nos sirve para el manejo de excepciones
}

Noticia::Noticia(string _titulo,string _detalle,int _dia,int _mes,int _anio,string _autor){
    titulo=_titulo;
    detalle=_detalle;
    dia=_dia;
    mes=_mes;
    anio=_anio;
    autor=_autor;
    cantcomentario=0;
    maxComentarios = 20; 
    comentarios = new Comentario[maxComentarios];
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
        if (cantcomentario <= maxComentarios){
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
    if (cantcomentario != 0)
    {
        for (int i = 0; i < cantcomentario; i++) {
        comentarios[i].mostrar();
        }
    } else{
        cout << "No se han publicado comentarios." <<endl;
    }
}
Noticia::~Noticia(){}


// Implementación de Usuario
Usuario::Usuario():Persona(){
    edad=0;
}
Usuario::Usuario(string _nombre, int _dni, int _edad):Persona(_nombre,_dni){
    edad=_edad;
}
Usuario::~Usuario(){}


// Implementación de Sistema
Sistema::Sistema(){
    contAutor = contUsuario = contnoticia = 0;
    maxAutores = maxUsuarios= maxNoticias = 20; // Puse un valor arbitrario para poder crear los arreglos dinámicos
    autores = new Autor[maxAutores];
    usuarios = new Usuario[maxUsuarios];
    noticias = new Noticia[maxNoticias];
}
Sistema::Sistema(int _autor,int _usuario,int _noti){
    contAutor=_autor;
    contUsuario=_usuario;
    contnoticia=_noti;
    maxAutores = maxUsuarios= maxNoticias = 20;
    autores = new Autor[maxAutores];
    usuarios = new Usuario[maxUsuarios];
    noticias = new Noticia[maxNoticias];
}

void Sistema::registrarAutor(){
    try{
        if (contAutor <= maxAutores){
            int dni;
            string nom, med;

            cout << "--------- Ingrese los siguientes datos -------- "<< endl;
            cout<<"Nombre: "; 
            cin.ignore(); // para poder usar getline
            getline(cin, nom); // getline es un método de la libreria estandar que estamos usando (iostream), así se puede leer la cadena ingresada aunque tenga espacios
            cout<<"DNI: "; cin>>dni;
            cout<<"Medio: "; 
            cin.ignore(); getline(cin, med); //cin>>med;
            autores[contAutor]=Autor(nom, dni, med);
            contAutor++;
            cout << "Se ha registrado correctamente" << endl;

        }else{
            cout<<"La cantidad de AUTORES está llena. No se cargará su usuario.";
        }
    }catch (...){
        cout<<"Error al registrar AUTOR.";
    }
}

void Sistema::registrarUsuario(){
    try{
        if (contUsuario <= maxUsuarios){
            int dni, edad;
            string nom;

            cout << "--------- Ingrese los siguientes datos -------- "<< endl;
            cout<<"Nombre: "; 
            cin.ignore(); getline(cin, nom);
            cout<<"DNI: "; cin>>dni;
            cout<<"Edad : ";cin>>edad;
            usuarios[contUsuario]=Usuario(nom, dni, edad);
            contUsuario++;
            cout << "Se ha registrado correctamente" << endl;

        }else{
            cout<<"La cantidad de USUARIOS está llena. No se cargará su usuario.";
        }
    }catch (...){
        cout<<"Error al registrar USUARIO.";
    }   
}

void Sistema::registrarNoticia(){
    try{
        if (contAutor > 0 && contnoticia <= maxNoticias){
            string titulo, detalle, autor;
            int dia, mes, anio, t = 0;
            
            cout<<"----------- Cargue los siguientes datos de la noticia -----------"<<endl;
            cin.ignore();
            cout<<"Titulo: "; getline(cin, titulo);
            cout<<"Detalle de la noticia: "; getline(cin, detalle);
            cout<<"Autor de la noticia: "; getline(cin, autor);
            cout<<"Fecha (en este formato: dia mes anio):"; cin >> dia >> mes >>anio; // Se pueden cargar de una pq el metodo cin lee las cadenas y para de leer cuando hay un espacios
            
            //Buscar autor
            while (t<contAutor && autor!=autores[t].getNombre()){
                t++;
            }
            if (t<contAutor){
                //Crear noticia
                noticias[contnoticia] = Noticia(titulo, detalle, dia, mes, anio, autor);
                contnoticia++;
                cout << "La noticia se ha resgitrado correctamente." << endl;
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
            
            cout<<"----------- Cargue los siguientes datos -----------"<<endl;
            cin.ignore();
            cout<<"Titulo de la noticia a comentar: "; getline(cin, titulo);
            // Buscar noticia
            while (i < contnoticia && noticias[i].getTitulo()!=titulo){
                i++;
            }

            if (i < contnoticia){
                cout<<"Nombre de usuario que comenta: "; getline(cin, usuario);            
                // Buscar usuario
                while (j < contUsuario && usuarios[j].getNombre()!=usuario){
                    j++;
                }

                if (j < contUsuario){
                    cout<<"Comentario a publicar: "; getline(cin, texto);
                    //Crear comentario y agregarlo a la noticia
                    Comentario c(i+1, texto, usuario);
                    noticias[i].agregarcomentario(c);
                    cout << "El comentario se ha publicado corectamente."<<endl;
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
        int anio;
        if (contnoticia > 0){
            cout<<"Ingrese el anio: "; cin>>anio;
            for (int i=0; i< contnoticia; i++){
                if (anio == noticias[i].getAnio()){
                    cout<<"Noticia encontrada"<<endl;
                    noticias[i].mostrar();
                }
            }
        }else{
            cout<<"No se han encontrado noticias publicadas en "<< anio <<endl;
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
            cout<<"No se han cargado noticias."<<endl;
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
            cout<<"Indique el titulo de la noticia: ";
            cin.ignore();
            getline(cin, titulo);
            for (int i=0; i<contnoticia; i++){
                if (noticias[i].getTitulo()==titulo){
                    noticias[i].mostrar();
                }
            }
        }else{
            cout<<"No se han cargado noticias."<<endl;
        }
    }catch(...){
        cout<<"Error al cargar la noticia con comentarios.";
    }
}

void Sistema::listarnoticiaautor(){
    try{
        if (contnoticia>0){
            string autor;
            bool bandera = false;
            cout<<"Indique el nombre del autor: ";
            cin.ignore();
            getline(cin, autor);
            for (int i=0; i<contAutor; i++){
                if (noticias[i].getAutor()==autor){
                    noticias[i].mostrar();
                    bandera = true;
                }
            }if (bandera == false){
            cout<<"No se han encontrado noticias del autor."<<endl;
            }
        }else{
            cout<<"No se han cargado noticias."<<endl;
        }    
    }catch(...){
        cout<<"Error al encontrar al autor y su noticia."<<endl;
    }
}

Sistema::~Sistema(){
    //Para borrar el espacios dinámico usado por los arreglos
    delete[] autores;
    delete[] usuarios;
    delete[] noticias;
    noticias = nullptr;
    autores = nullptr;
    usuarios = nullptr;
}