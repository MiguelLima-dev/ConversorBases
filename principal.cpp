#include <iostream>
#include "conversao.h"
using namespace std;

int main(){
    cout << "=-=-=-=-= MENU =-=-=-=-=" << endl;
    cout << "1. Converter decimal para Binário" << endl;
    cout << "2. Converter decimal para Octal" << endl;
    cout << "3. Converter decimal para Hexadecimal" << endl;

    int modo;
    cin >> modo;

    switch (modo) {
        case 1:
            
            break;

        case 2:

            break;
        
        case 3:

            break;
        
        default:
            cout << "Opção inexistente" << endl;
    }
    
    return 0;
}