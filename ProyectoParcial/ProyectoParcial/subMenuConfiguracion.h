#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED
///PROTOTIPOS
void subMenuConfiguracion();
void EstablecerDatosdeInicio();
void CopiaDeDeguridadJugadores();
void CopiaDeDeguridadDeportes();
void restaurarJugadores();
void restaurarDeportes();
///FIN

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
                    CopiaDeDeguridadJugadores();
                break;
            case 2:
                    CopiaDeDeguridadDeportes();
                break;
            case 3:
                    restaurarJugadores();
                break;
            case 4:
                    restaurarDeportes();
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


void CopiaDeDeguridadJugadores(){
    FILE* pJugadores;
    FILE* pJugadoresBackup;

    pJugadores = fopen("Jugadores.dat", "rb");
     if (pJugadores == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    pJugadoresBackup = fopen("jugadores_backup.bak", "wb");
     if (pJugadoresBackup == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    Jugadores jugador;
    while (fread(&jugador, sizeof(jugador), 1, pJugadores) == 1) {
            if(jugador.getEstado()){
                fwrite(&jugador, sizeof(Jugadores), 1, pJugadoresBackup);
            }
    }
    fclose(pJugadores);
    fclose(pJugadoresBackup);
    cout << "Copia de seguridad de jugadores realizada correctamente." << endl;

}

void CopiaDeDeguridadDeportes(){
    FILE* pDeportes;
    FILE* pDeportesBackup;

    pDeportes = fopen("Deportes.dat", "rb");
     if (pDeportes == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    pDeportesBackup = fopen("Deportes_backup.bak", "wb");
     if (pDeportesBackup == NULL) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }
    Deportes deporte;
    while (fread(&deporte, sizeof(Deportes), 1, pDeportes) == 1) {
            if(deporte.getEstado()){
                fwrite(&deporte, sizeof(Deportes), 1, pDeportesBackup);
            }
    }
    fclose(pDeportes);
    fclose(pDeportesBackup);
    cout << "Copia de seguridad de Deportes realizada correctamente." << endl;

}


void restaurarJugadores(){
    FILE *pJugadores;
    FILE *pJugadoresBackup;
    pJugadoresBackup = fopen("jugadores_backup.bak", "rb");
    if (pJugadoresBackup == NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }
    pJugadores = fopen("Jugadores.dat","wb");
    if(pJugadores==NULL){
        cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        return;
    }
    Jugadores jugador;
    while(fread(&jugador,sizeof(Jugadores),1, pJugadoresBackup)==1){
        fwrite(&jugador,sizeof(Jugadores),1,pJugadores);
    }
    fclose(pJugadoresBackup);
    fclose(pJugadores);
}



void restaurarDeportes(){
    FILE *pDeportes;
    FILE *pDeportesBackup;
    pDeportesBackup = fopen("Deportes_backup.bak", "rb");
    if (pDeportesBackup == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    pDeportes = fopen("Deportes.dat", "wb");
    if (pDeportes == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }
    Deportes deporte;
    while (fread(&deporte, sizeof(Deportes), 1, pDeportesBackup) == 1){
        fwrite(&deporte, sizeof(Deportes), 1, pDeportes);
    }
    fclose(pDeportesBackup);
    fclose(pDeportes);
}


void EstablecerDatosdeInicio(){
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
    while (fread(&jugador, sizeof(Jugadores), 1, pJugadores) == 1) {
            if(jugador.getEstado()){
                fwrite(&jugador, sizeof(Jugadores), 1, pJugadoresincio);
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
    while (fread(&deporte, sizeof(Deportes), 1, pD) == 1) {
            if(deporte.getEstado()){
                fwrite(&deporte, sizeof(Deportes), 1, pDI);
            }
    }
    fclose(pD);
    fclose(pDI);

    cout << "Datos establecidos correctamente." << endl;

}


#endif // SUBMENUCONFIGURACION_H_INCLUDED
