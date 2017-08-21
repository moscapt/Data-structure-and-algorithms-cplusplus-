#include "projeto.h"

extern int projectCounter;

projeto *addProjeto(projeto *head)
{
	projeto *current = NULL;
	projeto *previous = NULL;

	if (head == NULL) // caso nao haja nenhum projeto
	{
		if ((head = new projeto) != NULL) //head aponta para novo projeto, verifica se foi possivel alocar memoria
		{
			current = head;

			projectCounter = projectCounter + 1;
			current->id = projectCounter;
			readUserInputs(current);
			calcCustoTotal(current);
			cout << endl;
			cout << "Foi atribuido o codigo: " << current->id << endl;
			cout << "Projeto adicionado com sucesso!" << endl;
			cout << endl;

			current->next = NULL;

		}
		else // caso nao seja possivel alocar memoria
		{
			cout << endl;
			cout << "Erro: Impossivel alocar memoria!" << endl;
			cout << endl;
			return NULL;
		}

		return current;
	}
	else  // caso haja pelo menos 1 projeto
	{
		current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		previous = current;

		if ((current = new projeto) != NULL)
		{
			previous->next = current;

			projectCounter = projectCounter + 1;
			current->id = projectCounter;
			readUserInputs(current);
			calcCustoTotal(current);
			cout << endl;
			cout << "Foi atribuido o codigo: " << current->id << endl;
			cout << "Projeto adicionado com sucesso!" << endl;
			cout << endl;

			current->next = NULL;

		}
		else
		{
			cout << endl;
			cout << "Erro: Impossivel alocar memoria!" << endl;
			cout << endl;
		}
		return head;
	}
}

void readUserInputs(projeto *proj)
{
	string palavra;

	cout << endl;
	//cin.ignore(100, '\n');
	cout << "Titulo: " << endl;
	getline(cin, palavra);
	proj->titulo = capitalizar(palavra);

	cout << endl;
	cout << "Instituicao proponente: " << endl;
	getline(cin, palavra);
	proj->instituicao = capitalizar(palavra);
	cout << endl;

	cout << "Nome do Investigador Responsavel: " << endl;
	getline(cin, palavra);
	proj->investigador = capitalizar(palavra);

	cout << endl;
	cout << "Duracao do projecto (numero de meses): " << endl;
	intNoNegValidation(proj->duracao);

	cout << endl;
	cout << "Areas de investigacao: " << endl;

	for (int k = 0; k < 5; k++)
	{
		getline(cin, proj->palavraschave[k]);
	}

	cout << endl;
	cout << "GASTOS PREVISTOS (em euros): " << endl;

	cout << endl;
	cout << "Compra de equipamento: " << endl;
	floatNoNegValidation(proj->gastosprev.equipamento);
	//cin >> proj->gastosprev.equipamento;

	cout << endl;
	cout << "Pagamento de bolsas: " << endl;
	floatNoNegValidation(proj->gastosprev.bolsas);
	//cin >> proj->gastosprev.bolsas;

	cout << endl;
	cout << "Despesas com consumiveis: " << endl;
	floatNoNegValidation(proj->gastosprev.consumiveis);
	//cin >> proj->gastosprev.consumiveis;

	cout << endl;
	cout << "Despesas com consultores: " << endl;
	floatNoNegValidation(proj->gastosprev.consultores);
	//cin >> proj->gastosprev.consultores;

	cout << endl;
	cout << "Deslocacoes: " << endl;
	floatNoNegValidation(proj->gastosprev.deslocacoes);
	//cin >> proj->gastosprev.deslocacoes;

	cout << endl;	
	cout << "Gastos gerais: " << endl;
	floatNoNegValidation(proj->gastosprev.gerais);
	//cin >> proj->gastosprev.gerais;

}

void listProjetos(projeto *head)
{
	projeto *current;

	current = head;

	if (current == NULL)
	{
		cout << endl;
		cout << "Nao existem projetos para listar!" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "DADOS DOS PROJETOS: " << endl;
		cout << endl;
		cout << "-----------------------------------" << endl;

		while (current != NULL)
		{
			printProjectData(current);

			cout << endl;
			cout << "-----------------------------------" << endl;

			current = current->next;
		}

		cout << endl;
	}

}

