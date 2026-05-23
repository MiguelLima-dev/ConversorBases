#include <iostream>
#include <string>

using namespace std;

//Conversão de binário para octal
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

//Conversão de octal para binário

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

//Conversão de binário para hexadecimal
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

string bin_hex(string binario){
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

//Conversão de hexadecimal para binário
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
	if (caractere == 'A')
		return "1010";
	if (caractere == 'B')
		return "1011";
	if (caractere == 'C')
		return "1100";
	if (caractere == 'D')
		return "1101";
	if (caractere == 'E')
		return "1110";
	if (caractere == 'F')
		return "1111";
	return "";
}

string hex_bin (string hexadecimal){
	string binario = "";
	
	int tamH = hexadecimal.length();
	for(int h = 0; h < tamH; h++){
		char caractere = hexadecimal[h];
		
		binario += inversaoH(caractere);
	}
	
	return binario;
}

//Conversão de octal para hexadecimal
string oct_hex(string octal){
	string binario = oct_bin(octal);
	
	string hexadecimal = bin_hex(binario);
	
	return hexadecimal;
}

//Conversão de hexadecimal para octal
string hex_oct(string hexadecimal){
	string binario = hex_bin(hexadecimal);
	string octal = bin_oct(binario);
	
	int i = 0;
	int tamO = octal.length();
	while(i < tamO - 1 && octal[i] == '0'){
		i++;
	}
	
	octal = octal.substr(i);
	return octal;
}


int main (){
	
	string binario, octal, hexadecimal;
	
	cin >> binario;
	cin >> octal;
	cin >> hexadecimal;
	
	cout << "binario para octal: "<< bin_oct(binario) << endl;
	cout << "binario para hexadecimal: "<< bin_hex(binario) << endl;
	cout << "octal para binario: "<< oct_bin(octal) << endl;
	cout << "octal para hexadecimal: "<< oct_hex(octal) << endl;
	cout << "hexadecimal para binario: "<< hex_bin(hexadecimal) << endl;
	cout << "hexadecimal para octal: "<< hex_oct(hexadecimal) << endl;
	
	return 0;
}
