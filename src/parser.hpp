#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

// TRANSFORMA TIPOS DE DADOS.
double stringDouble(std::string s); // STRING → DOUBLE.
std::string doubleString(double num); // DOUBLE → STRING.

// RELACIONADOS A ENTRADA.
void input(std::string &input, bool &trace); // COLETA A ENTRADA.
bool valida(std::string &numero, int base); // VALIDA A ENTRADA.

// AUXILIAR
void separa(std::string numero, std::string &inteira, std::string &fracionaria); // SEPARA A PARTE INTEIRA DO RESTANTE EM UM NÚMERO NUMA STRING

#endif