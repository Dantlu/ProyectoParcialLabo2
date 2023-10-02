#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED
///PROTOTIPOS
void EstablecerDatosdeInicio();

void subMenuConfiguracion(){
int opc;

    while(true){
        system("cls");
        cout << "MENU CONFIGURACIONES" << endl;
        cout << "------------------" << endl;
        cout << "1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES" << endl;
        cout << "2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES" << endl;
        cout << "3) RESTAURAR EL ARCHIVO DE JUGADORES" << endl;
        cout << "4) RESTAURAR EL ARCHIVO DE DEPORTES" << endl;
        cout << "5) ESTABLECER DATOS DE INICIO" << endl;
        cout << "--------------------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl;
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
                    EstablecerDatosdeInicio();
                break;
            case 0:

                return;
            default:
                cout << "OPCION NO VALIDA, INTENTE DE NUEVO." << endl;
        }
        system("pause");
    }
}

void EstablecerDatosdeInicio{
    FILE* pJugadores;
    FILE* pJugadoresincio;

    pJugadores = fopen("jugadoresinicio.dat", "rb");
     if (pJugadores == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    pJugadoresincio = fopen("Jugadores.dat", "wb");
     if (pJugadoresincio == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    Jugadores jugador;
    while (fread(&jugador, sizeof(Jugador), 1, pJugadores) == 1) {
            if(jugador.getEstado()){
                fwrite(&jugador, sizeof(Jugador), 1, pJugadoresincio);
            }
    }
    fclose(pJugadores);
    fclose(pJugadoresincio);
    
    FILE* pD;
    FILE* pDI;

    pD = fopen("deportes.ini", "rb");
     if (pD == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    pDI = fopen("Deportes.dat", "wb");
     if (pDI == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    Deportes deporte;
    while (fread(&deporte, sizeof(deporte), 1, pD) == 1) {
            if(deporte.getEstado()){
                fwrite(&deporte, sizeof(deporte), 1, pDI);
            }
    }
    fclose(pD);
    fclose(pDI);
    
    cout << "Datos establecidos correctamente." << endl;
    
}


#endif // SUBMENUCONFIGURACION_H_INCLUDED
