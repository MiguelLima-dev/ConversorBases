#include <iostream>
using namespace std;

int main(){
    // Converte decimal para octal
	int decimal;
	cin >> decimal;
	
	string octal = "";
    int temp = decimal;
	while (decimal != 0){
		octal = char((decimal % 8) + '0') + octal;
		decimal /= 8;
	}
	
	cout << "Octal: " << octal << endl;

    // Converte decimal para binário
    decimal = temp;
	string binario = "";
	while (decimal != 0){
		binario = char((decimal % 2) + '0') + binario;
		decimal /= 2;
	}
	
	cout << "Binario: " << binario << endl;

    // Converte decimal para hexadecimal
    decimal = temp;
    string hexadecimal = "";
    string digitos = "0123456789ABCDEF";

    while (decimal != 0) {
        hexadecimal = digitos[decimal % 16] + hexadecimal;
        decimal /= 16;
    }

    cout << "Hexadecimal: " << hexadecimal << endl;
	return 0;
}
