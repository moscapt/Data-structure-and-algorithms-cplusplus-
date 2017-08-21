#include "projeto.h"

void escreverFicheiro(projeto v[], int n);

int main()
{

	cout << "Introduza o numero de projetos: " << endl;
	int nprojetos;
	cin >> nprojetos;

	projeto * vProjetos = new (nothrow) projeto[nprojetos];

	if (vProjetos != 0)
	{
		adicionarProj(vProjetos, nprojetos);

		bool sair = false;
		bool ct = false;
		bool av = false;
		bool cf = false;

		do
		{
			cout << "****MENU****" << endl;
			cout << "1 - Vizualizar dados dos Projetos" << endl;
			cout << "2 - Calcular Fianciamento Solicitado dos Projetos" << endl;
			cout << "3 - Avaliar Projetos" << endl;
			cout << "4 - Calcular Classificacao Final dos Projetos" << endl;
			cout << "5 - Ordenar projetos por ordem decrescente e escrever num ficheiro" << endl;
			cout << endl;
			cout << "0 - Sair" << endl;
			cout << "************" << endl;

			char choice;
			cin >> choice;

			switch (choice)
			{

				case '1':
					escreverConsola(vProjetos, nprojetos);
					break;

				case '2':
					calcCustoTotal(vProjetos, nprojetos);
					ct = true;
					break;

				case '3':
					avaliar(vProjetos, nprojetos);
					av = true;
					break;

				case '4':
					if (!av)
					{
						cout << endl;
						cout << "Primeiro tem de efectuar a avaliacao dos Projetos!" << endl;
						cout << endl;
					}
					else
					{
						calcClassFinal(vProjetos, nprojetos);
						cf = true;
					}
					break;

				case '5':
					if (!ct)
					{
						cout << endl;
						cout << "Primeiro tem de calcular o fianciamento solicitado dos Projetos!" << endl;
						cout << endl;
					}
					else if (!av)
					{
						cout << endl;
						cout << "Primeiro tem de avaliar os Projetos!" << endl;
						cout << endl;
					}
					else if (!cf)
					{
						cout << endl;
						cout << "Primeiro tem de calcular a classificacao final dos Projetos!" << endl;
						cout << endl;
					}
					else if(ct && av && cf)
					{
						ordernar(vProjetos, nprojetos);
						escreverFicheiro(vProjetos, nprojetos);
					}
					break;

				case '0':
					cout << "Escolheu a opcao Sair. Adeus!" << endl;
					sair = true;
					break;

				default:
					cout << endl;
					cout << "Escolha uma opcao correcta!" << endl;
					cout << endl;
					break;
			}
		} while (!sair);

		delete [] vProjetos;
	}

	return 0;

	//cin.sync();
	//cin.get();
}


void escreverFicheiro(projeto v[], int n)
{
	ofstream ficheiroOut("projetos.txt");

	if (ficheiroOut.is_open())
	{
		for (int i = 0; i < n; i++)
		{
			ficheiroOut << "Projeto: " << v[i].id << endl;
			ficheiroOut << "Titulo: " << v[i].titulo << endl;
			ficheiroOut << "Instituicao proponente: " << v[i].instituicao << endl;
			ficheiroOut << "Financiamento solicitado: " << v[i].custototal << endl;
			ficheiroOut << "Classificacao Final : " << v[i].classfinal << endl;
			ficheiroOut << endl;

			if (v[i].classfinal < 3)
			{
			
				ficheiroOut << "Projeto rejeitado." << endl;
			
			}
			else if (v[i].classfinal >= 3 && v[i].classfinal < 4)
			{

				ficheiroOut << "Subsidio de 30% do solicitado." << endl;

			}
			else if (v[i].classfinal >= 4 && v[i].classfinal < 5)
			{

				ficheiroOut << "Subsidio de 75% do solicitado." << endl;

			}
			else if(v[i].classfinal == 5)
			{

				ficheiroOut << "Subsidio de 100% do solicitado." << endl;

			}
			
			ficheiroOut << "-----------------------------------" << endl;
			ficheiroOut << endl;

		}

		ficheiroOut.close();
	}

	cout << endl;
	cout << "A escrita no ficheiro ocorreu com sucesso!" << endl;
	cout << endl;
}


