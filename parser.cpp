#include "parser.hpp"
#include <iostream>
#include <string>


// TRANFORMA UM NÚMERO EM UMA STRING EM UM DOUBLE.
double stringDouble(std::string s) {
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
std::string doubleString(double num) {
	std::string numero = "";
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
bool valida(std::string &numero, int base){
    if (numero == "") {
        std::cout << "Nenhuma entrada encontrada!" << std::endl;
        return false;
    }
	std::string validos = "0123456789ABCDEF";
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
                std::cout << "Dígito '" << c << "' inválido para base " << base <<"!" << std::endl;
                return false;
            }
		}
        if (separador > 1) {
            std::cout << "Mais de um separador inserido!" << std::endl;
            return false;
        }
	}

	return true;
}

// FUNÇÃO AUXILIAR PARA CONVERSÃO DE OUTRAS BASES PARA DECIMAL.
void separa(std::string numero, std::string &inteira, std::string &fracionaria) {
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

void input(std::string &input, bool &trace) {
	std::cout << "Insira o valor a ser convertido: ";
	std::cin >> input;
	std::cout << "Deseja ver o trace da conversão? (1 para sim, 0 para não): ";
	std::cin >> trace;
}