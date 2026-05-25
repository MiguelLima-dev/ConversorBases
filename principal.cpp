#include <iostream>
#include <fstream>
#include "conversao.hpp"
#include "parser.hpp"
#include "formatador.hpp"
using namespace std;

int main(){
	
	cout << "=-=-=-=-= MODO DE ENTRADA E SAIDA =-=-=-=-=" << endl;
    cout << "Digite (Manual) para entrada e saida padrão" << endl;
    cout << "Digite (Batch) para entrada e saida por arquivo .csv" << endl;
    
    string modoEntrada;
    cin >> modoEntrada;
    
    if(modoEntrada == "Manual"){
	
    cout << "=-=-=-=-= MENU =-=-=-=-=" << endl;
    cout << "1. Converter Decimal para Binário." << endl;
    cout << "2. Converter Decimal para Octal." << endl;
    cout << "3. Converter Decimal para Hexadecimal." << endl;
    cout << "4. Converter Binário para Decimal." << endl;
    cout << "5. Converter Octal para Decimal." << endl;
    cout << "6. Converter Hexadecimal para Decimal." << endl;
    cout << "7. Converter Binário para Octal." << endl;
    cout << "8. Converter Binário para Hexadecimal." << endl;
    cout << "9. Converter Octal para Binário." << endl;
    cout << "10. Converter Octal para Hexadecimal." << endl;
    cout << "11. Converter Hexadecimal para Binário." << endl;
    cout << "12. Converter Hexadecimal para Octal." << endl;

    int modo;
    cin >> modo;

    string entrada;
    switch (modo) {
        case 1:
            cout << "Decimal: ";
            cin >> entrada;
            if (valida(entrada, 10)) {
                imprimir(deci_bin(stringDouble(entrada)), 10, 2);
            }
            break;

        case 2:
            cout << "Decimal ";
            cin >> entrada;
            if (valida(entrada, 10)) {
                imprimir(deci_oct(stringDouble(entrada)), 10, 8);
            }
            break;
        
        case 3:
            cout << "Decimal: ";
            cin >> entrada;
            if (valida(entrada, 10)) {
                imprimir(deci_hexa(stringDouble(entrada)), 10, 16);
            }
            break;
        
        case 4:
            cout << "Binário: ";
            cin >> entrada;
            if (valida(entrada, 2)) {
                string inteira, fracionaria;
                separa(entrada, inteira, fracionaria);

                double resultado = bin_deci(inteira);
                if (fracionaria != "")
                    resultado += binFrac_deci(fracionaria);

                imprimir(doubleString(resultado), 2, 10);
            }
            break;
        
        case 5:
            cout << "Octal: ";
            cin >> entrada;
            if (valida(entrada, 8)) {
                string inteira, fracionaria;
                separa(entrada, inteira, fracionaria);

                double resultado = oct_deci(inteira);
                if (fracionaria != "")
                    resultado += octFrac_deci(fracionaria);
                
                imprimir(doubleString(resultado), 8, 10);
            }
            break;

        case 6:
            cout << "Hexadecimal: ";
            cin >> entrada;
            if (valida(entrada, 16)) {
                string inteira, fracionaria;
                separa(entrada, inteira, fracionaria);

                double resultado = hexa_deci(inteira);
                if (fracionaria != "") 
                    resultado += hexaFrac_deci(fracionaria);
                
                imprimir(doubleString(resultado), 16, 10);
            }
            break;

		case 7:
			cout << "Binário: ";
			cin >> entrada;
			if (valida(entrada, 2)) {
				imprimir(bin_oct(entrada), 2, 8);
			}
			break;
			
		case 8:
			cout << "Binário: ";
			cin >> entrada;
			if (valida(entrada, 2)) {
				imprimir(bin_hexa(entrada), 2, 16);
			}
			break;
			
		case 9:
			cout << "Octal: ";
			cin >> entrada;
			if (valida(entrada,8)) {
				imprimir(oct_bin(entrada), 8, 2);
			}
			break;
			
		case 10:
			cout << "Octal: ";
			cin >> entrada;
			if (valida(entrada, 8)) {
				imprimir(oct_hexa(entrada), 8, 16);
			}
			break;
			
		case 11:
			cout << "Hexadecimal: ";
			cin >> entrada;
			if (valida(entrada, 16)) {
				imprimir(hexa_bin(entrada), 16, 2);
			}
			break;
			
		case 12:
			cout << "Hexadecimal: ";
			cin >> entrada;
			if (valida(entrada, 16)) {
				imprimir(hexa_oct(entrada), 16, 8);
			}
			break;
			
        default:
            cout << "Opção inexistente" << endl;
		}
	}
	
	else if(modoEntrada == "Batch"){
		
		ifstream input;
		input.open("entrada.csv");
		
		ofstream output;
		output.open("saida.csv");
	
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
					resultado = deci_bin(stringDouble(valor));
				}
				else if(baseOriginal == "10" && novaBase == "8"){
					resultado = deci_oct(stringDouble(valor));
				}
				else if(baseOriginal == "10" && novaBase == "16"){
					resultado = deci_hexa(stringDouble(valor));
				}
				
				else if(baseOriginal == "2" && novaBase == "10"){
					separa(valor, inteira, fracionaria);
					double result = bin_deci(inteira);
					if (fracionaria != "") result += binFrac_deci(fracionaria);
					resultado = doubleString(result);
				}
				else if(baseOriginal == "2" && novaBase == "8"){
					resultado = bin_oct(valor);
				}
				else if(baseOriginal == "2" && novaBase == "16"){
					resultado = bin_hexa(valor);
				}
				
				else if(baseOriginal == "8" && novaBase == "10"){
					separa(valor, inteira, fracionaria);
					double result = oct_deci(inteira);
					if(fracionaria != "") result += octFrac_deci(fracionaria);
					resultado = doubleString(result);
				}
				else if (baseOriginal == "8" && novaBase == "2"){
					resultado = oct_bin(valor);
				}
				else if (baseOriginal == "8" && novaBase == "16"){
					resultado = oct_hexa(valor);
				}
				
				else if(baseOriginal == "16" && novaBase == "10"){
					separa(valor, inteira, fracionaria);
					double result = hexa_deci(inteira);
					if(fracionaria != "") result += hexaFrac_deci(fracionaria);
					resultado = doubleString(result);
				}
				else if(baseOriginal == "16" && novaBase == "2"){
					resultado = hexa_bin(valor);
				}
				else if (baseOriginal == "16" && novaBase == "8"){
					resultado = hexa_oct(valor);
				}
				
				
				output << valorOriginal << ";" << baseOriginal << ";" << resultado << ";" << novaBase << endl;
			}
			input.close();
			output.close();
			cout << "Arquivo imprimido em saida.csv." << endl;
	
		}else{
			cout << "Não foi possível abrir os arquivo entrada.csv e saida.csv." << endl;
		}
	
	}
    
    return 0;
}
