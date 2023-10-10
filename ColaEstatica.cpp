/*
COLA ESTATICA
ANGEL GABRIEL RODRIGUEZ MARTINEZ
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int TAM = 10;

class Alumno {
private:
    string nombre;
    string carrera;
    int matAp;
    float prom;

public:
    Alumno(string nom, string carr, int matAp, float prom) {
        nombre = nom;
        carrera = carrera;
        matAp = matAp;
        prom = prom;
    }

    Alumno() {}

    friend std::ostream& operator<<(std::ostream& o, Alumno& alum) {
       o << "\t\nNombre del alumno: " << alum.nombre << "\t\nCarrera que cursa: " << alum.carrera << "\t\nMaterias Aprobadas: " << alum.matAp << "\t\nPromedio general: " << alum.prom << "\n" << endl;
        return o;
    }

    friend std::istream& operator>>(std::istream& o, Alumno& alum) {
        std::cout<< "Ingresa el nombre del alumno : ";getline(o, alum.nombre);
        std::cout << "Ingresa la carrera que cursa: ";getline(o, alum.carrera);
        std::cout << "Ingresa el numero de materias aprobadas: ";o >> alum.matAp;cin.ignore();
        std::cout << "Ingresa el promedio general del alumno: ";o >> alum.prom;
        return o;
    }

    bool operator ==(Alumno& alum) {
        return ((nombre == alum.nombre) && (carrera == alum.carrera) && (matAp == alum.matAp) && (prom == alum.prom));
    }

    bool operator !=(Alumno& alum) {
        return ((nombre != alum.nombre) && (carrera != alum.carrera) && (matAp != alum.matAp) && (prom != alum.prom));
    }

    Alumno operator+(const Alumno& sum) const {
        Alumno resultado(nombre + sum.nombre, carrera + sum.carrera, matAp + sum.matAp, prom + sum.prom);
        return resultado;
    }

    
    bool operator<(const Alumno& menq) const {
        return prom < menq.prom;
    }

    bool operator>(const Alumno& mayq) const {
        return prom > mayq.prom;
    }

};

class Cola {
private:
    Alumno datos[TAM];
    int last;

    int inserta(Alumno elem, int pos) {
        int i = last + 1;
        while (i > pos) {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        last++;
        return 1;
    }

    bool elimina(int pos) {
        int i = pos;
        while (i < last) {
            datos[i] = datos[i + 1];
            i++;
        }
        last--;
        return false;
    }

public:
    Cola() :last(-1) {}

    bool vacia()const {
        if (last == -1)
            return true;
        return false;
    }
    bool llena()const {
        if (last == TAM - 1)
            return true;
        return false;
    }


    int ultimo()const {
        return last;
    }

    void enqueue(Alumno& elem)
    {
        inserta(elem, 0);
    }

    Alumno& dequeue()
    {
        last--;
        return datos[last + 1];
    }
};

int main()
{
    int opc=-1,nAlums=0;
    Cola cola1;
    Alumno x;
    while (1){
        system("cls");
        cout << "\t\tSolicitudes de Constancias de alumnos\n\tSelecciona la operacion a realizar del siguiente menu" << endl;
        cout << "1. Crear solicitud\n2. Elaborar una constancia\n3. Salir\n\tTu seleccion: ";cin >> opc;cin.ignore();

        switch (opc) {
        case 1:system("cls");
            if (cola1.llena()) {
                std::cout << "ERROR DE INSERCION: La cola esta llena\n";system("PAUSE");break;
            }
            else {
                std::cout << "\tAGREGAR SOLICITUD DE CONSTANCIA:\n";cin >> x;
                cola1.enqueue(x);nAlums++;
            }
            cout << "Solicitud encolada con exito" << endl;
            system("PAUSE");
            break;
        
        case 2:system("cls");
            if (cola1.vacia()) {
                std::cout << "ERROR DE ATENCION: La cola esta vacia\n";system("PAUSE");break;
            }
            else {
                x=cola1.dequeue();
            }
            cout << x<<endl;
            system("PAUSE");

        break;

        case 3:exit(0);break;

        default: std::cout << "Ingresa una opcion valida";system("PAUSE");
    }
    }
}