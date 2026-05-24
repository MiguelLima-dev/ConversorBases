#include <iostream>
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
    
    return 0;
}
