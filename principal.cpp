#include <iostream>
#include "conversao.hpp"
#include "parser.hpp"
using namespace std;

int main(){
    cout << "=-=-=-=-= MENU =-=-=-=-=" << endl;
    cout << "1. Converter Decimal para Binário" << endl;
    cout << "2. Converter Decimal para Octal" << endl;
    cout << "3. Converter Decimal para Hexadecimal" << endl;
    cout << "4. Converte Binário para Decimal." << endl;
    cout << "5. Converte Octal para Decimal." << endl;
    cout << "6. Converte Hexadecimal para Decimal." << endl;

    int modo;
    cin >> modo;

    string entrada;
    switch (modo) {
        case 1:
            cout << "Decimal: ";
            cin >> entrada;
            if (valida(entrada, 10)) {
                cout << "Binário: " <<
                deci_bin(stringDouble(entrada)) << endl;
            }
            break;

        case 2:
            cout << "Decimal ";
            cin >> entrada;
            if (valida(entrada, 10)) {
                cout << "Octal: " <<
                deci_oct(stringDouble(entrada)) << endl;
            }
            break;
        
        case 3:
            cout << "Decimal: ";
            cin >> entrada;
            if (valida(entrada, 10)) {
                cout << "Hexadecimal: " <<
                deci_hexa(stringDouble(entrada)) << endl;
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

                cout << "Decimal: " << resultado << endl;
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
                
                cout << "Decimal: " << resultado << endl;
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
                
               cout << "Decimal: " << resultado << endl; 
            }
            break;

        default:
            cout << "Opção inexistente" << endl;
    }
    
    return 0;
}