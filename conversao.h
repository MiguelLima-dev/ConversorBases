#include <iostream>
using namespace std;

// DECIMAL P/ BINÁRIO.
string deci_bin(int decimal) {
	string binario = "";

	while (decimal != 0) {
		binario = char((decimal % 2) + '0') + binario;
		decimal /= 2;
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

// DECIMAL P/ OCTAL.
string deci_oct(int decimal) {
	string octal = "";

	while (decimal != 0) {
		octal = char((decimal % 8) + '0') + octal;
		decimal /= 8;
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

// DECIMAL P/ HEXADECIMAL
string deci_hexa(int decimal) {
	string hexadecimal = "";
	string digitos = "0123456789ABCDEF";

	while (decimal != 0) {
		hexadecimal = digitos[decimal % 16] + hexadecimal;
		decimal /= 16;		
	}

	return hexadecimal;
}
