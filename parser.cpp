#include "parser.hpp"
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

// RETRONA SE O NÚMERO É VALIDO PARA A BASE INFORMADA.
bool valida(string numero, int base){
	string validos = "0123456789ABCDEF";
	bool valido = true;
	for (int i = 0; numero[i] != '\0' && valido; i++) {
		char c = numero[i];
		if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';

		if (c != '.' && c != ',') {
			int indx = -1;
			for (int j = 0; j < 16; j++) {
				if (validos[j] == c) indx = j;
			}

			if (indx == -1 || indx >= base) valido = false;
		}
	}

	return valido;
}

void separa(string numero, string &inteira, string &fracionaria) {
	inteira = "";
	fracionaria = "";
	bool separador = false;
	
	for (int i = 0; numero[i] != '\0'; i++) {
		if (numero[i] == '.' || numero[i] == ',')
			separador = true;
		else if (!separador)
			inteira += numero[i];
		else
			fracionaria += numero[i];
	}
}