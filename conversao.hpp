#ifndef CONVERSAO_HPP
#define CONVERSAO_HPP

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

// SEM PASSAR POR DECIMAL.
char conversao(std::string blocoOCT);
std::string bin_oct(std::string binario);
std::string inversao(char caractere);
std::string oct_bin(std::string octal);
char conversaoH(std::string blocoHEX);
std::string bin_hexa(std::string binario);
std::string inversaoH(char caractere);
std::string hexa_bin(std::string hexadecimal);
std::string hexa_bin(string hexadecimal);
std::string oct_hexa(std::string octal);
std::string hexa_oct(string hexadecimal);

// AUXILIAR	
int index(char c);

#endif