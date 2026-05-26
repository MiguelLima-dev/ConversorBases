#include "formatador.hpp"
#include "conversao.hpp"
#include "parser.hpp"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cmath>
using namespace std;

void imprimir(string resultado, int baseOrigem, int baseDestino) {
    cout << "\n Base " << baseOrigem << " -> Base " <<
        baseDestino << ": " << resultado << endl;
}

void modoBatch() {
    string entrada, saida;
    cout << "Nome do arquivo de entrada: " << endl;
    cin >> entrada;
    cout << "Nome do arquivo de saida: " << endl;
    cin >> saida;

    ifstream input;
	input.open(entrada);
		
	ofstream output;
    output.open(saida);
	
	if(input.is_open() && output.is_open()){
	    string valor;
		string baseOriginal;
	    string novaBase;
			
			
		while (getline(input, valor, ';')){
			getline(input, baseOriginal, ';');
			getline(input, novaBase);
			
			while(!novaBase.empty() && (novaBase.back() == '\r' || novaBase.back() == '\n')){
				novaBase.pop_back();
			}
				
			if(!valor.empty() && valor.front() == '\n'){
				valor.erase(0, 1);
			}
				
			string valorOriginal = valor;
			string resultado  = "Conversão não incluida";
				
			string inteira = "", fracionaria = "";
				
			if(baseOriginal == "10" && novaBase == "2"){
				resultado = deci_bin(stringDouble(valor), false);
			}
			else if(baseOriginal == "10" && novaBase == "8"){
				resultado = deci_oct(stringDouble(valor), false);
			}
			else if(baseOriginal == "10" && novaBase == "16"){
				resultado = deci_hexa(stringDouble(valor), false);
			}
				
			else if(baseOriginal == "2" && novaBase == "10"){
				separa(valor, inteira, fracionaria);
				double result = bin_deci(inteira, false);
				if (fracionaria != "") result += binFrac_deci(fracionaria, false);
				resultado = doubleString(result);
			}
			else if(baseOriginal == "2" && novaBase == "8"){
				resultado = bin_oct(valor, false);
			}
			else if(baseOriginal == "2" && novaBase == "16"){
				resultado = bin_hexa(valor, false);
			}
				
			else if(baseOriginal == "8" && novaBase == "10"){
				separa(valor, inteira, fracionaria);
				double result = oct_deci(inteira, false);
				if(fracionaria != "") result += octFrac_deci(fracionaria, false);
				resultado = doubleString(result);
			}
			else if (baseOriginal == "8" && novaBase == "2"){
				resultado = oct_bin(valor, false);
			}
			else if (baseOriginal == "8" && novaBase == "16"){
				resultado = oct_hexa(valor, false);
			}
				
			else if(baseOriginal == "16" && novaBase == "10"){
				separa(valor, inteira, fracionaria);
				double result = hexa_deci(inteira, false);
				if(fracionaria != "") result += hexaFrac_deci(fracionaria, false);
				resultado = doubleString(result);
			}
			else if(baseOriginal == "16" && novaBase == "2"){
				resultado = hexa_bin(valor, false);
			}
			else if (baseOriginal == "16" && novaBase == "8"){
				resultado = hexa_oct(valor, false);
			}
			
				
			output << valorOriginal << ";" << baseOriginal << ";" << resultado << ";" << novaBase << endl;
		}
	input.close();
	output.close();
	cout << "Arquivo imprimido em saida.csv." << endl;

	} else{
		cout << "Não foi possível abrir o arquivo entrada." << endl;
	}
	
}

void calculaMaximos(int k) {
	int maiornum = pow(2, k) - 1;
	string maiorBinario = deci_bin(maiornum, false);
	string maiorDecimal = doubleString(maiornum);
	string maiorOctal = bin_oct(maiorBinario, false);
	string maiorHexa =bin_hexa(maiorBinario, false);

	cout << "Maiores números representados com " << k << "bits nas bases:";
	cout << "\nBinário :" << maiorBinario;
	cout << "\nDecimal : " << maiorDecimal;
	cout << "\nOctal : " << maiorOctal;
	cout << "\nHexadecimal : " << maiorHexa << endl;
}

// ESTRUTURA USADA NO QUIZ.
struct Quiz{
		int pontuacao = 0;
		int nivelAtual = 1;
		int numeroSecreto = 0;
		int baseOriginal = 0;
		int baseDestino = 0;
};

