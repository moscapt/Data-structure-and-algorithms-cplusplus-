#ifndef H_PROJETO
#define H_PROJETO

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct gastos{

	float equipamento;
	float bolsas;
	float consumiveis;
	float consultores;
	float deslocacoes;
	float gerais;

};

struct projeto{

	int id;
	float custototal;
	float classfinal;

	string titulo;
	string instituicao;
	string investigador;
	int duracao;
	string palavraschave[5];
	gastos gastosprev;
	char classificacao[3][4];

};


void calcCustoTotal(projeto v[], int n);

void avaliar(projeto v[], int n);

void calcClassFinal(projeto v[], int n);

void adicionarProj(projeto v[], int n);

void ordernar(projeto v[], int n);

void escreverConsola(projeto v[], int n);

#endif





// projeto p;

// p.gastosprev.equipamento     aceder a uma estrutura dentro duma estrutura do projecto p






