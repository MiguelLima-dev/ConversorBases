#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

double stringDouble(std::string s);
std::string doubleString(double num);
bool valida(std::string &numero, int base);
void separa(std::string numero, std::string &inteira, std::string &fracionaria);

#endif