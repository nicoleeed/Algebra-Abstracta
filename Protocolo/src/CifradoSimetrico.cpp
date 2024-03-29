#include "CifradoSimetrico.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ofstream salida ("textoCifrado.txt");
int mo(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}
int generadorNumAleatorio(int maximo){
    srand(time(NULL));
    int aleatorio, DESDE=0, HASTA=maximo;
    aleatorio = mo(rand(),HASTA);
    return aleatorio;
}
string generadorClaveAleatorio(int tam, string alf, int alfabetoTam) {
	string mensajeAleatorio;
	for (int i = 0; i < tam; i++) {
		int aleatorio = generadorNumAleatorio(alfabetoTam-1);
		//cout<<"aleatorio"<< aleatorio<<endl;
		mensajeAleatorio+= alf.at(aleatorio);
		alf.erase(aleatorio, 1);
	}
	return mensajeAleatorio;
}
CifradoSimetrico::CifradoSimetrico(){
    Enigma a;
    claveEnigma=generadorClaveAleatorio(3,alfabeto,alfabetoTam);
   // cout<<"Clave Enigma " <<claveEnigma<<endl;
    //cout<<endl;
    this->r1Rojo=a.r1Rojo;
    salida<<a.r1Rojo<<endl;
    salida<<claveEnigma<<endl;
    salida<<2<<endl;
    salida<<alfabetoTam/2<<endl;

}

string CifradoSimetrico::cifrado(string mensaje){
    int tamMsj=mensaje.size();
    Vigenere b(tamMsj);
    salida<<b.clave<<endl;
    string cifVigenere=b.cifrado(mensaje);
   cout<<"cifrado vigenere  "<<cifVigenere<<endl;
    Enigma a(claveEnigma,r1Rojo,2,alfabetoTam/2);
    string cifEnigma=a.cifrado(cifVigenere);
    cout<<"cifrado enigma   "<<cifEnigma<<endl;
    Afin c;
    salida<<c.aleatorio<<endl;
    salida<<c.b<<endl;
    string cifAfin=c.cifrado(cifEnigma);
    cout<<"cifrado afin     "<<cifAfin<<endl;
    salida<<cifAfin<<endl;
    salida.close();
    return cifAfin;
}

string CifradoSimetrico::descifrado(string mensaje,string r1Rojo,string claveEnigma,int filas,int columnas,string claveVigenere,int a,int b){
    Afin r(a,b);
    cout<<"constructor afin"<<endl;
    string desAfin=r.descifrado(mensaje);
    cout<<"desAfin      "<<desAfin<<endl;
    Enigma s(claveEnigma,r1Rojo,filas,columnas);
    s.cifrado(mensaje);
    string desEnigma=s.descifrado(desAfin);
    cout<<"desEnigma    "<<desEnigma<<endl;
    Vigenere t(claveVigenere);
    string desVigenere=t.descifrado(desEnigma);
    cout<<"desVigenere  "<<desVigenere<<endl;
    return desVigenere;
}
CifradoSimetrico::~CifradoSimetrico()
{
    //dtor
}
