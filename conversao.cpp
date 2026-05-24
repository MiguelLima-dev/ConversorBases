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

// Usada para encontrar o valor de cada digitos da base Hexadecimal.
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

//CONVERSÃO DE BINÁRIO PARA OCTAL
char conversao(string blocoOCT){
	
	if (blocoOCT == "000")
		return '0';
	
	else if (blocoOCT == "001")
		return '1';
		
	else if (blocoOCT == "010")
		return '2';
		
	else if (blocoOCT == "011")
		return '3';
		
	else if (blocoOCT == "100")
		return '4';
		
	else if (blocoOCT == "101")
		return '5';
		
	else if (blocoOCT == "110")
		return '6';
		
	else if(blocoOCT == "111")
		return '7';
		
	else	
		return '0';
}

string bin_oct(string binario){
	string octal = "";
	
	int tamB = binario.length(); 
	if (tamB % 3 == 0){
		octal = binario;
	}
		
	else if(tamB % 3 == 1){
		octal = "00" + binario;
	}
	else if(tamB % 3 == 2){
		octal = "0" + binario;
	}
	
	int tamO = octal.length();
	string result = "";
	for(int i=0; i < tamO; i+=3){
		string blocoOCT = octal.substr(i, 3);
		
		result = result + conversao(blocoOCT);
	}
	
	return result;
}

//CONVERSÃO DE OCTAL PARA BINÁRIO
string inversao(char caractere){
	if (caractere == '0')
		return "000";
	if (caractere == '1')
		return "001";
	if (caractere == '2')
		return "010";
	if (caractere == '3')
		return "011";
	if (caractere == '4')
		return "100";
	if (caractere == '5')
		return "101";
	if (caractere == '6')
		return "110";
	if (caractere == '7')
		return "111";
	return "";
}

string oct_bin (string octal){
	string binario = "";
	
	int tamO = octal.length();
	for (int o = 0; o < tamO; o++){
		char caractere = octal[o];
		
		binario += inversao(caractere); 
	}
	
	return binario;
}

//CONVERSÃO DE BINÁRIO PARA HEXADECIMAL
char conversaoH (string blocoHEX){
	if(blocoHEX == "0000")
		return '0';
	else if(blocoHEX == "0001")
		return '1';
	else if(blocoHEX == "0010")
		return '2';
	else if(blocoHEX == "0011")
		return '3';
	else if(blocoHEX == "0100")
		return '4';
	else if(blocoHEX == "0101")
		return '5';
	else if(blocoHEX == "0110")
		return '6';
	else if(blocoHEX == "0111")
		return '7';
	else if(blocoHEX == "1000")
		return '8';
	else if(blocoHEX == "1001")
		return '9';
	else if(blocoHEX == "1010")
		return 'A';
	else if(blocoHEX == "1011")
		return 'B';
	else if(blocoHEX == "1100")
		return 'C';
	else if(blocoHEX == "1101")
		return 'D';
	else if(blocoHEX == "1110")
		return 'E';
	else if(blocoHEX == "1111")
		return 'F';
	return '0';
}
string bin_hexa(string binario){
	string hexadecimal = "";
	
	int tamB = binario.length();
	if (tamB % 4 == 0){
		hexadecimal = binario;
	}
	else if (tamB % 4 == 1){
		hexadecimal = "000" + binario;
	}
	else if(tamB % 4 == 2){
		hexadecimal = "00" + binario;
	}
	else if(tamB % 4 == 3){
		hexadecimal = "0" + binario;
	}
	int tamH = hexadecimal.length();
	string result = "";
	for(int j=0; j<tamH; j+=4){
		string blocoHEX = hexadecimal.substr(j, 4);
		
		result += conversaoH(blocoHEX);
	}
	
	return result;
}

//CONVERSÃO DE HEXADECIMAL PARA BINÁRIO
string inversaoH(char caractere){
	
	if (caractere == '0')
		return "0000";
	if (caractere == '1')
		return "0001";
	if (caractere == '2')
		return "0010";
	if (caractere == '3')
		return "0011";
	if (caractere == '4')
		return "0100";
	if (caractere == '5')
		return "0101";
	if (caractere == '6')
		return "0110";
	if (caractere == '7')
		return "0111";
	if (caractere == '8')
		return "1000";
	if (caractere == '9')
		return "1001";
	if (caractere == 'A' || caractere == 'a')
		return "1010";
	if (caractere == 'B' || caractere == 'b')
		return "1011";
	if (caractere == 'C' || caractere == 'c')
		return "1100";
	if (caractere == 'D' || caractere == 'd')
		return "1101";
	if (caractere == 'E' || caractere == 'e')
		return "1110";
	if (caractere == 'F' || caractere == 'f')
		return "1111";
	return "";
}
string hexa_bin (string hexadecimal){
	string binario = "";
	
	int tamH = hexadecimal.length();
	for(int h = 0; h < tamH; h++){
		char caractere = hexadecimal[h];
		
		binario += inversaoH(caractere);
	}
	
	return binario;
}

//CONVERSÃO DE OCTAL PARA HEXADECIMAL
string oct_hexa(string octal){
	string binario = oct_bin(octal);
	
	string hexadecimal = bin_hexa(binario);
	
	return hexadecimal;
}

//CONVERSÃO DE HEXADECIMAL PARA OCTAL
string hexa_oct(string hexadecimal){
	string binario = hexa_bin(hexadecimal);
	string octal = bin_oct(binario);
	
	int i = 0;
	int tamO = octal.length();
	while(i < tamO - 1 && octal[i] == '0'){
		i++;
	}
	
	octal = octal.substr(i);
	return octal;
}