// FUNÇÃO QUE EXECUTA O QUIZ.
void quizInterativo(){
	
	Quiz quiz;
	bool escolheuSair = false;
	//Números aleatórios
	random_device rd;
	mt19937 gerador(rd());
	
while (quiz.pontuacao >= 0){
	
	int limite_maximo = 0;
	
	switch (quiz.nivelAtual){
		case 1 :
			limite_maximo = 15;
			break;
		case 2 :
			limite_maximo = 100;
			break;
		case 3 :
			limite_maximo = 500;
			break;
		case 4 :
			limite_maximo = 5000;
			break;
		case 5 :
			limite_maximo = 10000;
			break;
		default:
			limite_maximo = 15;
			break;
		}
		
	
	//intervalo dos níveis 
	uniform_int_distribution<int> distribuicao(1, limite_maximo);

	quiz.numeroSecreto = distribuicao(gerador);

	//distribuição das bases
	uniform_int_distribution<int> dist_bases(1, 4);

	//Sorteia a base
	quiz.baseOriginal = dist_bases(gerador);

	do{
		quiz.baseDestino = dist_bases(gerador);
	}while(quiz.baseDestino == quiz.baseOriginal);

	string origem, destino;

	//bases de entrada
	switch(quiz.baseOriginal) {
		case 1:
			origem = "binaria";
			break;
		case 2:
			origem = "decimal";
			break;
		case 3:
			origem = "octal";
			break;
		case 4:
			origem = "hexadecimal";
			break;
		}
	
		//bases de saida
		switch(quiz.baseDestino) {
		case 1:
			destino = "binaria";
			break;
		case 2:
			destino = "decimal";
			break;
		case 3:
			destino = "octal";
			break;
		case 4:
			destino = "hexadecimal";
			break;
		}
	
		//passando o número sorteado para a base de destino
		string sorteado;
		
		switch (quiz.baseOriginal){
			case 1:
				sorteado = deci_bin(quiz.numeroSecreto, false);
				break;
			case 2:
				sorteado = to_string(quiz.numeroSecreto);
				break;
			case 3:
				sorteado = deci_oct(quiz.numeroSecreto, false);
				break;
			case 4:
				sorteado = deci_hexa(quiz.numeroSecreto, false);
				break;
			}
			
			//Interação com o usuário	
			cout << endl;
			cout << "=== QUIZ DAS CONVERSOES === Digite ""sair"" para sair." << endl;
			cout << "Nivel atual: " << quiz.nivelAtual << " Pontos:" << quiz.pontuacao << endl;
			cout << "Converta o numero: " << sorteado << " da base " << origem << " para a base " << destino << endl;
			cout << endl;
			cout << "Digite sua resposta: ";
				
		string resposta;
		cin >> resposta;

		//Caso o usuário queira sair do quiz
		if (resposta == "sair" || resposta == "SAIR" || resposta == "Sair"){
			cout << endl;
			cout << "\n Você saiu do quiz." << endl;
			escolheuSair = true;
			break;
		}
		
		
		string gabarito;
		
		switch (quiz.baseDestino){
			case 1:
				gabarito = deci_bin(quiz.numeroSecreto, false);
				break;
			case 2:
				gabarito = to_string(quiz.numeroSecreto);
				break;
			case 3:
				gabarito = deci_oct(quiz.numeroSecreto, false);
				break;
			case 4:
				gabarito = deci_hexa(quiz.numeroSecreto, false);
				break;
			}
		
		//Validação da resposta
		if(resposta == gabarito){
			cout << "\n Muito bem! Sua resposta esta correta! "<< "Você ganhou 5 pontos" << endl;
			quiz.pontuacao += 5;
		} else {
			cout << "Resposta incorreta, tente a proxima conversao. " << "Você perdeu 4 pontos " << endl;
			cout << "Resposta correta: " << gabarito << endl;
			quiz.pontuacao -= 4;
			}

		if (quiz.pontuacao < 0) break;
		//pontuação 
		cout << "Sua pontuacao é de " << quiz.pontuacao << " pontos. " << endl;
		
		
		//Niveis baseados na pontuação
		if(quiz.pontuacao >= 0 && quiz.pontuacao <= 25){
			quiz.nivelAtual = 1;
		}else if(quiz.pontuacao >= 26 && quiz.pontuacao <= 50){
			quiz.nivelAtual = 2;
		}else if(quiz.pontuacao >= 51 && quiz.pontuacao <= 75){
			quiz.nivelAtual = 3;
		}else if(quiz.pontuacao >= 76 && quiz.pontuacao <= 99){
			quiz.nivelAtual = 4;
		}else if(quiz.pontuacao >= 100){
			quiz.nivelAtual = 5;
		}

		cout << "Você está no nivel " << quiz.nivelAtual << "!\n" << endl;
			
}

	cout << "\n=== FIM DE JOGO ===" << endl;
	if (escolheuSair)
		cout << "Você encerrou com " << quiz.pontuacao << " pontos." << endl;
	else
		cout << "\nSua pontuacao esta negativa" << endl;
}
