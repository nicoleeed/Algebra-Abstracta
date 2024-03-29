#include<string>
#include <ctime>
#include<vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Vernam.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;


ZZ mod(ZZ t, ZZ m) {
	ZZ mo ;
	mo=-1;
	if (t < 0)
		return (t * mo >= m) ? (t - (t / m * m)) + m : t + m;
	return (t >= m) ? t - (t / m * m) : t;
}
ZZ euclides(ZZ a, ZZ b) {
    ZZ r1 = a;
	ZZ r2 = b;
	while (r2 > 0) {
		ZZ q = r1 / r2;
		ZZ r = r1 - q * r2;
		r1 = r2;
		r2 = r;
	}
	//cout<<"El Maximo Comun Divisor es: "<<r1<<endl;
	return r1;
}
ZZ getInverse(ZZ a, ZZ m) {
  ZZ tmp(m);
  ZZ s0(1), s1;
  while (m > 0) {
    ZZ q, s, r;
    q = a / m;
    r = a - (m * q);
    s = s0 - s1 * q;
    a = m;
    m = r;
    s0 = s1;
    s1 = s;
  }
  ZZ res = mod(s0, tmp);
  return res;
}

ZZ modularExponentiation(ZZ a, ZZ e, ZZ n) {
  ZZ total;
  total = 1;
  ZZ sqrValue = mod(a, n);
  for(int i = 0; e > 0; i++, e >>= 1) {
    if ( mod(e, (ZZ)2) == (ZZ)1)
      total = mod(total*sqrValue, n);

    sqrValue = mod(sqrValue*sqrValue, n);
  }

  return total;

}



ZZ string_a_zz(string message){
     ZZ number(INIT_VAL, message.c_str());
     return number;
}
string zz_a_string(const ZZ &z)
{
  std::stringstream buffer;
  buffer << z;
  return buffer.str();
}

inline ZZ convBitsToZZ(string bitsStr){
  ZZ conversion;
  for(int i = bitsStr.size(); i >= 0 ; i--)
    if (bitsStr[i] == '1') conversion += power2_ZZ(i);

  return conversion;
}

ZZ convertirBinaryToZZ(string binary)
{
	ZZ res;
	ZZ base;
	base = 2;
	res = 0;
	long exp = 0;
	for (long i = binary.size() - 1; i >= 0; --i) {
		if (binary[i] == '1') {
			res += power(base, exp);
		}
		++exp;
	}

	return res;
}
bool fermatTest(int numTests, string pPrime) {
	ZZ a;
	string binario;
   binario = pPrime;
   ZZ pseudoPrime;
   pseudoPrime= string_a_zz(pPrime);
	if (pseudoPrime == 1)
	{
		return false;
	}
	for (int i = 0; i < numTests; i++)
	{


		a = mod(convertirBinaryToZZ(binario), (pseudoPrime - conv<ZZ>(1)) + conv<ZZ>(1));
		if (modularExponentiation(a, pseudoPrime - 1, pseudoPrime) != 1)
		{
			return false;
		}
	}
	return true;
}
void generadorClaves(ZZ &p ,ZZ &q,int bits) {
   /* p = GenPrime_ZZ(bits);
    q = GenPrime_ZZ(bits);
    */
	/*int tam=10;
	cout<<"tam "<< tam<<endl;
	Vernam gg(tam);
  //cout<<"tam "<< tam<<endl;
	vector<string> binarios = gg.cifrado(generadorMensajeAleatorio(tam, gg.alfabeto, gg.tamAlfabeto));
	string aString;
	aString += binarios[1];
	aString += binarios[2];
    //cout << "aString   "<<aString << endl;
	string bString;
	bString += binarios[3];
	bString += binarios[4];
	//cout << "bString   "<<bString << endl;
	ZZ a;
	ZZ b;

	a= convBitsToZZ(aString);
	//cout << "a "<<a << endl;
	b = convBitsToZZ(bString);
	//cout << "b "<<b << endl;

	vector<ZZ> criba;
	criba=CribaDeEratostenes((ZZ)9999999);
	long temp1 = 0, temp2 = 0;
	conv(temp1, a);
	conv(temp2, b);
	p = criba[temp1];
	q = criba[temp2];
    //cout << "p  " << p << endl;
	//cout << "q  " << q << endl;

	/*
	vector<unsigned long long> primos;
	cout<<"rrr"<<endl;
	primos[0] = 8925;
	primos[1] = 65261;
	cout << "p  " << primos[0] << endl;
	cout << "q  " << primos[1]<< endl;
	return primos;
    */

}
