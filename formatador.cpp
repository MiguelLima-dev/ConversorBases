#include "formatador.hpp"
#include <iostream>
using namespace std;

void imprimir(string resultado, int baseOrigem, int baseDestino) {
    cout << "Base " << baseOrigem << " -> Base " <<
        baseDestino << ": " << resultado << endl;
}
