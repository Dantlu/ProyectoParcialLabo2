#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include <iostream>
#include <cstdlib>

/*
INTEGRANTE QUE DESARROLLO ESTA PARTE DEL EXAMEN:
Dante Luongo
*/

using namespace std;
#include "clsJugadores.h"
#include "FuncionesGlobales.h"
#include "clsDeportes.h"

void subMenuReportes();
void punto1();
void punto2();
bool listarRegistros();

void subMenuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU REPORTES" << endl;
        cout << "------------------" << endl;
        cout << "1) PUNTO 1" << endl;
        cout << "2) PUNTO 2" << endl;
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
            case 0:
                return;
            default:
                cout << "OPCION NO VALIDA." << endl;
        }
        system("pause");
    }
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

void punto1() {
   /// Informar EL MES de este año con mayor cantidad de jugadores inscriptos
   ///COMO DICE INFORMAR EL MES, SI HAY DOS MESES CON LA MISMA CANTIDAD DE INSCRIPTOS, VOY A MOSTRAR EL PRIMERO QUE ME APAREZCA.
    ArchivoJugadores archi("Jugadores.dat");
    Jugadores reg;
    int vMes[12]={0};
    int i;
    int cantreg=archi.contarRegistros();
    for(i=0;i<cantreg;i++){
        reg=archi.leerRegistro(i);
        if(reg.getFechaInscripcio().getAnio()==2023){
                vMes[reg.getFechaInscripcio().getMes()-1]++;
        }
    }
    cout<<"EL MES DE ESTE ANIO 2023 CON MAS CANTIDAD DE JUGADORES INSCRIPTOS ES EL: "<<maximoVector(vMes, 12)+1<<endl;
}


/*Generar un archivo con los docentes que participan de deportes
pertenecientes al tipo de deporte 3. Cada registro del archivo nuevo debe tener el
siguiente formato:
DNI, nombre, apellido y fecha de inscripción*/

bool esDelTipoDeDeporte(int IDdeporte, int tipo){
    ArchivoDeportes archi("Deportes.dat");
    Deportes aux;
    int cantregistros=archi.contarRegistros();
    int i;
    for(i=0;i<cantregistros;i++){
        aux=archi.leerRegistro(i);
        if(aux.getID()==IDdeporte){
            if(aux.gettipodeporte()==tipo){
                return true;
            }return false;
        }
    }return false;
}

class solucionPunto2{
private:
    int DNI;
    char nombre[35];
    char apellido[35];
    Fecha fechaInscripcionDocente;
public:
    void setDni(int d){DNI=d;}
    void setNombre(const char* nom){strcpy(nombre,nom);}
    void setApellido(const char* ape){strcpy(apellido,ape);}
    void setFechaInscripcion(Fecha f){fechaInscripcionDocente=f;}

    solucionPunto2(int d=0,const char* n="nadie",const char* a="nada", int dia=0, int mes=0, int anio=0){
        DNI=d;
        strcpy(nombre,n);
        strcpy(apellido,a);
        fechaInscripcionDocente=Fecha();
        fechaInscripcionDocente.setDia(dia);
        fechaInscripcionDocente.setMes(mes);
        fechaInscripcionDocente.setAnio(anio);
    }

    void Mostrar(){
        cout<<"DNI: "<<DNI<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: "<<apellido<<endl;
        cout<<"FECHA DE INSCRIPCION: ";
        fechaInscripcionDocente.Mostrar();

    }

};

bool escribirRegistro(solucionPunto2 reg){
    FILE *p;
    p=fopen("Punto2.dat","ab");
    if(p==NULL)return false;
    bool escribio = fwrite(&reg,sizeof reg, 1, p);
    fclose(p);
    return escribio;
}

void punto2(){
    ArchivoJugadores archi("Jugadores.dat");
    Jugadores reg;
    solucionPunto2 aux;
    int i;
    int cantRegistros=archi.contarRegistros();
    for(i=0;i<cantRegistros;i++){
        reg=archi.leerRegistro(i);
        if(reg.getClaustro()==1){
            if(esDelTipoDeDeporte(reg.getDeporte(),3)){
                aux.setDni(reg.getDNI());
                aux.setNombre(reg.getNombre());
                aux.setApellido(reg.getApellido());
                aux.setFechaInscripcion(reg.getFechaInscripcio());
                escribirRegistro(aux);
                }
            }
        }
    }



///VERIFICO SI MI PUNTO ESTA CORRECTO.
///NO DEBERIA CREAR EL ARCHIVO PORQUE EL UNICO DEPORTE DE TIPO 3 TIENE ID=6
///NO HAY NINGUN CLAUSTRO 1(DOCENTES) CON DEPORTE=6

bool listarRegistros(){
    solucionPunto2 reg;
    FILE *p=fopen("Punto2.dat","rb");
        if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
            }

      while(fread(&reg, sizeof reg,1,p)==1){
          reg.Mostrar();
          cout<<endl;
            }

    fclose(p);

    return true;
}
