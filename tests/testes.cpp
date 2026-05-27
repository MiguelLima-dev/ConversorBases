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
check(deci_oct(10, false) == "12", "deci_oct(10)");
check(deci_oct(8.5, false) == "10.4", "deci_oct(8.5)");
check(deci_hexa(10, false) == "A", "deci_hexa(10)");
check(deci_hexa(16.5, false) == "10.8", "deci_hexa(16.5)");
check(bin_deci("10", false) == 2, "bin_deci(10)");
check(bin_deci("10", false) + binFrac_deci("1", false) == 2.5, "bin_deci(10.1)");
check(oct_deci("10", false) == 8, "oct_deci(10)");
check(oct_deci("10", false) + octFrac_deci("1", false) == 8.125, "oct_deci(10.1)");
check(hexa_deci("10", false) == 16, "hexa_deci(10)");
check(hexa_deci("10", false) + hexaFrac_deci("1", false) == 16.0625, "hexa_deci(10.1)");
check(bin_oct("10", false) == "2", "bin_oct(10)");
check(bin_oct("1010.1", false) == "12.4", "bin_oct(1010.1)");
check(bin_hexa("10", false) == "2", "bin_hexa(10)");
check(bin_hexa("1010.1", false) == "A.8", "bin_hexa(1010.1)");
check(oct_bin("10", false) == "001000", "oct_bin(10)");
check(oct_bin("10.4", false) == "001000.100", "oct_bin(10.4)");
check(oct_hexa("10", false) == "8", "oct_hexa(10)");
check(oct_hexa("10.4", false) == "8.8", "oct_hexa(10.4)");
check(hexa_bin("10", false) == "00010000", "hexa_bin(10)");
check(hexa_bin("A.8", false) == "00001010.1000", "hexa_bin(A.8)");
check(hexa_oct("10", false) == "20", "hexa_oct(10)");
check(hexa_oct("A.8", false) == "12.4", "hexa_oct(A.8)");
check(deci_bin(0, false) == "0", "deci_bin(0)");
check(deci_oct(0, false) == "0", "deci_oct(0)");
check(deci_hexa(0, false) == "0", "deci_hexa(0)");
check(bin_deci("0", false) == 0, "bin_deci(0)");
check(oct_deci("0", false) == 0, "oct_deci(0)");
check(hexa_deci("0", false) == 0, "hexa_deci(0)");
std::cout << "\n" << correto << " corretos, " << falha << " falharam.\n";
return falha;
}