void printProjectData(projeto *proj)
{
	cout << endl;
	cout << "Projeto: " << proj->id << endl;
	cout << endl;
	cout << "Titulo: " << proj->titulo << endl;
	cout << endl;
	cout << "Instituicao proponente: " << proj->instituicao << endl;
	cout << endl;
	cout << "Nome do Investigador Responsavel: " << proj->investigador << endl;
	cout << endl;
	cout << "Duracao do projecto: " << proj->duracao << " meses"<< endl;
	cout << endl;
	cout << "Palavras chave: " << proj->palavraschave[0] << ", " << proj->palavraschave[1] << ", "
		<< proj->palavraschave[2] << ", " << proj->palavraschave[3] << ", " << proj->palavraschave[4] << "." << endl;
	cout << endl;

	cout << "GASTOS PREVISTOS: " << endl;
	cout << endl;
	cout << "Compra de equipamento: " << proj->gastosprev.equipamento << " EUR" << endl;
	cout << endl;
	cout << "Pagamento de bolsas: " << proj->gastosprev.bolsas << " EUR" << endl;
	cout << endl;
	cout << "Despesas com consumiveis: " << proj->gastosprev.consumiveis << " EUR" << endl;
	cout << endl;
	cout << "Despesas com consultores: " << proj->gastosprev.consultores << " EUR" << endl;
	cout << endl;
	cout << "Deslocacoes: " << proj->gastosprev.deslocacoes << " EUR" << endl;
	cout << endl;
	cout << "Gastos gerais: " << proj->gastosprev.gerais << " EUR" << endl;

	cout << endl;
	cout << "Financiamento solicitado: " << proj->custototal << " EUR" << endl;

	if (proj->av1 == true || proj->av2 == true || proj->av3 == true)
	{
		cout << endl;
		cout << "CLASSIFICACAO: " << endl;
		cout << "Segundo os criterios: Originalidade, Qualidade da proposta, Idoneidade da equipa e Exequibilidade" << endl;
		cout << endl;
	}

	if (proj->av1 == true)
	{
		cout << "Avaliador 1 - " << proj->classificacao[0][0] << ", " << proj->classificacao[0][1] << ", " << proj->classificacao[0][2] << ", " << proj->classificacao[0][3] << "." << endl;
	}

	if (proj->av2 == true)
	{
		cout << "Avaliador 2 - " << proj->classificacao[1][0] << ", " << proj->classificacao[1][1] << ", " << proj->classificacao[1][2] << ", " << proj->classificacao[1][3] << "." << endl;
	}

	if (proj->av3 == true)
	{
		cout << "Avaliador 3 - " << proj->classificacao[2][0] << ", " << proj->classificacao[2][1] << ", " << proj->classificacao[2][2] << ", " << proj->classificacao[2][3] << "." << endl;
	}

	if (proj->avaliado == true)
	{
		cout << endl;
		cout << "Classificacao Final: " << proj->classfinal << endl;
	}

}

void calcCustoTotal(projeto *proj)
{

	float total = 0;

	total = proj->gastosprev.equipamento + proj->gastosprev.bolsas + proj->gastosprev.consumiveis
		+ proj->gastosprev.consultores + proj->gastosprev.deslocacoes + proj->gastosprev.gerais;

	proj->custototal = total;

}

void calcClassFinal(projeto *proj)
{
		float total = 0;
		float media_total = 0;

		for (int l = 0; l < 3; l++) //percorre linhas (avaliadores)
		{
			float total_linha = 0;
			float media_linha = 0;

			for (int c = 0; c < 4; c++) //percorre colunas (criterios de apreciaçao)
			{
				switch (proj->classificacao[l][c])
				{
				case 'N':
					total_linha = total_linha + 1;
					break;

				case 'M':
					total_linha = total_linha + 2;
					break;

				case 'S':
					total_linha = total_linha + 3;
					break;

				case 'B':
					total_linha = total_linha + 4;
					break;

				case 'E':
					total_linha = total_linha + 5;
					break;
				}
			}

			media_linha = total_linha / 4;

			total = total + media_linha;
		}

		media_total = total / 3;

		proj->classfinal = media_total;
}

void listById(projeto *head)
{
	projeto *current;

	current = head;

	if (current == NULL)
	{

		cout << endl;
		cout << "Nao existem projetos!" << endl;
		cout << endl;

	}
	else
	{

		int codigo;

		cout << endl;
		cout << "Introduza o Codigo do projeto: " << endl;
		intNoNegValidation(codigo);
		cout << endl;

		while (current != NULL)
		{

			if (current->id == codigo)
			{
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << endl;
				printProjectData(current);
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << endl;
				return;
			}

			current = current->next;
		}

		cout << endl;
		cout << "Nao existem projetos com esse codigo!" << endl;
		cout << endl;
	}
}

