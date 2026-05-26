#include <iostream>
#include <string>
#include <random>
#include "conversao.hpp"

using namespace std;

struct Quiz{
		int pontuacao = 0;
		int nivelAtual = 1;
		int numeroSecreto = 0;
		int baseOriginal = 0;
		int baseDestino = 0;
};
	
void QuizInterativo(){
	
	Quiz quiz;
	
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
			cout << "=== QUIZ DAS CONVERSOES ===" << endl;
			cout << "Nivel atual: " << quiz.nivelAtual << " Pontos:" << quiz.pontuacao << endl;
			cout << "Converta o numero: " << sorteado << " da base " << origem << " para a base " << destino << endl;
			cout << endl;
			cout << "Digite sua resposta: ";
				
		string resposta;
		cin >> resposta;
		
		//Caso o usuário queira sair do quiz
		if (resposta == "sair" || resposta == "SAIR" || resposta == "Sair"){
			cout << endl;
			cout << "\n Voce saiu do quiz." << endl;
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
			cout << "\n Muito bem! Sua resposta esta correta! "<< "Voce ganhou 5 pontos" << endl;
			quiz.pontuacao += 5;
		} else {
			cout << "Resposta incorreta, tente a proxima conversao. " << "Voce perdeu 4 pontos " << endl;
			cout << "Resposta correta: " << gabarito << endl;
			quiz.pontuacao -= 4;
			}
		
		//pontuação 
		cout << "Sua pontuacao e de " << quiz.pontuacao << " pontos. " << endl;
		
		
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

		cout << "Voce esta no nivel " << quiz.nivelAtual << "!\n" << endl;
			
}

	cout << "\n=== FIM DE JOGO ===" << endl;
	cout << "\nSua pontuacao esta negativa" << endl;
}

int main(){
	
	QuizInterativo();
	return 0;
}
