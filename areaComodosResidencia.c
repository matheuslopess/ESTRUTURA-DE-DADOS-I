#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

typedef struct elemento
{
	char nome[100];
	float largura;
	float comprimento;
	float area;
} t_elemento;

typedef struct lista
{
	t_elemento vetor[MAX];
	float area;
	int n;
} t_lista;

t_lista criar(void)
{
	t_lista lista;
	lista.n = -1;
	lista.area = 0;
	return lista;
}

int inserir(t_lista *lista, t_elemento dado)
{
	if(lista->n == (MAX - 1))
		return 0;

	(lista->n)++;
	lista->vetor[lista->n] = dado;

	lista->area += dado.area;

	return 1;
}

int main(void)
{
	t_lista residencia = criar();
	t_elemento comodo;

	int i;

	while(1)
	{
		printf("Insira o nome (NAO para sair):\n");
		scanf("%s", comodo.nome);

		if(!strcmp(comodo.nome, "NAO"))
			break;

		printf("Insira a largura:\n");
		scanf("%f", &comodo.largura);

		printf("Insira a comprimento:\n");
		scanf("%f", &comodo.comprimento);

		putchar('\n');

		comodo.area = comodo.largura * comodo.comprimento;

		inserir(&residencia, comodo);
	}

	putchar('\n');

	for(i = 0; i <= residencia.n; i++)
	{
		printf("Comodo %s; Largura %.2f; Comprimento %.2f; Area %.2f.\n",
			residencia.vetor[i].nome, residencia.vetor[i].largura, residencia.vetor[i].comprimento, residencia.vetor[i].area);
	}

	putchar('\n');

	printf("Area total: %.2f\n", residencia.area);

	return 0;
}
