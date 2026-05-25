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

// FUNÇÕES AUXILIARES.
char conversao(std::string blocoOCT);
std::string inversao(char caractere);
char conversaoH(std::string blocoHEX);
std::string inversaoH(char caractere);

//CONVERSÕES SEM PASSAR POR DECIMAL.
std::string bin_oct(std::string binario);
std::string oct_bin(std::string octal);
std::string bin_hexa(std::string binario);
std::string hexa_bin(std::string hexadecimal);

//CONVERSÃO ENTRE OCTAL E HEXADECIMAL (F4).
std::string oct_hexa(std::string octal);
std::string hexa_oct(std::string hexadecimal);

// AUXILIAR	
int index(char c);

#endif
