#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct elementos
{
	char nome[50];
	char telefone1[25];
	char telefone2[25];
} t_elemento;

typedef struct lista
{
	t_elemento vetor[MAX];
	int n;
} t_lista;

t_lista criar();
int isVazia(t_lista *);
int isCheia(t_lista *);
int getTamanho(t_lista *);
t_elemento *getElemento(t_lista *, int);
int getPosicao(t_lista *, t_elemento);
int compara(t_elemento, t_elemento);
int inserir(t_lista *, int, t_elemento);
int deslocaDireita(t_lista *, int);
int remover(t_lista *, int);
int deslocaEsquerda(t_lista *, int);

int main()
{
	char opcoes_str[5][10] = {"Cadastrar", "Apagar", "Pesquisar", "Listar", "Sair"};
	int opcoes_num = 5, escolha = 0;
	int i;

	t_lista agenda = criar();
	t_elemento contato;
	t_elemento *contato_p = 0;

	do {
		printf("MENU\n\n");

		for(i = 0; i < opcoes_num; i++)
			printf("%d) %s\n", i+1, opcoes_str[i]);

		printf("\nInsira o numero da opcao: ");
		scanf("%d%*c", &escolha);

		putchar('\n');

		escolha--;

		switch(escolha)
		{
			case 0:
				printf("Insira o nome:\n");
				scanf("%s%*c", contato.nome);
				printf("Insira o primeiro telefone:\n");
				scanf("%s%*c", contato.telefone1);
				printf("Insira o segundo telefone:\n");
				scanf("%s%*c", contato.telefone2);

				if(inserir(&agenda, getTamanho(&agenda), contato))
					printf("\nOK\n");
				else
					printf("\nERRO\n");

				break;
			case 1:
				printf("Insira o nome:\n");
				scanf("%s%*c", contato.nome);
				
				if(remover(&agenda, getPosicao(&agenda, contato)))
					printf("\nOK\n");
				else
					printf("\nERRO\n");

				break;
			case 2:
				printf("Insira o nome:\n");
				scanf("%s%*c", contato.nome);

				contato_p = getElemento(&agenda, getPosicao(&agenda, contato));

				if(contato_p)
				{
					printf("\nNome: %s\n", contato_p->nome);
					printf("Telefone 1: %s\n", contato_p->telefone1);
					printf("Telefone 2: %s\n", contato_p->telefone2);
				}
				else
					printf("\nERRO\n");

				break;
			case 3:
				for(i = 0; i < getTamanho(&agenda); i++)
				{
					contato_p = getElemento(&agenda, i);

					printf("\nNome: %s\n", contato_p->nome);
					printf("Telefone 1: %s\n", contato_p->telefone1);
					printf("Telefone 2: %s\n", contato_p->telefone2);
				}

				break;
			case 4:
				break;
			default:
				printf("Opcao nao disponivel. Tente novamente.");
		}

		putchar('\n');
	} while(escolha != 4);

	return 0;
}

t_lista criar()
{
	t_lista lista;
	lista.n = -1;
	return lista;
}

int isVazia(t_lista *lista)
{
	return (lista->n == -1);
}

int isCheia(t_lista *lista)
{
	return (lista->n == MAX-1);
}

int getTamanho(t_lista *lista)
{
	return lista->n + 1;
}

t_elemento *getElemento(t_lista *lista, int pos)
{
	if((pos > lista->n) || (pos < 0))
		return 0;

	return &(lista->vetor[pos]);
}

int getPosicao(t_lista *lista, t_elemento dado)
{
	int i;
	for(i = 0; i <= lista->n; i++)
		if(compara(lista->vetor[i], dado) == 0)
			return i;

	return -1;
}

int compara(t_elemento dado1, t_elemento dado2)
{
	return strcmp(dado1.nome, dado2.nome);
}

int inserir(t_lista *lista, int pos, t_elemento dado)
{
	if(isCheia(lista) || (pos > lista->n + 1) || (pos < 0))
		return 0;

	deslocaDireita(lista, pos);
	lista->vetor[pos] = dado;
	(lista->n)++;
	return 1;
}

int deslocaDireita(t_lista *lista, int pos)
{
	int i;
	for(i = lista->n + 1; i > pos; i--)
		lista->vetor[i] = lista->vetor[i-1];

	return 1;
}

int remover(t_lista *lista, int pos)
{
	if((pos > lista->n) || (pos < 0))
		return 0;

	deslocaEsquerda(lista, pos);
	(lista->n)--;
	return 1;
}

int deslocaEsquerda(t_lista *lista, int pos)
{
	int i;
	for(i = pos; i < (lista->n); i++)
		lista->vetor[i] = lista->vetor[i+1];

	return 1;
}
