#ifndef SUBMENUREPORTES_H_INCLUDED
#define SUBMENUREPORTES_H_INCLUDED
#include <iostream>
#include <cstdlib>

using namespace std;

void subMenuReportes();
void punto1();
void punto2();
void punto3();

void subMenuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU REPORTES" << endl;
        cout << "------------------" << endl;
        cout << "1) PUNTO 1" << endl;
        cout << "2) PUNTO 2" << endl;
        cout << "3) PUNTO 3" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opc;
        system("cls");

        switch(opc) {
            case 1:
                    punto1();
                break;
            case 2:
                    punto2();
                break;
            case 3:
                    punto3();
                break;
            case 0:
                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
        system("pause");
    }
}

void punto1() {
    //   punto1
}

void punto2() {
    //  punto2
}

void punto3() {
    //  punto3
}


#endif // SUBMENUREPORTES_H_INCLUDED
