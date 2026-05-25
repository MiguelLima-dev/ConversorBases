#include "formatador.hpp"
#include "conversao.hpp"
#include "parser.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void imprimir(string resultado, int baseOrigem, int baseDestino) {
    cout << "Base " << baseOrigem << " -> Base " <<
        baseDestino << ": " << resultado << endl;
}

void modoBatch() {
    string entrada, saida;
    cout << "Nome do arquivo de entrada: " << endl;
    cin >> entrada;
    cout << "Nome do arquivo de saida: " << endl;
    cin >> saida;

    ifstream input;
	input.open(entrada);
		
	ofstream output;
    output.open(saida);
	
	if(input.is_open() && output.is_open()){
	    string valor;
		string baseOriginal;
	    string novaBase;
			
			
		while (getline(input, valor, ';')){
			getline(input, baseOriginal, ';');
			getline(input, novaBase);
			
			while(!novaBase.empty() && (novaBase.back() == '\r' || novaBase.back() == '\n')){
				novaBase.pop_back();
			}
				
			if(!valor.empty() && valor.front() == '\n'){
				valor.erase(0, 1);
			}
				
			string valorOriginal = valor;
			string resultado  = "Conversão não incluida";
				
			string inteira = "", fracionaria = "";
				
			if(baseOriginal == "10" && novaBase == "2"){
				resultado = deci_bin(stringDouble(valor), false);
			}
			else if(baseOriginal == "10" && novaBase == "8"){
				resultado = deci_oct(stringDouble(valor), false);
			}
			else if(baseOriginal == "10" && novaBase == "16"){
				resultado = deci_hexa(stringDouble(valor), false);
			}
				
			else if(baseOriginal == "2" && novaBase == "10"){
				separa(valor, inteira, fracionaria);
				double result = bin_deci(inteira, false);
				if (fracionaria != "") result += binFrac_deci(fracionaria, false);
				resultado = doubleString(result);
			}
			else if(baseOriginal == "2" && novaBase == "8"){
				resultado = bin_oct(valor, false);
			}
			else if(baseOriginal == "2" && novaBase == "16"){
				resultado = bin_hexa(valor, false);
			}
				
			else if(baseOriginal == "8" && novaBase == "10"){
				separa(valor, inteira, fracionaria);
				double result = oct_deci(inteira, false);
				if(fracionaria != "") result += octFrac_deci(fracionaria, false);
				resultado = doubleString(result);
			}
			else if (baseOriginal == "8" && novaBase == "2"){
				resultado = oct_bin(valor, false);
			}
			else if (baseOriginal == "8" && novaBase == "16"){
				resultado = oct_hexa(valor, false);
			}
				
			else if(baseOriginal == "16" && novaBase == "10"){
				separa(valor, inteira, fracionaria);
				double result = hexa_deci(inteira, false);
				if(fracionaria != "") result += hexaFrac_deci(fracionaria, false);
				resultado = doubleString(result);
			}
			else if(baseOriginal == "16" && novaBase == "2"){
				resultado = hexa_bin(valor, false);
			}
			else if (baseOriginal == "16" && novaBase == "8"){
				resultado = hexa_oct(valor, false);
			}
			
				
			output << valorOriginal << ";" << baseOriginal << ";" << resultado << ";" << novaBase << endl;
		}
	input.close();
	output.close();
	cout << "Arquivo imprimido em saida.csv." << endl;

	} else{
		cout << "Não foi possível abrir o arquivo entrada." << endl;
	}
	
}
