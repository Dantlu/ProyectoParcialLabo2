#ifndef JUGADORES_H
#define JUGADORES_H
#include "FuncionesGlobales.h"
#include "clsDeportes.h"
class Jugadores{
private:
    int DNI;
    Fecha fechaInscripcion;
    char nombre[35];
    char apellido[35];
    char email[35];
    char telefono[35];
    int claustro;
    int deporte;
    int numEquipo;
    float matricula;
    bool estado;
public:
    Jugadores(const char *n="NOMBRE"){
        strcpy(nombre, n);
        estado=true;
        }
    void setDia(int x) {
        fechaInscripcion.setDia(x);
    }

    void setMes(int x) {
        fechaInscripcion.setMes(x);
    }

    void setAnio(int x) {
        fechaInscripcion.setAnio(x);
    }
        ///sets
   void setDNI(int d){DNI=d;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    bool setClaustro(int c) {
    if (c >= 1 && c <= 4) {
        claustro = c;
        return true;
    }
    return false;
}
    bool setDeporte(int dep){
        if(dep>=1 && dep<=10){
        deporte=dep;
        return true;}
        return false;
        }
    void setEquipo(const int eq){numEquipo=eq;}

    bool setMatricula(float mat){
        if(mat>=0){
        matricula=mat;
        return true;}
        return false;
        }
    void setEstado(bool s){
      estado=s;}

    ///gets
    int getDNI(){return DNI;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getEquipo(){return numEquipo;}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}


    void Cargar(const int);
    void Mostrar();

};

 bool validarID(int ID){
    Deportes reg;
    bool IDencontrado=false;
    FILE *pDep;
    pDep=fopen("Deportes.dat","rb");
    if(pDep==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg,sizeof reg,1,pDep)==1){
        if(reg.getID()==ID){
            IDencontrado=true;
            break;
        }
    }

    fclose(pDep);
    return IDencontrado;
}


void Jugadores::Cargar(int d=-1){
    if(d==-1){
        cout<<"DOCUMENTO: ";
        cin>>DNI;
    }
    else{
        DNI=d;
    }
    cout<<"Nombre: ";
    cargarCadena(nombre, 35);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,35);
    cout<<"EMAIL: ";
    cargarCadena(email,35);
    cout<<"TELEFONO: ";
    cargarCadena(telefono,35);
    cout<<"CLAUSTRO: ""(1:docente, 2:alumno,3:no docente, 4:graduado): ";
    int cla;
    cin>>cla;
    if(!setClaustro(cla)){
        cout<<"EL VALOR INGRESADO NO ES VALIDO"<<endl;
        return;
    }claustro=cla;

   while (!validarID(deporte)) {
    cout << "DEPORTE: (1 a 10): ";
    cin >> deporte;

    if (!validarID(deporte)) {
        cout << "EL DEPORTE INGRESADO ES INCORRECTO, INGRESELO NUEVAMENTE" << endl;
    }
}
    cout<<"EQUIPO: ";
    cin>>numEquipo;
    cout<<"FECHA DE INSCRIPCION"<<endl;
    fechaInscripcion.Cargar();
    cout<<"MATRICULA: ";
    int mt;
    cin>>mt;
    if(!setMatricula(mt)){
        cout<<"NUMERO DE MATRICULA INCORRECTO"<<endl;
    }matricula=mt;
    estado=true;

}

void Jugadores::Mostrar(){

if(estado==true){
        cout<<"DNI: ";
        cout<<DNI<<endl;
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"TELEFONO: ";
        cout<<telefono<<endl;
        cout<<"CLAUSTRO: ";
        cout<<claustro<<endl;
        cout<<"DEPORTE: (1 a 10)";
        cout<<deporte<<endl;
        cout<<"EQUIPO";
        cout<<numEquipo<<endl;
        cout<<"FECHA INSCRIPCION: "<<endl;
        fechaInscripcion.Mostrar();
        cout<<"MATRICULA: "<<endl;
        cout<<matricula<<endl;
    }

}

class ArchivoJugadores {
private:
    char nombre[35];
public:
    ArchivoJugadores(const char* n) {
        strcpy(nombre, n);
    }
    bool AgregarRegistro(Jugadores reg);
    bool buscarPorDNI();
    bool listarRegistros();
    int buscarDNI(int dni);
    Jugadores leerRegistro(int pos);
    bool modificarRegistro(Jugadores reg, int pos);

};

bool ArchivoJugadores::AgregarRegistro(Jugadores reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}


bool ArchivoJugadores::listarRegistros(){
    Jugadores reg;
    FILE *p=fopen(nombre,"rb");
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

int ArchivoJugadores::buscarDNI(int dni){
    Jugadores reg;
    FILE *pJug;
    pJug=fopen("Jugadores.dat","rb");
    if(pJug==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int posRegistro=0;
    while(fread(&reg,sizeof(Jugadores),1,pJug)==1){
        if(reg.getDNI()==dni){
            fclose(pJug);
            return posRegistro;
        }
        posRegistro++;
    }
    fclose(pJug);
    return -1;
}

Jugadores ArchivoJugadores::leerRegistro(int pos){
    Jugadores reg;
    reg.setDNI(-1);
    FILE *pJug;
    pJug=fopen("Jugadores.dat","rb");
    if(pJug==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(pJug,sizeof reg*pos,0);

    int leyo=fread(&reg,sizeof(Jugadores),1,pJug);
    fclose(pJug);

    if(leyo==0) reg.setDNI(-1);
    return reg;
}

bool ArchivoJugadores::modificarRegistro(Jugadores reg, int pos){
    FILE *pJug;
    pJug=fopen("Jugadores.dat","rb+");///+ le agrega al modo lo que no tiene
    if(pJug==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(pJug,sizeof reg*pos,0);
    bool escribio=fwrite(&reg,sizeof(Jugadores),1,pJug);
    fclose(pJug);
    return escribio;
}
#endif // JUGADORES_H
