#include "projeto.h"



void adicionarProj(projeto v[], int n)
{
	cout << endl;
	cout << "INTRODUZA AS INFORMACOES DOS PROJETOS: " << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < n; i++)
	{

		v[i].id = i + 1;
		cout << endl;
		cout << "Esta a introduzir dados no Projeto: " << v[i].id << endl;

		cout << endl;
		cout << "Titulo: " << endl;
		cin.ignore();
		getline(cin, v[i].titulo);

		cout << endl;
		cout << "Instituicao proponente: " << endl;
		getline(cin, v[i].instituicao);

		cout << endl;
		cout << "Nome do Investigador Responsavel: " << endl;
		getline(cin, v[i].investigador);

		cout << endl;
		cout << "Duracao do projecto: " << endl;
		cin >> v[i].duracao;

		cout << endl;
		cout << "Areas de investigação: " << endl;

		cin.ignore();
		for (int k = 0; k < 5; k++)
		{		
			getline(cin, v[i].palavraschave[k]);
		}

		cout << endl;
		cout << "GASTOS PREVISTOS: " << endl;

		cout << endl;
		cout << "Compra de equipamento: " << endl;
		cin >> v[i].gastosprev.equipamento;

		cout << endl;
		cout << "Pagamento de bolsas: " << endl;
		cin >> v[i].gastosprev.bolsas;

		cout << endl;
		cout << "Despesas com consumiveis: " << endl;
		cin >> v[i].gastosprev.consumiveis;

		cout << endl;
		cout << "Despesas com consultores: " << endl;
		cin >> v[i].gastosprev.consultores;

		cout << endl;
		cout << "Deslocacoes: " << endl;
		cin >> v[i].gastosprev.deslocacoes;

		cout << endl;
		cout << "Gastos gerais: " << endl;
		cin >> v[i].gastosprev.gerais;

		cout << endl;
		cout << "-----------------------------------" << endl;

	}

	cout << endl;
}

void escreverConsola(projeto v[], int n)
{
	cout << endl;
	cout << "DADOS DOS PROJETOS: " << endl;
	cout << endl;	
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Projeto: " << v[i].id << endl;
		cout << endl;
		cout << "Titulo: " << v[i].titulo << endl;
		cout << endl;
		cout << "Instituicao proponente: " << v[i].instituicao << endl;
		cout << endl;
		cout << "Nome do Investigador Responsavel: " << v[i].investigador << endl;
		cout << endl;
		cout << "Duracao do projecto: " << v[i].duracao << endl;
		cout << endl;
		cout << "Palavras chave: " << v[i].palavraschave[0] << ", " << v[i].palavraschave[1] << ", "
			<< v[i].palavraschave[2] << ", " << v[i].palavraschave[3] << ", " << v[i].palavraschave[4] << "." << endl;
		cout << endl;

		cout << "GASTOS PREVISTOS: " << endl;
		cout << endl;
		cout << "Compra de equipamento: " << v[i].gastosprev.equipamento << endl;
		cout << endl;
		cout << "Pagamento de bolsas: " << v[i].gastosprev.bolsas << endl;
		cout << endl;
		cout << "Despesas com consumiveis: " << v[i].gastosprev.consumiveis << endl;
		cout << endl;
		cout << "Despesas com consultores: " << v[i].gastosprev.consultores << endl;
		cout << endl;
		cout << "Deslocacoes: " << v[i].gastosprev.deslocacoes << endl;
		cout << endl;
		cout << "Gastos gerais : " << v[i].gastosprev.gerais << endl;
		cout << endl;

		cout << "CLASSIFICACAO: " << endl;
		cout << "Segundo os criterios: Originalidade, Qualidade da proposta, Idoneidade da equipa e Exequibilidade" << endl;
		cout << endl;
		cout << "Classificador 1 : " << v[i].classificacao[0][0] << ", " << v[i].classificacao[0][1] << ", " << v[i].classificacao[0][2] << ", " << v[i].classificacao[0][3] << "." << endl;
		cout << "Classificador 2 : " << v[i].classificacao[1][0] << ", " << v[i].classificacao[1][1] << ", " << v[i].classificacao[1][2] << ", " << v[i].classificacao[1][3] << "." << endl;
		cout << "Classificador 3 : " << v[i].classificacao[2][0] << ", " << v[i].classificacao[2][1] << ", " << v[i].classificacao[2][2] << ", " << v[i].classificacao[2][3] << "." << endl;

		cout << endl;
		cout << "Financiamento solicitado : " << v[i].custototal << endl;
		cout << endl;
		cout << "Classificacao Final : " << v[i].classfinal << endl;

		cout << endl;
		cout << "-----------------------------------" << endl;
	}

	cout << endl;
}

