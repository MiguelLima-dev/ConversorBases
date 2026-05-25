#ifndef CONVERSAO_HPP
#define CONVERSAO_HPP

#include <string>

// DECIMAL P/ OUTRAS BASES.
std::string deci_bin(double decimal, bool trace);
std::string deci_oct(double decimal, bool trace);
std::string deci_hexa(double decimal, bool trace);

// OUTRAS BASES P/ DECIMAL.
int bin_deci(std::string binario, bool trace);
int oct_deci(std::string octal, bool trace);
int hexa_deci(std::string hexadecimal, bool trace);

// FRACIONÁRIOS P/ DECIMAL.
double binFrac_deci(std::string fracao, bool trace);
double octFrac_deci(std::string fracao, bool trace);
double hexaFrac_deci(std::string fracao, bool trace);

// FUNÇÕES AUXILIARES.
char conversao(std::string blocoOCT);
std::string inversao(char caractere);
char conversaoH(std::string blocoHEX);
std::string inversaoH(char caractere);

//CONVERSÕES SEM PASSAR POR DECIMAL.
std::string bin_oct(std::string binario, bool trace);
std::string oct_bin(std::string octal, bool trace);
std::string bin_hexa(std::string binario, bool trace);
std::string hexa_bin(std::string hexadecimal, bool trace);

//CONVERSÃO ENTRE OCTAL E HEXADECIMAL (F4).
std::string oct_hexa(std::string octal, bool trace);
std::string hexa_oct(std::string hexadecimal, bool trace);

// AUXILIAR	HEXADECIMAL.
int index(char c);

#endif