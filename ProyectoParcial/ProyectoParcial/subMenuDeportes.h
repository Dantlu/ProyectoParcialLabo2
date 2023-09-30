#include "clsDeportes.h"
void agregarRegistroDeportes();
bool buscarPorID();
void mostrarDeportes();
bool bajaLogicaDeportes();
bool CambiarFechaDeporte();

void subMenuDeportes(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU DEPORTES" << endl;
        cout << "------------------" << endl;
        cout << "1) AGREGAR DEPORTE" << endl;
        cout << "2) LISTAR DEPORTE POR ID" << endl;
        cout << "3) LISTAR TODO" << endl;
        cout << "4) MODIFICAR ANIO DE ORIGEN" << endl;
        cout << "5) ELIMINAR REGISTRO" << endl;
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

void agregarRegistroDeportes(){
     ArchivoDeportes archi("Deportes.dat");
     int contID = archi.contarRegistros();
     Deportes reg;
    ///Asignamos valores al objeto de memoria
    reg.cargarDeporte();
    reg.setID(contID + 1);
    ///Escribimos el registro en el archivo
    if(archi.AgregarRegistro(reg)==true){
        cout<<"REGISTRO AGREGADO";
    }
    else{
        cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
    }
}

bool buscarPorID(){
    int ID;
    Deportes reg;
    FILE *pDep;
    bool existe=false;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    cout<<"INGRESAR DNI A BUSCAR ";
    cin>>ID;
    while(fread(&reg,sizeof(Deportes),1,pDep)==1){
        if(reg.getID()==ID){
            reg.mostrarDeporte();
            existe=true;
        }
    }
    fclose(pDep);
    if(existe==false){
        cout<<"NO HAY REGISTROS CON ESE DNI"<<endl;
    }
    return true;
}

void mostrarDeportes(){
        ArchivoDeportes archi("Deportes.dat");
        archi.listarRegistros();
}

bool CambiarFechaDeporte() {
    ArchivoDeportes archi("Deportes.dat");
    int ID;
    cout << "Ingrese el ID del deporte al que desea cambiar la fecha de origen: ";
    cin >> ID;

    int pos = archi.buscarID(ID);

    if (pos == -1) {
        cout << "NO EXISTE UN REGISTRO CON ESE ID" << endl;
        return false;
    }

    Deportes reg=archi.leerRegistro(pos);

    if (reg.getID() == -1) {
        cout << "NO EXISTE EL REGISTRO" << endl;
        return false;
    }

    int nuevoanio;
    cout << "---Nueva Anio de origen---" << endl;
    cout << "ANIO: ";
    cin >> nuevoanio;


    reg.setfecha(nuevoanio);
    bool quePaso = archi.modificarRegistro(reg, pos);
    return quePaso;
}


bool bajaLogicaDeportes(){
    ///BUSCAR EL REGISTRO
    ArchivoDeportes archi("Deportes.dat");
    int ID;
    cout<<"INGRESAR EL ID DEL DEPORTE QUE QUIERE DAR DE BAJA ";
    cin>>ID;
    ///VER SI EL REGISTRO SI EL REGISTRO EXISTE EN EL ARCHIVO
    int pos=archi.buscarID(ID);
    ///SI NO EXISTE, INFORMARLO Y TERMINAR LA FUNCION.
    if(pos==-1){
        cout<<"NO EXISTE UN REGISTRO CON ESE ID"<<endl;
        return false;
    }
    ///SI EXISTE, LEER EL REGISTRO
    Deportes reg=archi.leerRegistro(pos);
    if(reg.getID()==-1){
        cout<<"NO EXISTE EL REGISTRO"<<endl;
    }
    ///CAMBIAR EL VALOR DEL CAMPO/PROPIEDAD estado
    reg.setEstado(false);
    ///SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(reg, pos);
    return quePaso;
}


