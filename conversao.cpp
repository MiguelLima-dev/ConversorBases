#include "conversao.hpp"
#include <iostream>
#include <string>
using namespace std;

// DECIMAL FRACIONARIO P/ BINÁRIO.
string deci_bin(double decimal) {
	string binario = "";
	int parte_inteira = decimal;
	double parte_fracionaria = decimal - parte_inteira;

	if (parte_inteira == 0) binario = "0";

	while (parte_inteira != 0) {
		binario = char((parte_inteira % 2) + '0') + binario;
		parte_inteira /= 2;
	}

	if (parte_fracionaria > 1e-12) {
		binario = binario + '.';

		int casas = 16;

		while (parte_fracionaria > 1e-12 && casas-- > 0) {
			parte_fracionaria *= 2;
			binario = binario + char((int) parte_fracionaria + '0');
			parte_fracionaria = parte_fracionaria - (int) parte_fracionaria;
		}
		
		if (casas <= 0 && parte_fracionaria > 1e-12) {
			binario = binario + "[...]";
		}
	}

	return binario;
}

// BINÁRIO P/ DECIMAL.
int bin_deci(string binario) {
    int decimal = 0, peso = 1;
    unsigned int n_digitos = binario.length();
    
    for (int i = n_digitos - 1; i >= 0; i--) {
        decimal += (binario[i] - '0') * peso;
        peso *= 2;
    }

    return decimal;
}

// PARTE FRACIONÁRIA DO BINÁRIO P/ DECIMAL.
double binFrac_deci(string fracao) {
    double resultado = 0.0;
    double peso = 1.0 / 2.0;
    for (int i = 0; fracao[i] != '\0'; i++) {
        resultado += (fracao[i] - '0') * peso;
        peso /= 2.0;
    }

    return resultado;
}
// DECIMAL FRACIONÁRIO P/ OCTAL.
string deci_oct(double decimal) {
	string octal = "";
	int parte_inteira = decimal;
	double parte_fracionaria = decimal - parte_inteira;

	if (parte_inteira == 0) octal = "0";

	while (parte_inteira != 0) {
		octal = char((parte_inteira % 8) + '0') + octal;
		parte_inteira /= 8;
	}

	if (parte_fracionaria > 1e-12) {
		octal = octal + '.';

		int casas = 16;

		while (parte_fracionaria > 1e-12 && casas-- > 0) {
			parte_fracionaria *= 8;
			octal = octal + char((int) parte_fracionaria + '0');
			parte_fracionaria = parte_fracionaria - (int) parte_fracionaria;
		}

		if (casas <= 0 && parte_fracionaria > 1e-12) {
			octal = octal + "[...]";
		}
	}

	return octal;
}

// OCTAL P/ DECIMAL.
int oct_deci(string octal) {
    int decimal = 0, peso = 1;
    unsigned int n_digitos = octal.length();

    for (int i = n_digitos - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * peso;
        peso *= 8;
    }

    return decimal;
}

// PARTE FRACIONÁRIA DO OCTAL P/ DECIMAL.
double octFrac_deci(string fracao) {
    double resultado = 0.0;
    double peso = 1.0 / 8.0;
    for (int i = 0; fracao[i] != '\0'; i++) {
        resultado += (fracao[i] - '0') * peso;
        peso /= 8.0;
    }

    return resultado;
}

// DECIMAL FRACIONÁRIO P/ HEXADECIMAL.
string deci_hexa(double decimal) {
	string hexadecimal = "";
	int parte_inteira = decimal;
	double parte_fracionaria = decimal - parte_inteira;

	string digitos = "0123456789ABCDEF";
	if (parte_inteira == 0) hexadecimal = "0";

	while (parte_inteira != 0) {
		hexadecimal = digitos[parte_inteira % 16] + hexadecimal;
		parte_inteira /= 16;
	}

	if (parte_fracionaria > 1e-12) {
		hexadecimal = hexadecimal + '.';

		int casas = 16;

		while (parte_fracionaria > 1e-12 && casas-- > 0) {
			parte_fracionaria *= 16;
			hexadecimal = hexadecimal + digitos[(int) parte_fracionaria];
			parte_fracionaria = parte_fracionaria - (int) parte_fracionaria;
		}

		if (casas <= 0 && parte_fracionaria > 1e-12) {
			hexadecimal = hexadecimal + "[...]";
		}
	}

	return hexadecimal;
}

// Usada para encontrar o valor de cada digitos da
// base Hexadecimal.
int index(char c) {
	int indice = -1;
	string digitos = "0123456789ABCDEF";
	for (int i = 0; i < 16 && indice == -1; i++) {
		if (digitos[i] == c) {
			indice = i;
		}
	}

	return indice;
}

// HEXADECIMAL P/ DECIMAL.
int hexa_deci(string hexadecimal) {
	int decimal = 0, peso = 1;
	unsigned int n_digitos = hexadecimal.length();

	for (int i = n_digitos - 1; i >= 0; i--) {
		decimal += index(hexadecimal[i]) * peso;
		peso *= 16;
	}

	return decimal;
}

// CONVERTE A PARTE FRACIONÁRIA DO HEXADECIMAL P/ DECIMAL.
double hexaFrac_deci(string fracao) {
    double resultado = 0.0;
    double peso = 1.0 / 16.0;
    for (int i = 0; fracao[i] != '\0'; i++) {
        resultado += index(fracao[i]) * peso;
        peso /= 16;
    }

    return resultado;
}