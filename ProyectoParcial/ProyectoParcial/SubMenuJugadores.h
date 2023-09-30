#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED
#include "clsJugadores.h"
#include "FuncionesGlobales.h"
///PROTOTIPOS
void subMenuJugadores();
void agregarRegistroJugadores();
void mostrarJugadores();
bool buscarPorDNI();
bool CambiarFechaJugador();
bool bajaLogica();
///FIN PROTOTIPOS


void subMenuJugadores(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU JUGADORES"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1) AGREGAR JUGADOR"<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI"<<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES"<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADOR"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<"SELECCIONE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroJugadores();
                break;
            case 2:  buscarPorDNI();
            break;
            case 3: mostrarJugadores();
                break;

            case 4: CambiarFechaJugador();
                break;
            case 5: bajaLogica();
                break;
            case 0: return;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;
    }
    system("pause");
}

}



void agregarRegistroJugadores(){
    Jugadores reg;
    ArchivoJugadores archi("Jugadores.dat");
    ///Asignamos valores al objeto de memoria
    reg.Cargar();
    ///Escribimos el registro en el archivo
    if(archi.AgregarRegistro(reg)==true){
        cout<<"REGISTRO AGREGADO"<<endl;
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

bool buscarPorDNI(){
    int DNI;
    Jugadores reg;
    FILE *pJug;
    bool existe=false;
    pJug=fopen("Jugadores.dat","rb");
    if(pJug==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    cout<<"INGRESAR DNI A BUSCAR ";
    cin>>DNI;
    while(fread(&reg,sizeof(Jugadores),1,pJug)==1){
        if(reg.getDNI()==DNI){
            reg.Mostrar();
            existe=true;
        }
    }
    fclose(pJug);
    if(existe==false){
        cout<<"NO HAY REGISTROS CON ESE DNI"<<endl;
    }
    return true;
}

void mostrarJugadores(){
        ArchivoJugadores archi("Jugadores.dat");
        archi.listarRegistros();
}


bool CambiarFechaJugador() {
    ArchivoJugadores archi("Jugadores.dat");
    int dni;
    cout << "Ingrese el DNI del jugador al que desea cambiar la fecha de inscripcion: ";
    cin >> dni;

    int pos = archi.buscarDNI(dni);

    if (pos == -1) {
        cout << "NO EXISTE UN REGISTRO CON ESE DNI" << endl;
        return false;
    }

    Jugadores reg=archi.leerRegistro(pos);

    if (reg.getDNI() == -1) {
        cout << "NO EXISTE EL REGISTRO" << endl;
        return false;
    }

    int nuevodia, nuevomes, nuevoanio;
    cout << "---Nueva fecha---" << endl;
    cout << "DIA: ";
    cin >> nuevodia;
    cout << "MES: ";
    cin >> nuevomes;
    cout << "ANIO: ";
    cin >> nuevoanio;

    reg.setDia(nuevodia);
    reg.setMes(nuevomes);
    reg.setAnio(nuevoanio);
    bool quePaso = archi.modificarRegistro(reg, pos);
    return quePaso;
}


bool bajaLogica(){
    ///BUSCAR EL REGISTRO
    ArchivoJugadores archi("Jugadores.dat");
    int dni;
    cout<<"INGRESAR EL DNI DEL EMPLEADO A DAR DE BAJA ";
    cin>>dni;
    ///VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int pos=archi.buscarDNI(dni);
    ///SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE DNI"<<endl;
        return false;
    }
    ///SI EXISTE, LEER EL REGISTRO
    Jugadores reg=archi.leerRegistro(pos);
    if(reg.getDNI()==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
    }
    ///CAMBIAR EL VALOR DEL CAMPO/PROPIEDAD estado
    reg.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(reg, pos);
    return quePaso;
}
#endif // SUBMENUJUGADORES_H_INCLUDED