void calcCustoTotal(projeto v[], int n)
{	
	for (int i = 0; i < n; i++)
	{
		float total = 0;

		total = v[i].gastosprev.equipamento + v[i].gastosprev.bolsas + v[i].gastosprev.consumiveis
				+ v[i].gastosprev.consultores + v[i].gastosprev.deslocacoes + v[i].gastosprev.gerais;

		v[i].custototal = total;
	}

	cout << endl;
	cout << "Fianciamento solicitado dos Projetos calculado com sucesso!" << endl;
	cout << endl;

}

void avaliar(projeto v[], int n)
{

	cout << endl;
	cout << "INTRODUZA AS CLASSIFICACOES DOS PROJETOS: " << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Esta a classificar o Projeto: " << v[i].id << endl;
		cout << endl;
		cout << "Classificacoes possiveis: 'N' - Nao satisfaz, 'M' - Minimamente satisfatorio, 'S' - Satisfaz, 'B' - Bom, 'E' - Excelente" << endl;

		for (int l = 0; l < 3; l++) //percorre linhas
		{
			cout << endl;
			cout << "Avaliador " << l + 1 << endl;

			for (int c = 0; c < 4; c++) //percorre colunas
			{
				string criterio;

				if (c == 0)
				{
					criterio = "Originalidade";
				}
				if (c == 1)
				{
					criterio = "Qualidade da proposta";
				}
				if (c == 2)
				{
					criterio = "Idoneidade da equipa";
				}
				if (c == 3)
				{
					criterio = "Exequibilidade";
				}

				cout << endl;
				cout << "Esta a avaliar o criterio " << criterio << endl;
				cin >> v[i].classificacao[l][c];
			}
		}

		cout << endl;
		cout << "-----------------------------------" << endl;
	}

	cout << endl;
	cout << "Projetos avaliados com sucesso!" << endl;
	cout << endl;
}


void calcClassFinal(projeto v[], int n)
{
	for (int i = 0; i < n; i++) //percorre vector de projetos
	{
		float total = 0;
		float media_total = 0;

		for (int l = 0; l < 3; l++) //percorre linhas (avaliadores)
		{
			float total_linha = 0;
			float media_linha = 0;

			for (int c = 0; c < 4; c++) //percorre colunas (criterios de apreciaçao)
			{
				switch (v[i].classificacao[l][c])
				{
					case 'n':
						total_linha = total_linha + 1;
						break;

					case 'm':
						total_linha = total_linha + 2;
						break;

					case 's':
						total_linha = total_linha + 3;
						break;

					case 'b':
						total_linha = total_linha + 4;
						break;

					case 'e':
						total_linha = total_linha + 5;
						break;
				}
			}

			media_linha = total_linha / 4;
			
			total = total + media_linha;
		}

		media_total = total / 3;

		v[i].classfinal = media_total;
	}

	cout << endl;
	cout << "Classificacao final dos projetos, calculado com sucesso!" << endl;
	cout << endl;
}


void ordernar(projeto v[], int n)
{
	for (int j = 0; j < n; j++)
	{
		float chave = v[j].classfinal;

		projeto temp = v[j];

		int i = j - 1;

		while ((i >= 0) && (v[i].classfinal < chave))
		{

			v[i + 1] = v[i];
			i = i - 1;

		}

		v[i + 1].classfinal = chave;
		v[i + 1] = temp;
	}

	cout << endl;
	cout << "Projetos ordenados com sucesso!" << endl;
	cout << endl;
}