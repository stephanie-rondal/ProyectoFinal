#include "clases.h" 
#include <string>
#include <fstream>
#include <sstream>

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
    cout<<usuario<<": "<<texto<<endl;
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
    for(int i = 0; i < maxComentarios; i++) {
        comentarios[i] = Comentario();
    }
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
    for(int i = 0; i < maxComentarios; i++) {
        comentarios[i] = Comentario();
    }
    
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
        if (comentarios == nullptr) {
            cout << "ERROR: comentarios es NULL!" << endl;
            return;
        }
        if (cantcomentario < maxComentarios){
            comentarios[cantcomentario] = _c;
            cantcomentario++;
            cout << "DEBUG: Comentario agregado en posicion " << (cantcomentario-1) << endl;
        }else{
            cout<<"Ya no se pueden cargar más comentarios."<<endl;
        }
    }catch(...){
        cout<<"Error al cargar el comentario"<<endl;
    }
}

void Noticia::mostrar() {
    cout << " " <<endl;
    cout<< "TITULO: " << titulo << endl;
    cout << "DETALLE: " << detalle << endl;
    cout << "FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout << "AUTOR: "<<autor<< endl;
    
    cout << "***Comentarios***" << endl;
    if (cantcomentario != 0)
    {
        for (int i=0;i<cantcomentario;i++){
            comentarios[i].mostrar();
        }
    } else{
        cout << "No se han publicado comentarios." <<endl;
    }
}

int Noticia::cantComentarios(){
    return cantcomentario;
}

Noticia::~Noticia(){
    delete[] comentarios;
    comentarios=nullptr;
}


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
    
    // Leer los datos guardados en, hay que hacerlo recorriendo el arreglo 
    ifstream archivo("autores.txt");
    string nombre, medio;
    int dni;
    while (getline(archivo, nombre)) {
        archivo >> dni;
        archivo.ignore();
        getline(archivo, medio);
        autores[contAutor] = Autor(nombre, dni, medio);
        contAutor++;
    }
    archivo.close();

    ifstream archivo1("noticias.txt");
    string autor, cuerpo, titulo,fecha,trash;
    int dia,mes, anio;

    while (getline(archivo1, fecha)) {
        if (fecha.find('/') != string::npos) {
            stringstream ss(fecha);
            char separador;
            if (ss >> dia >> separador >> mes >> separador >> anio) {
                getline(archivo1, titulo);
                archivo1.ignore(); // Limpiar newline
                getline(archivo1, cuerpo);
                archivo1.ignore();
                getline(archivo1,trash);
                getline(archivo1, autor);
                archivo1.ignore(); // Limpiar newline
                
                if (contnoticia < maxNoticias) {
                    noticias[contnoticia] = Noticia(titulo, cuerpo, dia, mes, anio, autor);
                    contnoticia++;
                    cout << "DEBUG: Noticia asignada al array" << endl;
                }
            }
        }
    }
    archivo1.close();

    ifstream archivo2("usuarios.txt");
    int edad;
    while (getline(archivo2, nombre)) {
        archivo2 >> dni;
        archivo2 >> edad;
        archivo.ignore();
        usuarios[contUsuario]= Usuario(nombre,dni,edad);
        contUsuario++;
    }
    archivo2.close();

    ifstream archivo3("comentarios.txt");
    string texto, usuario;
    int lineCount = 0,x=0;;

    while (getline(archivo3, titulo)) {
        getline(archivo3, texto);   // Segunda línea: texto del comentario
        getline(archivo3, usuario); // Tercera línea: usuario
        for (int i = 0; i < contnoticia; i++) {
            if (noticias[i].getTitulo() == titulo) {
                Comentario c(noticias[i].cantComentarios(), texto, usuario);
                noticias[i].agregarcomentario(c);
                break;
            }
        }
        lineCount+=3;
    }
    archivo3.close();
}

