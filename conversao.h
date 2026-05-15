#include <iostream>
using namespace std;

string deci_bin(int decimal) {
	string binario = "";

	while (decimal != 0) {
		binario = char((decimal % 2) + '0') + binario;
		decimal /= 2;
	}

	return binario;
}

string deci_oct(int decimal) {
	string octal = "";

	while (decimal != 0) {
		octal = char((decimal % 8) + '0') + octal;
		decimal /= 8;
	}

	return octal;
}

string deci_hexa(int decimal) {
	string hexadecimal = "";
	string digitos = "0123456789ABCDEF";

	while (decimal != 0) {
		hexadecimal = digitos[decimal % 16] + hexadecimal;
		decimal /= 16;		
	}

	return hexadecimal;
}
