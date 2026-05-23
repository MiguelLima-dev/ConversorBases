#ifndef CONVERSAO.HPP
#define CONVERSAO.HPP

#include <string>

// DECIMAL P/ OUTRAS BASES.
std::string deci_bin(double decimal);
std::string deci_oct(double decimal);
std::string deci_hexa(double decimal);

// OUTRAS BASES P/ DECIMAL.
int bin_deci(std::string binario);
int oct_deci(std::string octal);
int hexa_deci(std::string hexadecimal);

// FRACIONÁRIOS P/ DECIMAL.
double binFrac_deci(std::string fracao);
double octFrac_deci(std::string fracao);
double hexaFrac_deci(std::string fracao);

// AUXILIAR	
int index(char c);

#endif