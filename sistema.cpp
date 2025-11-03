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
    cout<<usuario<<": "<<texto<<endl;
}
Comentario::~Comentario(){}


// Implementación de Medio
/*Medio::Medio(){
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
Medio::~Medio(){}*/


// Implementación de Autor
Autor::Autor() : Persona(), medio(""){ //Se llama a los contrcutores de persona y medio, 
}
Autor::Autor(string n, int doc, string m):Persona(n, doc), medio(m){; //Se llama a los contrctores parametrizados
}
string Autor::getMedio(){
    return medio;
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
    //cantcomentario=0;
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
    //cantcomentario=0;
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
int Usuario::getEdad(){
    return edad;
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
            if (autorRegistrado(nom)) {
            cout << "El autor ya esta registrado." << endl;
                return;
            }
            cout<<"DNI: "; cin>>dni;
            cout<<"Medio: "; 
            cin.ignore(); getline(cin, med);
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
            if (usuarioRegistrado(nom)) {
                cout << "El usuario ya esta registrado." << endl;
                return;
            }
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
            if (noticiaRegistrada(titulo)){
                cout << "Ya existe una noticia con ese titulo." << endl;
                return;
            }
            cout<<"Detalle de la noticia: "; getline(cin, detalle);
            cout<<"Autor de la noticia: "; getline(cin, autor);
            cout<<"Fecha (en este formato: dia mes anio): "; cin >> dia >> mes >>anio; // Se pueden cargar de una pq el metodo cin lee las cadenas y para de leer cuando hay un espacios
            
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
            if (comentarioExistente(titulo, usuario)) {
                cout << "Este usuario ya comento esta noticia." << endl;
                return;
}

            // Buscar noticia
            while (i<contnoticia && noticias[i].getTitulo()!=titulo){
                i++;
            }

            if (i<contnoticia){
                cout<<"Nombre de usuario que comenta: "; getline(cin, usuario);            
                // Buscar usuario
                while (j < contUsuario && usuarios[j].getNombre()!=usuario){
                    j++;
                }

                if (j<contUsuario){
                    cout<<"Comentario a publicar: "; getline(cin, texto);
                    //Crear comentario y agregarlo a la noticia
                    Comentario c(i+1, texto, usuario);
                    noticias[i].agregarcomentario(c);
                    cout << "El comentario se ha publicado crectamente."<<endl;
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
            while (mes>12 || mes<0){
                cout<<"Error, no existe ese mes. Cárguelo de nuevo: ";
                cin>>mes;
            }
            cout<<"Anio actual: ";cin>>anio;
            while (anio>2025 || anio<1980){
            cout<<"Año incorrecto. No pasó o es muy viejo. Cargue nuevamente: ";
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

// ==========================
// CARGAR DESDE ARCHIVOS
// ==========================
void Sistema::cargarDesdeArchivos() {
    // ----- AUTORES -----
    ifstream archA("autores.txt");
    string linea;
    while (getline(archA, linea)) {
        int p1 = linea.find('|');
        int p2 = linea.find('|', p1 + 1);
        string nom = linea.substr(0, p1);
        int dni = stoi(linea.substr(p1 + 1, p2 - p1 - 1));
        string med = linea.substr(p2 + 1);
        autores[contAutor] = Autor(nom, dni, med);
        contAutor++;
    }
    archA.close();

    // ----- USUARIOS -----
    ifstream archU("usuarios.txt");
    while (getline(archU, linea)) {
        int p1 = linea.find('|');
        int p2 = linea.find('|', p1 + 1);
        string nom = linea.substr(0, p1);
        int dni = stoi(linea.substr(p1 + 1, p2 - p1 - 1));
        int edad = stoi(linea.substr(p2 + 1));
        usuarios[contUsuario] = Usuario(nom, dni, edad);
        contUsuario++;
    }
    archU.close();

    // ----- NOTICIAS -----
    ifstream archN("noticias.txt");
    while (getline(archN, linea)) {
        int p1 = linea.find('|');
        int p2 = linea.find('|', p1 + 1);
        int p3 = linea.find('|', p2 + 1);
        int p4 = linea.find('|', p3 + 1);
        int p5 = linea.find('|', p4 + 1);

        string titulo = linea.substr(0, p1);
        string detalle = linea.substr(p1 + 1, p2 - p1 - 1);
        int dia = stoi(linea.substr(p2 + 1, p3 - p2 - 1));
        int mes = stoi(linea.substr(p3 + 1, p4 - p3 - 1));
        int anio = stoi(linea.substr(p4 + 1, p5 - p4 - 1));
        string autor = linea.substr(p5 + 1);

        noticias[contnoticia] = Noticia(titulo, detalle, dia, mes, anio, autor);
        contnoticia++;
    }
    archN.close();
}

// ==========================
// GUARDAR TODO
// ==========================
void Sistema::guardarTodo() {
    // Guardar autores
    ofstream archA("autores.txt");
    for (int i=0; i<contAutor; i++) {
        archA <<autores[i].getNombre()<<"|"
              <<autores[i].getDni()<<"|"
              <<autores[i].getMedio()<<endl;
    }
    archA.close();

    // Guardar usuarios
    ofstream archU("usuarios.txt");
    for (int i = 0; i < contUsuario; i++) {
        archU << usuarios[i].getNombre() << "|"
              << usuarios[i].getDni() << "|"
              << usuarios[i].getEdad() << endl;
    }
    archU.close();

    // Guardar noticias
    ofstream archN("noticias.txt");
    for (int i=0; i<contnoticia; i++) {
        archN << noticias[i].getTitulo() << "|"
              << noticias[i].getDetalle() << "|"
              << noticias[i].getDia() << "|"
              << noticias[i].getMes() << "|"
              << noticias[i].getAnio() << "|"
              << noticias[i].getAutor() << endl;
    }
    archN.close();
} 

bool Sistema::autorRegistrado(string nombreBuscado) {
    ifstream arch("autores.txt");
    string linea;
    while (getline(arch, linea)) {
        int pos = linea.find('|');
        string nombre = linea.substr(0, pos);
        if (nombre == nombreBuscado) {
            arch.close();
            return true;
        }
    }
    arch.close();
    return false;
}

bool Sistema::usuarioRegistrado(string nombreBuscado) {
    ifstream arch("usuarios.txt");
    string linea;
    while (getline(arch, linea)) {
        int pos = linea.find('|');
        string nombre = linea.substr(0, pos);
        if (nombre == nombreBuscado) {
            arch.close();
            return true;
        }
    }
    arch.close();
    return false;
}

bool Sistema::noticiaRegistrada(string tituloBuscado) {
    ifstream arch("noticias.txt");
    string linea;
    while (getline(arch, linea)) {
        int pos = linea.find('|');
        string titulo = linea.substr(0, pos);
        if (titulo == tituloBuscado) {
            arch.close();
            return true;
        }
    }
    arch.close();
    return false;
}

bool Sistema::comentarioExistente(string tituloBuscado, string usuarioBuscado) {
    ifstream arch("comentarios.txt");
    string linea;
    while (getline(arch, linea)) {
        int p1=linea.find('|');
        int p2=linea.find('|', p1 + 1);

        string titulo=linea.substr(0, p1);
        string usuario=linea.substr(p1 + 1, p2 - p1 - 1);

        if (titulo==tituloBuscado && usuario==usuarioBuscado) {
            arch.close();
            return true;
        }
    }
    arch.close();
    return false;
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