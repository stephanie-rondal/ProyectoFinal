#include <iostream>
#include "clases.h"
using namespace std;
int main() {
    Sistema sistema;
    int opcion=1;
    while (opcion!=0) {
        
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
        try {
            if (opcion==1) {sistema.registrarAutor();
            }else if (opcion==2) {
                sistema.registrarUsuario();
            }else if (opcion==3){
                sistema.registrarNoticia();
            }else if (opcion==4){
                sistema.registrarComentario();
            }else if (opcion==5) {
                sistema.listarnoticiasanio();
            }else if (opcion==6){
                sistema.listarnoticiasmes();
            }else if(opcion==7){
                sistema.listarnoticiacomentario();
            }else if(opcion==8){
                sistema.listarnoticiaautor();
            }
            else if (opcion!=0) cout << "Opcion no valida."<<endl;
        } catch (...) {
            cout << "Error en el menú."<<endl;
        }
    }
}