void Sistema::registrarAutor(){
    try{
        if (contAutor < maxAutores){
            int dni;
            string nom, med;

            cout << "--------- Ingrese los siguientes datos -------- "<< endl;
            cout<<"Nombre: "; 
            cin.ignore(); // para poder usar getline
            getline(cin, nom); // getline es un método de la libreria estandar que estamos usando (iostream), así se puede leer la cadena ingresada aunque tenga espacios
            cout<<"DNI: "; cin>>dni;
            cout<<"Medio: "; 
            cin.ignore(); getline(cin, med);
            autores[contAutor]=Autor(nom, dni, med);
            contAutor++;

            // Guardar los datos en el archivo autores.txt
            ofstream archivo("autores.txt", ios::app); 
            archivo << nom <<endl;
            archivo << dni <<endl;
            archivo << med <<endl;
            archivo.close();
            
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
        if (contUsuario < maxUsuarios){
            int dni, edad;
            string nom;

            cout << "--------- Ingrese los siguientes datos -------- "<< endl;
            cout<<"Nombre: "; 
            cin.ignore(); getline(cin, nom);
            cout<<"DNI: "; cin>>dni;
            cout<<"Edad : ";cin>>edad;
            usuarios[contUsuario]=Usuario(nom, dni, edad);
            contUsuario++;

            // Guardar los datos en el archivo usuarios.txt
            ofstream archivo2("usuarios.txt", ios::app); 
            archivo2 << nom <<endl;
            archivo2 << dni <<endl;
            archivo2 << edad <<endl;
            archivo2 << endl;
            archivo2.close();
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
        if (contAutor > 0 && contnoticia < maxNoticias){
            string titulo, detalle, autor, medio;
            int dia, mes, anio,t=0;
            
            cout<<"----------- Cargue los siguientes datos de la noticia -----------"<<endl;
            cin.ignore();
            cout<<"Titulo: "; getline(cin, titulo);
            cout<<"Detalle de la noticia: "; getline(cin, detalle);
            cout<<"Autor de la noticia: "; getline(cin, autor);
            cout<<"Fecha (uno a uno ingrese los valores: dia mes anio): "; cin >> dia >> mes >>anio; // Se pueden cargar de una pq el metodo cin lee las cadenas y para de leer cuando hay espacios
            //Buscar autor
            while (t<contAutor && autor!=autores[t].getNombre()){
                t++;
            }
            if (t<contAutor){
                //Crear noticia
                noticias[contnoticia] = Noticia();
                noticias[contnoticia].setTitulo(titulo);
                noticias[contnoticia].setDetalle(detalle);
                noticias[contnoticia].setDia(dia);
                noticias[contnoticia].setMes(mes);
                noticias[contnoticia].setAnio(anio);
                noticias[contnoticia].setAutor(autor);
                contnoticia++;

                // Guardar los datos en el archivo noticias.txt
                ofstream archivo("noticias.txt", ios::app);
                //archivo <<;
                archivo << dia << "/" << mes<< "/"<< anio <<endl; 
                archivo <<titulo<<endl<<endl;
                archivo << detalle <<endl<<endl;
                archivo << "Redactado por: "<<endl << autor <<endl<<endl;
                archivo.close();
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
                cout<<"DEBUG: noticia encontrada en indice: "<< i << endl;

                cout<<"Nombre de usuario que comenta: "; getline(cin, usuario);            
                // Buscar usuario
                while (j < contUsuario && usuarios[j].getNombre()!=usuario){
                    j++;
                }

                cout << "DEBUG: Usuario encontrado en indice: " << j << endl;

                if (j < contUsuario){
                    cout<<"Comentario a publicar: "; getline(cin, texto);
                

                    cout << "DEBUG: Creando comentario..." << endl;
                    
                    Comentario c(i+1, texto, usuario);
                    
                    cout << "DEBUG: Agregando comentario a noticia..." << endl;
                    
                    noticias[i].agregarcomentario(c);
                    
                    cout << "DEBUG: Comentario agregado exitosamente" << endl;
                    // Guardar los datos en el archivo autores.txt
                    ofstream archivo("comentarios.txt", ios::app); 
                    //archivo << numero <<endl;
                    archivo << titulo<<endl;
                    archivo << texto <<endl;
                    archivo << usuario <<endl;
                    archivo.close();

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
        bool bandera=false;
        int anio;
        if (contnoticia > 0){
            cout<<"Ingrese el anio: "; cin>>anio;
            for (int i=0; i< contnoticia; i++){
                if (anio == noticias[i].getAnio()){
                    cout<<"Noticia encontrada"<<endl;
                    noticias[i].mostrar();
                    bandera=true;
                }
            }
            if (bandera==false){
                cout<<"No se encontraron noticias en el año cargado."<<endl;
            }
        }else{
            cout<<"No se han encontrado noticias publicadas."<<endl;
        }
    }catch(...){
        cout<<"Error al listar la noticia."<<endl;
    }
}

void Sistema::listarnoticiasmes(){
    try{
        bool bandera=false;
        if (contnoticia>0){
            int mes, anio;
            cout<<"Mes actual: ";
            cin>>mes;
            while (mes>12 || mes<1){
                cout<<"Error, no existe ese mes. Cárguelo de nuevo: ";
                cin>>mes;
            }
            if(mes==1){
                mes=12;
            }
            cout<<"Anio actual: ";cin>>anio;
            while (anio>2025 || anio<1980){
            cout<<"Año incorrecto, no pasó o es negativo. Cargue nuevamente: ";
            cin>>anio;
            }
            int mesanterior=mes-1;
            if (mesanterior==0){
                mesanterior=12;
                anio=anio-1;
            }for (int i=0; i<contnoticia;i++){
                if (noticias[i].getMes()==mesanterior && noticias[i].getAnio()==anio){
                    noticias[i].mostrar();
                    bandera = true;
                }
            }
        }else{
            cout<<"No se han cargado noticias."<<endl;
        }if (bandera==false){
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
            for (int i=0; i<contnoticia; i++){
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
    delete[] autores;
    delete[] usuarios;
    delete[] noticias;
    noticias = nullptr;
    autores = nullptr;
    usuarios = nullptr;
}