#include <iostream>
#include "sistemas.h"
using namespace std;
int main() {
    Sistema sistema;
    int opcion=1;
    while (opcion!=0) {
        try {
            cout<<endl<<"--- MENU ---"<<endl;
            cout<<"1. Registrar autor"<<endl;
            cout<<"2. Registrar usuario"<<endl;
            cout<<"3. Publicar noticia"<<endl;
            cout<<"4. Comentar noticia"<<endl;
            cout<<"5. Listar noticias por año"<<endl;
            cout<<"6. Mostrar noticia del último mes"<<endl;
            cout<<"7. Mostrar noticia con comentarios"<<endl;
            cout<<"8. Mostrar noticia por un determinado autor"<<endl;
            cout<<"0. Salir"<<endl;
            cout<<"Opcion: "<<endl;
            cin >> opcion;
            if (opcion==1) {sistema.registrarAutor();
            }else if (opcion==2) {
                sistema.registrarUsuario();
            }else if (opcion==3){
                sistema.registrarNoticia();
            }else if (opcion==4){
                sistema.registrarComentario();
            }else if (opcion==5) {
                int anio;
                cout<<"Elegir el año de la noticia buscada: "; cin>>anio;
                sistema.listarnoticiasanio(anio);
            }else if (opcion==6){
                int mes, anio;
                    cout<<"Mes actual: ";cin>>mes;
                    while (mes>12 || mes<0){
                        cout<<"Error, no existe ese mes. Cárguelo de nuevo: ";
                        cin>>mes;
                    }
                    cout<<"Año actual: ";cin>>anio;
                    while (anio>2025 && anio<0){
                        cout<<"Año incorrecto, no pasó o es negativo. Cargue nuevamente: ";
                        cin>>anio;
                    }
                sistema.listarnoticiasmes(mes, anio);
            }else if(opcion==7){
                string titulo;
                cout<<"Indique el título de la noticia: ";
                cin>>titulo;
                sistema.listarnoticiacomentario(titulo);
            }else if(opcion==8){
                    string nombreautor;
                    cout<<"Elegir autor de la noticia buscada: "; cin>>nombreautor;
                sistema.listarnoticiaautor(nombreautor);
            }
            else if (opcion!=0) cout << "Opcion no valida."<<endl;
        } catch (...) {
            cout << "Error en el menú."<<endl;
        }
    }
}