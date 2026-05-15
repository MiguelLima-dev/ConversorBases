#include <iostream>
#include "conversao.h"
using namespace std;

int main(){
	int decimal;
	cin >> decimal;
	
	cout << "Binário: " << deci_bin(decimal) << endl;
	cout << "Octal: " << deci_oct(decimal) << endl;
    cout << "Hexadecimal: " << deci_hexa(decimal) << endl;

	return 0;
}