void listByInstituition(projeto *head)
{
	projeto *current;

	current = head;

	if (current == NULL)
	{

		cout << endl;
		cout << "Nao existem projetos!" << endl;
		cout << endl;

	}
	else
	{
		bool listedproj = false;
		string inst;

		cout << endl;
		cout << "Introduza a o nome da Instituicao Proponente: " << endl;
		getline(cin, inst);
		cout << endl;
		transform(inst.begin(), inst.end(), inst.begin(), tolower);

		while (current != NULL)
		{

			string tempinstituicao;
			tempinstituicao = current->instituicao;
			transform(tempinstituicao.begin(), tempinstituicao.end(), tempinstituicao.begin(), tolower);
		
			if (((tempinstituicao).compare(inst)) == 0)
			{
				cout << endl;
				cout << "-----------------------------------" << endl;
				printProjectData(current);
				
				listedproj = true;
			}
			
			current = current->next;
		}

		if (!listedproj)
		{
			cout << endl;
			cout << "Nao existem projetos associados a essa Instituicao!" << endl;
			cout << endl;
			return;
		}

		cout << endl;
		cout << "-----------------------------------" << endl;
		cout << endl;
	}
}

void avaliarById(projeto *head)
{

	projeto *current;

	current = head;

	if (current == NULL)
	{

		cout << endl;
		cout << "Nao existem projetos!" << endl;
		cout << endl;

	}
	else
	{

		int codigo;

		cout << endl;
		cout << "Introduza o Codigo do projeto: " << endl;
		intNoNegValidation(codigo);
		cout << endl;

		while (current != NULL)
		{

			if (current->id == codigo)
			{
				if (current->avaliado == false)
				{
					avaliar(current);

					if (current->av1 == true && current->av2 == true && current->av3 == true)
					{
						current->avaliado = true;
						calcClassFinal(current);
					}

					return;
				}
				else
				{
					cout << endl;
					cout << "Este Projeto ja foi avaliado!" << endl;
					cout << endl;
					return;
				}
			}

			current = current->next;
		}

		cout << endl;
		cout << "Nao existem projetos com esse codigo!" << endl;
		cout << endl;
	}
}

void avaliar(projeto *proj)
{

	cout << "Esta a avaliar o Projeto: " << proj->id << endl;

	bool continuar;
	int avaliador;

	do{

		continuar = true;

		checkAvaliadores(proj);
		cout << "Escolha o numero do avaliador:" << endl;
		
		selectAvaliadorValidation(avaliador);

		switch (avaliador)
		{
		case 1:
			if (proj->av1 == true)
			{
				cout << endl;
				cout << "O Avaliador 1 ja efecutou a avaliacao!" << endl;
				continuar = false;
			}
			break;

		case 2:
			if (proj->av2 == true)
			{
				cout << endl;
				cout << "O Avaliador 2 ja efecutou a avaliacao!" << endl;
				continuar = false;
			}
			break;

		case 3:
			if (proj->av3 == true)
			{
				cout << endl;
				cout << "O Avaliador 3 ja efecutou a avaliacao!" << endl;
				continuar = false;
			}
			break;
		}
	} while (continuar == false);

	cout << endl;
	cout << "Avaliacao enquanto Avaliador " << avaliador << endl;
	cout << endl;

	cout << "Avaliacoes possiveis: 'N' - Nao satisfaz, 'M' - Minimamente satisfatorio, 'S' - Satisfaz, 'B' - Bom, 'E' - Excelente" << endl;

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
		cout << "Esta a avaliar o criterio: " << criterio << endl;
		charAvaValidation(proj->classificacao[avaliador - 1][c]);
		//cin >> proj->classificacao[avaliador - 1][c];

	}

	switch (avaliador)
	{
		case 1:
			proj->av1 = true;
			break;

		case 2:
			proj->av2 = true;
			break;

		case 3:
			proj->av3 = true;
			break;
	}

	cout << endl;
	cout << "Projeto avaliado com sucesso pelo avaliador " << avaliador << " !" << endl;
	cout << endl;
}

