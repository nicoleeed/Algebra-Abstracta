#include <iostream>
#include <fstream>
#include <string>
#include "CifradoSimetrico.h"
#include "Enigma.h"
#include "Afin.h"
using namespace std;

int main()
{

    CifradoSimetrico ra;
    ra.cifrado("En realidad, lo que el sistema controla es que Ud. ingrese dentro de los minutos de tolerancia permitidos. De ahi en adelante puede mantenerse en el sistema el tiempo que considere prudente para la toma de asistencia. Nicole Durand Zeballos codigo, 181-10-43088 Si un estudiante llego despues de haber tomado lista y Ud. se encuentra dentro de los minutos de tolerancia permitidos, puede ingresar nuevamente al sistema y eliminarlo de la lista de inasistentes.");

   string r1Rojo;
    string claveEnigma;
    int filas;
    int columnas;
    string claveVigenere;
    int a;
    int b;
    string mensaje;
    int i=0;
    ifstream entrada("textoCifrado.txt");
    ofstream salida ("textoDesifrado.txt");
    string copia;
    while (getline(entrada,copia)){

            if (i==0){
                r1Rojo=copia;
            }
            if (i==1){
                claveEnigma=copia;
            }
            if (i==2){
                filas=stoi(copia);
            }
            if (i==3){
                columnas=stoi(copia);
            }
            if (i==4){
                claveVigenere=copia;
            }
            if (i==5){
                a=stoi(copia);
            }
            if (i==6){
                b=stoi(copia);
            }
            if (i==7){
                mensaje=copia;
            }
            i++;
    }

    cout<<"r1Rojo  "<<r1Rojo<<endl;
    cout<<"claveEnigma  "<<claveEnigma<<endl;
    cout<<"filas  "<<filas<<endl;
    cout<<"columnas  "<<columnas<<endl;
    cout<<"claveVigenere  "<<claveVigenere<<endl;
    cout<<"a  "<<a<<endl;
    cout<<"b  "<<b<<endl;
    cout<<"mensaje        "<<mensaje<<endl;
    CifradoSimetrico rb;
    string des=rb.descifrado(mensaje,r1Rojo,claveEnigma,filas,columnas,claveVigenere,a,b);



    cout<<"descifrado: "<<des<<endl;
    cout<<endl;
    salida<<des<<endl;

    return 0;
}
