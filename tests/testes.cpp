#include <iostream>
#include "../src/conversao.hpp"
#include "../src/parser.hpp"

int correto = 0, falha = 0;

void check(bool cond, std::string nome) {
    if (cond) {std::cout << "[OK] " << nome << "\n"; correto++; }
    else {std::cout << "[FALHOU] " << nome << "\n"; falha++; }
}

int main() {
    check(deci_bin(10, false) == "1010", "deci_bin(10)");
    check(deci_bin(10.5, false) == "1010.1", "deci_bin(10.5)");


    std::cout << "\n" << correto << "Corretos, " << falha << " falharam.\n";
    return falha;
}