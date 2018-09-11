#include <stdio.h>

#define MAX 64

int main(void)
{
	int i;
	long int graos_quadro = 1, graos_totais = 1;

	for(i = 0; i < MAX; i++, graos_quadro *= 2, graos_totais += graos_quadro)
		printf("Quadro %d: %ld\t|\tTotal: %ld\n", (i + 1), graos_quadro, graos_totais);

	return 0;
}
