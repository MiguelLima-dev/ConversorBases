#include <iostream>
using namespace std;

int main(){
    double decimal;
    cin >> decimal;

    string binario = "";
    int parte_inteira = decimal;
    double parte_fracionaria = decimal - parte_inteira;

    if (parte_inteira  == 0) {
        binario = '0' + binario;
    }
    while (parte_inteira != 0) {
        binario = char((parte_inteira % 2) + '0') + binario;
		parte_inteira /= 2;
    }

    if (parte_fracionaria != 0) {
        binario = binario + '.';

        while (parte_fracionaria != 0) {
            parte_fracionaria *= 2;
            binario = binario + char((int) parte_fracionaria + '0');
            parte_fracionaria = parte_fracionaria  - ((int) parte_fracionaria);
        }
    }

    cout << binario << endl;
    return 0;
}