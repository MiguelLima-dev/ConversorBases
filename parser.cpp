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

// TRANSFORMA UM NÚMERO EM UM DOUBLE EM UMA STRING.
string doubleString(double num) {
	string numero = "";
	int inteiro = (int)num;
	double fracionario = num - inteiro;

	if (inteiro == 0) numero = "0";

	while (inteiro > 0) {
		numero = char(inteiro % 10 + '0') + numero;
		inteiro /= 10;
	}

	if (fracionario > 1e-12) {
		numero += '.';
		
		int casas = 16;
		while (fracionario > 1e-12 && casas-- > 0) {
			fracionario *= 10;
			int digito = (int)fracionario;
			numero += char(digito + '0');
			fracionario -= digito;
		}

	}
	return numero;
}

// RETORNA SE O NÚMERO É VALIDO PARA A BASE INFORMADA.
bool valida(string &numero, int base){
    if (numero == "") {
        cout << "Nenhuma entrada encontrada!" << endl;
        return false;
    }
	string validos = "0123456789ABCDEF";
    int separador = 0;
	for (int i = 0; numero[i] != '\0'; i++) {
		char c = numero[i];
		if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
            numero[i] = c;
        }

        if (c == '.' || c == ',') separador++;
		else {
			int indx = -1;
			for (int j = 0; j < 16; j++) {
				if (validos[j] == c) indx = j;
			}
			if (indx == -1 || indx >= base) {
                cout << "Dígito '" << c << "' inválido para base " << base <<"!" << endl;
                return false;
            }
		}
        if (separador > 1) {
            cout << "Mais de um separador inserido!" << endl;
            return false;
        }
	}

	return true;
}

// FUNÇÃO AUXILIAR PARA CONVERSÃO DE OUTRAS BASES PARA DECIMAL.
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