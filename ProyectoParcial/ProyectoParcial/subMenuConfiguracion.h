#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED


void subMenuConfiguracion(){
int opc;

    while(true){
        system("cls");
        cout << "MENÚ CONFIGURACIÓN" << endl;
        cout << "------------------" << endl;
        cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES" << endl;
        cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES" << endl;
        cout << "3) RESTAURAR EL ARCHIVO DE JUGADORES" << endl;
        cout << "4) RESTAURAR EL ARCHIVO DE DEPORTES" << endl;
        cout << "5) ESTABLECER DATOS DE INICIO" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opc;
        system("cls");

        switch(opc) {
            case 1:
                    agregarRegistroDeportes();
                break;
            case 2:
                    buscarPorID();
                break;
            case 3:
                    mostrarDeportes();
                break;
            case 4:
                    CambiarFechaDeporte();
                break;
            case 5:
                    bajaLogicaDeportes();
                break;
            case 0:

                return;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
        system("pause");
    }
}




#endif // SUBMENUCONFIGURACION_H_INCLUDED
