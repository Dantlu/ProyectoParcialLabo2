#ifndef CLSDEPORTES_H_INCLUDED
#define CLSDEPORTES_H_INCLUDED

#include <iostream>
#include <cstring>
#include "FuncionesGlobales.h"
class Deportes {
private:
   int IDdeporte;
   char nombre[30];
   int tipoDeporte;
   int anio;
   bool estado;
    int contadorID;
public:


    Deportes(const char *n = "NOMBRE") {
        strcpy(nombre, n);
        IDdeporte = ++contadorID;

        tipoDeporte = 0;
        anio = 0;
        estado = false;
    }
    void setID(int id){
    IDdeporte=id;
    }
    void setnombre(const char *n) {
        strcpy(nombre, n);
    }

    bool settipodeporte(int t) {
        if (t >= 1 && t <= 21) {
            tipoDeporte = t;
            return true;
        } else {
            return false;
        }
    }

    void setEstado(bool s) {
        estado = s;
    }

    bool setfecha(int f) {
        if (f >= 1800 && f <= 2023) {
            anio = f;
            return true;
        } else {
            return false;
        }
    }
    int getID(){return IDdeporte;}
    const char* getNombre() {return nombre;}
    int gettipodeporte() {return tipoDeporte;}
    bool getEstado() {return estado;}
    int getfecha() {return anio;}


    void cargarDeporte();
    void mostrarDeporte();
};

    void Deportes::cargarDeporte() {

        cout<<"INGRESE EL NOMBRE: ";
        cargarCadena(nombre, 35);
        cout << "INGRESE EL TIPO DE DEPORTE (1 a 21): ";
        int td;
        cin >> td;
        if (!settipodeporte(td)) {
            cout << "EL VALOR INGRESADO NO ES VALIDO" << endl;
            return;
        }

       bool entra=true;
    while (entra){
        cout<<"INGRESE EL ANIO: ";
        cin>>anio;
        if (anio>=1800&&anio<=2023){
            entra=false;
        }else{
            cout<<"---------------------------------------------------"<<endl;
            cout<<"EL ANIO INGRESADO NO ES VALIDO, INTENTE DE NUEVO:"<<endl;
        }
    }
        estado = true;
    }


    void Deportes::mostrarDeporte() {
        if (estado == true) {
            cout<< "ID: "<<IDdeporte<<endl;
            cout << "NOMBRE: " << nombre<<endl;
            cout << "TIPO DE DEPORTE: " << tipoDeporte<<endl;
            cout << "ANIO: " << anio <<endl;
        }
    }

class ArchivoDeportes {
private:
    char nombre[35];
public:
    ArchivoDeportes(const char* n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(Deportes reg);
    bool listarRegistros();
    int buscarID(int ID);
    Deportes leerRegistro(int pos);
    bool modificarRegistro(Deportes reg, int pos);
    int contarRegistros();

};
int ArchivoDeportes::contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return 0;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deportes);
      }
bool ArchivoDeportes::AgregarRegistro(Deportes reg){

    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}


bool ArchivoDeportes::listarRegistros(){
    Deportes reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg, sizeof reg,1,p)==1){
        reg.mostrarDeporte();
        cout<<endl;
    }
    fclose(p);
    return true;
}
int ArchivoDeportes::buscarID(int ID){
    Deportes reg;
    FILE *pDep;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Deportes),1,pDep)==1){
        if(reg.getID()==ID){
            fclose(pDep);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pDep);
    return -1;
}
Deportes ArchivoDeportes::leerRegistro(int pos){
    Deportes reg;
    reg.setID(-1);
    FILE *pDep;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(pDep,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Deportes),1,pDep);
    fclose(pDep);

    if(leyo==0) reg.setID(-1);
    return reg;
}


bool ArchivoDeportes::modificarRegistro(Deportes reg, int pos){
    FILE *pDep;
    pDep=fopen("Deportes.dat","rb+");///+ le agrega al modo lo que no tiene
    if(pDep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pDep,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Deportes),1,pDep);
    fclose(pDep);
    return escribio;
}

#endif // CLSDEPORTES_H_INCLUDED
