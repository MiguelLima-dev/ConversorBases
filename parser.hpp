#include <iostream>
#include <string>
using namespace std;

// TRANFORMA UM NÚMERO EM UMA STRING EM UM DOUBLE.
double stringDouble(string s) {
	double resultado = 0.0;	
	double divisor = 10.0;
	bool separador = false;

	for (int i = 0; s[i] != '\0'; i++) {
		char c = s[i];
		if (c == ',' || c == '.')
			separador = true;
		else {
			int digito = c - '0';
			if (!separador) {
				resultado = resultado * 10.0 + digito;
			} else {
				resultado += digito / divisor;
				divisor *= 10.0;
			}
		}
	}

	return resultado;
}