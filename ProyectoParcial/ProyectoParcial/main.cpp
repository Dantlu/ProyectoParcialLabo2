/*
INTEGRANTES:
Tomas Emanuel Munguia
Daniel Martin Rios
Dante Luongo
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#include "FuncionesGlobales.h"
#include "clsJugadores.h"
#include "SubMenuJugadores.h"
#include "clsDeportes.h"
#include "subMenuDeportes.h"
#include "Reportes.h"
#include "subMenuConfiguracion.h"

int main() {
    int opc;
    while (true) {

        system("cls");
        cout << "MENU PRINCIPAL " << endl;
        cout << "------------------" << endl;
        cout << "1) MENU JUGADORES" << endl;
        cout << "2) MENU DEPORTES" << endl;
        cout << "3) REPORTES" << endl;
        cout << "4) CONFIGURACION" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) FIN DEL PROGRAMA" << endl;

        cout << "SELECCIONE UNA DE LAS OPCIONES: " << endl;
        cin >> opc;
        system("cls");
        switch (opc) {
        case 1:
            subMenuJugadores();
            break;
        case 2:
            subMenuDeportes();
            break;
        case 3:
            subMenuReportes();
            break;
        case 4:
            subMenuConfiguracion();
            break;
        case 0:
            return 0;
            break;
        default:
            cout << "OPCION INCORRECTA" << endl;
            break;
        }

        system("pause");
    }
    return 0;
}
