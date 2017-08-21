#include "projeto.h"

void escreverFicheiro(projeto *head);

int projectCounter = 0;

int main()
{
	projeto *head = NULL;
	bool sair = false;

	do
	{
		cout << "****MENU****" << endl;
		cout << "1 - Adicionar Projeto Manualmente" << endl;
		cout << "2 - Carregar Projetos do Ficheiro" << endl;
		cout << endl;
		cout << "3 - Listar Dados de um Projeto" << endl;
		cout << "4 - Listar todos os Projetos ordenados por Titulo" << endl;
		cout << "5 - Listar Projetos associados a uma Instituicao" << endl;
		cout << endl;
		cout << "6 - Avaliar Projeto" << endl;
		cout << "7 - Ordenar projetos por ordem decrescente e escrever num Ficheiro" << endl;
		cout << endl;
		cout << "8 - Remover Projecto" << endl;
		cout << "9 - Remover TODOS os Projectos" << endl;
		cout << endl;
		cout << "0 - Sair" << endl;
		cout << "************" << endl;

		char choice;
		cin >> choice;
		cin.ignore(100, '\n');

		switch (choice)
		{
			case '1':
				head = addProjeto(head);
				break;

			case '2':
				head = addProjetoFile(head);
				break;

			case '3':
				listById(head);
				break;

			case '4':
				head = ordenarAlfa(head);
				listProjetos(head);
				break;
			
			case '5':
				listByInstituition(head);
				break;

			case '6':
				avaliarById(head);
				break;

			case '7':
				if (projetosPorAvaliar(head) == false)
				{ 
					head = ordenarDownClass(head);
					escreverFicheiro(head);
				}
				break;

			case '8':
				head = deleteProjeto(head);
				break;

			case '9':
				if (head != NULL)
				{
					bool out = false;

					do{
						cout << endl;
						cout << "Tem a certeza que deseja remover TODOS os Projectos?" << endl;
						cout << "(S / N): ";
						char inoption;
						cin >> inoption;
						cin.ignore(100, '\n');

						char option = toupper(inoption);

						switch (option)
						{
							case 'S':
								head = deleteTodosProjetos(head);
								cout << endl;
								cout << "Foram Removidos Todos os Projetos!" << endl;
								cout << endl;
								out = true;
								break;

							case 'N':
								cout << endl;
								out = true;
								break;

							default:
								cout << endl;
								cout << "Escolha uma opcao correcta!" << endl;
								cout << endl;
								break;
						}

					} while (!out);
				}
				else
				{
					cout << endl;
					cout << "Nao Existem Projectos!" << endl;
					cout << endl;
				}
				break;

			case '0':
				cout << endl;
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

	deleteTodosProjetos(head);
	return 0;

}


void escreverFicheiro(projeto *head)
{
	
	projeto *current;

	current = head;

	if (current == NULL)
	{
		cout << endl;
		cout << "Nao existem projetos para escrever no ficheiro!" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "Introduza o nome do ficheiro:" << endl;

		string fname;
		getline(cin, fname);

		string fnametxt = fname + ".txt";
		ofstream ficheiroOut(fnametxt);

		if (ficheiroOut.is_open())
		{
			while (current != NULL)
			{
				ficheiroOut << "Projeto: " << current->id << endl;
				ficheiroOut << "Titulo: " << current->titulo << endl;
				ficheiroOut << "Instituicao proponente: " << current->instituicao << endl;
				ficheiroOut << "Financiamento solicitado: " << current->custototal << " EUR" << endl;
				ficheiroOut << "Classificacao Final: " << current->classfinal << endl;
				ficheiroOut << "Subsido a atribuir: ";

				if (current->classfinal >= 0 && current->classfinal < 3)
				{
					ficheiroOut << (current->custototal) * 0.00 << " EUR";
					ficheiroOut << " (Rejeitado)" << endl;

				}
				else if (current->classfinal >= 3 && current->classfinal < 3.5)
				{
					ficheiroOut << (current->custototal) * 0.30 << " EUR";
					ficheiroOut << " (30%)" << endl;

				}
				else if (current->classfinal >= 3.5 && current->classfinal < 4.5)
				{
					ficheiroOut << (current->custototal) * 0.75 << " EUR";
					ficheiroOut << " (75%)" << endl;

				}
				else if (current->classfinal >= 4.5 && current->classfinal <= 5)
				{
					ficheiroOut << (current->custototal) * 1.00 << " EUR";
					ficheiroOut << " (100%)" << endl;

				}

				ficheiroOut << "-----------------------------------" << endl;
				ficheiroOut << endl;

				current = current->next;
			}

			ficheiroOut.close();
		}

		cout << endl;
		cout << "A escrita no ficheiro '" << fnametxt<< "' ocorreu com sucesso!" << endl;
		cout << endl;
	}
}

