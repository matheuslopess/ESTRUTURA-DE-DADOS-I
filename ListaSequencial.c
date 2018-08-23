#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MAX_STR 50

typedef struct elementos
{
	char nome[MAX_STR];
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
	int i, n = 0;
	t_lista m_lista;
	t_elemento m_nomes;
	t_elemento *m_elemento;

	// Criar a lista
	m_lista = criar();

	// Guardar três nomes
	for(i = 0; i < 3; i++)
	{
		printf("[%d] Insira o seu nome:\n", i);
		scanf(" %s%*c", (m_nomes.nome));
		inserir(&m_lista, i, m_nomes);
	}

	putchar('\n');

	// Mostrar os nomes
	for(i = 0; i < 3; i++)
	{
		m_elemento = getElemento(&m_lista, i);
		printf("[%d] Nome: %s\n", i, (m_elemento->nome));
	}

	putchar('\n');

	// Buscar e mostrar o nome
	do {
		printf("Informe a posicao do elemento a ser buscada [0 a 2]:\n");
		scanf(" %1d%*c", &n);
	} while(n < 0 || n > 2);

	putchar('\n');

	m_elemento = getElemento(&m_lista, n);

	printf("[%d] Nome: %s\n", n, (m_elemento->nome));

	putchar('\n');


	// Apagar um nome
	do {
		printf("Informe a posicao do elemento a ser apagada [0 a 2]:\n");
		scanf(" %1d%*c", &n);
	} while(n < 0 || n > 2);

	putchar('\n');

	remover(&m_lista, n);

	printf("fim\n");

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

int inserir (t_lista *lista, int pos, t_elemento dado)
{
	if (isCheia(lista) || (pos > lista->n + 1) || (pos < 0))
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