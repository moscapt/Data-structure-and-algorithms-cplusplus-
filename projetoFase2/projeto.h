#ifndef H_PROJETO
#define H_PROJETO

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>    // para a funçao: transform
#include <ctype.h>      // para a funçao: tolower

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

	bool avaliado = false; // controla se o projecto foi avaliado

	bool av1 = false;
	bool av2 = false;
	bool av3 = false;

	projeto *next;
};


void readUserInputs(projeto *proj);

projeto *addProjeto(projeto *head);

void listProjetos(projeto *head);

void printProjectData(projeto *proj);

void calcCustoTotal(projeto *proj);

void listById(projeto *head);

void listByInstituition(projeto *head);

void avaliarById(projeto *head);

void avaliar(projeto *proj);

void calcClassFinal(projeto *proj);

projeto *ordenarDownClass(projeto *head);

bool projetosPorAvaliar(projeto *head);

projeto *addProjetoFile(projeto *head);

void readFileInputs(ifstream &ficheiro, projeto *proj);

projeto *ordenarAlfa(projeto *head);

string capitalizar(string palavra);

void intNoNegValidation(int &a);

void floatNoNegValidation(float &a);

void charAvaValidation(char &a);

projeto *deleteProjeto(projeto *head);

void checkAvaliadores(projeto *proj);

void selectAvaliadorValidation(int &a);

projeto *deleteTodosProjetos(projeto *head);

#endif