projeto *ordenarDownClass(projeto *head)
{
	if (head == NULL)
	{
		cout << endl;
		cout << "Nao existem projetos para ordenar!" << endl;
		cout << endl;
		return NULL;
	}
	else
	{
		projeto *sortedList = head;
		head = head->next;
		sortedList->next = NULL;

		while (head != NULL)
		{
			projeto *current = head;
			head = head->next;

			if (current->classfinal > sortedList->classfinal)
			{
				current->next = sortedList;
				sortedList = current;
			}
			else
			{
				projeto *search = sortedList;

				while (search->next != NULL && current->classfinal < search->next->classfinal)
				{
					search = search->next;
				}

				current->next = search->next;
				search->next = current;
			}
		}

		return sortedList;
	}
}

bool projetosPorAvaliar(projeto *head)
{

	int * v = new (nothrow) int[projectCounter];

	int i = 0;

	projeto *current;

	current = head;
	
	while (current != NULL)
	{
		if (current->avaliado == false)
		{
			v[i] = current->id;
			i++;
		}

		current = current->next;
	}

	if (i != 0)
	{
		cout << endl;
		cout << "Falta avaliar os seguintes Projetos:";
		for (int k = 0; k < i; k++)
		{

			cout << " " << v[k];
		
		}
		cout <<"."<< endl;
		cout << endl;

		delete[] v;
		return true;
	}

	delete[] v;
	return false;	
}

void readFileInputs(ifstream &ficheiro, projeto *proj)
{
	
	getline(ficheiro, proj->titulo);
	getline(ficheiro, proj->instituicao);
	getline(ficheiro, proj->investigador);
	ficheiro >> proj->duracao;

	ficheiro.ignore();
	for (int k = 0; k < 5; k++)
	{
		getline(ficheiro, proj->palavraschave[k]);
	}

	ficheiro >> proj->gastosprev.equipamento;
	ficheiro >> proj->gastosprev.bolsas;
	ficheiro >> proj->gastosprev.consumiveis;
	ficheiro >> proj->gastosprev.consultores;
	ficheiro >> proj->gastosprev.deslocacoes;
	ficheiro >> proj->gastosprev.gerais;
	ficheiro.ignore();
}

projeto *ordenarAlfa(projeto *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		projeto *sortedList = head;
		head = head->next;
		sortedList->next = NULL;

		while (head != NULL)
		{
			projeto *current = head;
			head = head->next;

			if (current->titulo < sortedList->titulo)
			{
				current->next = sortedList;
				sortedList = current;
			}
			else
			{
				projeto *search = sortedList;

				while (search->next != NULL && current->titulo > search->next->titulo)
				{
					search = search->next;
				}

				current->next = search->next;
				search->next = current;
			}
		}

		return sortedList;
	}
}

string capitalizar(string palavra)
{
	if (palavra.length()>0)
	{
		palavra[0] = toupper(palavra[0]);
		for (size_t i = 1; i < palavra.length(); i++)
			palavra[i] = tolower(palavra[i]);
	}

	return palavra;
}

