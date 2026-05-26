#include <iostream>
#include <fstream>
#include "conversao.hpp"
#include "parser.hpp"
#include "formatador.hpp"
using namespace std;

int main(){
	
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
    cout << "13. Modo Batch, lê de um arquivo.csv" << endl;
    cout << "14. Calculadora de máximos." << endl;
    cout << "15. Modo quiz interativo." << endl;
    cout << "16. SAIR." << endl;
    cout << "-|-|-INSIRA UMA ALTERNATIVA-|-|-" << endl;
    
    int modo;
    cin >> modo;
    string entrada;
    bool trace;
    switch (modo) {
        case 1: // DECIMAL → BINÁRIO.
            input(entrada, trace);
            if (valida(entrada, 10)) {
                imprimir(deci_bin(stringDouble(entrada), trace), 10, 2);
            }
            break;

        case 2: // DECIMAL → OCTAL.
            input(entrada, trace);
            if (valida(entrada, 10)) {
                imprimir(deci_oct(stringDouble(entrada), trace), 10, 8);
            }
            break;
        
        case 3: // DECIMAL → HEXADECIMAL
            input(entrada, trace);
            if (valida(entrada, 10)) {
                imprimir(deci_hexa(stringDouble(entrada), trace), 10, 16);
            }
            break;
        
        case 4: // BINÁRIO → DECIMAL.
            input(entrada, trace);
            if (valida(entrada, 2)) {
                string inteira, fracionaria;
                separa(entrada, inteira, fracionaria);

                double resultado = bin_deci(inteira, trace);
                if (fracionaria != "")
                    resultado += binFrac_deci(fracionaria, trace);

                imprimir(doubleString(resultado), 2, 10);
            }
            break;
        
        case 5: // OCTAL → DECIMAL.
            input(entrada, trace);
            if (valida(entrada, 8)) {
                string inteira, fracionaria;
                separa(entrada, inteira, fracionaria);

                double resultado = oct_deci(inteira, trace);
                if (fracionaria != "")
                    resultado += octFrac_deci(fracionaria, trace);
                
                imprimir(doubleString(resultado), 8, 10);
            }
            break;

        case 6: // HEXADECIMAL → DECIMAL.
            input(entrada, trace);
            if (valida(entrada, 16)) {
                string inteira, fracionaria;
                separa(entrada, inteira, fracionaria);

                double resultado = hexa_deci(inteira, trace);
                if (fracionaria != "") 
                    resultado += hexaFrac_deci(fracionaria, trace);
                
                imprimir(doubleString(resultado), 16, 10);
            }
            break;

		case 7: // BINÁRIO → OCTAL.
			input(entrada, trace);
			if (valida(entrada, 2)) {
				imprimir(bin_oct(entrada, trace), 2, 8);
			}
			break;
			
		case 8: // BINÁRIO → HEXADECIMAL.
			input(entrada, trace);
			if (valida(entrada, 2)) {
				imprimir(bin_hexa(entrada, trace), 2, 16);
			}
			break;
			
		case 9: // OCTAL → BINÁRIO.
			input(entrada, trace);
			if (valida(entrada,8)) {
				imprimir(oct_bin(entrada, trace), 8, 2);
			}
			break;
			 
		case 10: // OCTAL → HEXADECIMAL.
			input(entrada, trace);
			if (valida(entrada, 8)) {
				imprimir(oct_hexa(entrada, trace), 8, 16);
			}
			break;
			
		case 11: // HEXADECIMAL → BINÁRIO.
			input(entrada, trace);
			if (valida(entrada, 16)) {
				imprimir(hexa_bin(entrada, trace), 16, 2);
			}
			break;
			
		case 12: // HEXADECIMAL → OCTAL.
			input(entrada, trace);
			if (valida(entrada, 16)) {
				imprimir(hexa_oct(entrada, trace), 16, 8);
			}
			break;
		
        case 13: // MODO BATCH.
            modoBatch();
            break;

        case 14: // CALCULADORA DE MÁXIMOS.
            int k;
            cout << "Insira o número de bits: ";
            cin >> k;
            calculaMaximos(k);
            break;

        case 15: // MODO QUIZ.
            quizInterativo();
            break;

        case 16: break; // SAI DO PROGRAMA.

        default:    
            cout << "Opção inexistente" << endl;
		}
	
	
    return 0;
}
