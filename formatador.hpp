#ifndef FORMATADOR_HPP
#define FORMATADOR_HPP

#include <string>

// IMPRIME O RESULTADO NO TERMINAL.
void imprimir(std::string resultado, int baseOrigem, int baseDestino);

/* EXECUTA O MODO BATCH, LÊ DE UM ARQUIVO.CSV DE ENTRAD
E IMPRIME EM OUTRO ARQUIVO.CSV DE SAIDA"*/
void modoBatch();

// CALCULA E IMPRIME OS MAIORES NÚMEROS EM CADA UMA DAS QUATRO BASES.
void calculaMaximos(int k);

#endif