void intNoNegValidation(int &a)
{
	while (!(cin >> a) || a < 0)
	{
		cout << "Tem de introduzir um inteiro positivo!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cin.ignore(100, '\n');
}

void floatNoNegValidation(float &a)
{
	while (!(cin >> a) || a < 0)
	{
		cout << "Tem de introduzir um numero inteiro ou decimal, positivo!" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cin.ignore(100, '\n');
}

void charAvaValidation(char &a)
{
	while (!(cin >> a) || (a != 'S' && a != 'N' && a != 'M' && a != 'B' && a != 'E'))
	{
		cout << "Tem de introduzir um caracter pertencente as avaliacoes possivieis !" << endl;
		cout << "N - Nao satisfaz, M - Minimamente satisfatorio, "<< endl;
		cout << "S - Satisfaz, B - Bom, E - Excelente" << endl;
		cout << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cin.ignore(100, '\n');
}

void selectAvaliadorValidation(int &a)
{
	while (!(cin >> a) || (a != 1 && a != 2 && a != 3))
	{
		cout << "Tem de introduzir um dos seguintes numeros: 1, 2, ou 3 !" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	cin.ignore(100, '\n');
}

projeto *addProjetoFile(projeto *head)
{
	ifstream ficheiroIn("projetosIn.txt");

	if (ficheiroIn.is_open())
	{
		projeto *current;

		current = head;

		projeto *aux = NULL;

		if (current == NULL) // caso nao haja nenhum projeto
		{

			bool firstnode = true; 

			while (ficheiroIn.peek() != EOF)
			{

				if (firstnode == true) //faz o head apontar para o primeiro nodo criado por esta funçao (addProjetoFile)
				{
					current = new projeto;

					head = current;
					firstnode = false;
				}

				projectCounter = projectCounter + 1;
				current->id = projectCounter;
				readFileInputs(ficheiroIn, current);
				calcCustoTotal(current);
			
				aux = current;

				current = new projeto;

				aux->next = current;

			}

			cout << endl;
			cout << "Projetos adicionados com sucesso, a partir do ficheiro 'projetosIn.txt' !" << endl;
			cout << endl;

			aux->next = NULL;	//visto que a verificação ficheiroIn.peek() != EOF não é perfeita, ainda é criado um nodo extra inválido
			delete current;		//após a leitura do ficheiro, logo é necessario apagar esse nodo extra e fazer o ultimo nodo "correcto" apontar para NULL

		}
		else //caso ja existam projectos
		{

			projeto *previous = NULL;
			
			while (current->next != NULL)
			{
				current = current->next;
			}

			previous = current;

			bool firstnode = true;

			while (ficheiroIn.peek() != EOF)
			{

				if (firstnode == true) //faz o ultimo nodo da LL apontar para o primeiro nodo criado por esta funçao (addProjetoFile)
				{
					current = new projeto;

					previous->next = current;
					firstnode = false;
				}

				projectCounter = projectCounter + 1;
				current->id = projectCounter;
				readFileInputs(ficheiroIn, current);
				calcCustoTotal(current);

				aux = current;

				current = new projeto;

				aux->next = current;

			}
			
			cout << endl;
			cout << "Projetos adicionados com sucesso, a partir do ficheiro 'projetosIn.txt' !" << endl;						
			cout << endl;

			aux->next = NULL;	//visto que a verificação ficheiroIn.peek() != EOF não é perfeita, ainda é criado um nodo extra inválido
			delete current;		//após a leitura do ficheiro, logo é necessario apagar esse nodo extra e fazer o ultimo nodo "correcto" apontar para NULL
			
		}
	}

	ficheiroIn.close();

	return head;
}

projeto *deleteProjeto(projeto *head)
{

	if (head == NULL)
	{
		cout << endl;
		cout << "Nao Existem Projectos!" << endl;
		cout << endl;
	}
	else
	{
		projeto *current = head;
		projeto *previous = NULL;

		int codigo;

		cout << endl;
		cout << "Introduza o Codigo do projeto: " << endl;
		intNoNegValidation(codigo);
		cout << endl;

		while (current != NULL)
		{

			if (current->id == codigo)
			{
				break;	//current agora aponta para o nodo a apagar
			}
			else
			{
				previous = current;
				current = current->next;
			}

		}

		if (current == NULL)
		{
			cout << endl;
			cout << "Nao Existem Projectos associados ao codigo: " << codigo << " !" << endl;
			cout << endl;
		}
		else
		{

			if (head == current) //caso o nodo a apagar seja o nodo para qual a head tambem aponta
			{
				head = head->next;
			}
			else
			{
				previous->next = current->next;
			}

			delete current;

			cout << endl;
			cout << "O Projecto com o codigo " << codigo << " foi removido!" << endl;
			cout << endl;
		}
	}

	return head;

}

void checkAvaliadores(projeto *proj)
{
	int * v = new (nothrow) int[3];

	int i = 0;

	if (proj->av1 == false)
	{
		v[i] = 1;
		i++;
	}
	if (proj->av2 == false)
	{
		v[i] = 2;
		i++;
	}
	if (proj->av3 == false)
	{
		v[i] = 3;
		i++;
	}

	if (i != 0)
	{
		cout << endl;
		cout << "Falta a avaliacao dos seguintes avaliadores:";
		for (int k = 0; k < i; k++)
		{

			cout << " " << v[k];

		}
		cout << "." << endl;
		cout << endl;
	}

	delete[] v;
}

projeto *deleteTodosProjetos(projeto *head)
{
	projeto *current;
	projeto *prox;

	current = head;

	while (current != NULL)
	{
		prox = current->next;
		delete current;
		current = prox;
	}

	head = NULL;
	
	return head;
}