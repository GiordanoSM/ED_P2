//Giordano Süffert Monteiro - Criado: 10/11/17 - Última atualização: 16/11/17
#include "entrada.h"

vertice** ler_entrada (int* N)
{
	int indice, proximo, i;
	float distancia;
	vertice **grafo;
	scanf ("%d", N);
	getchar();
	grafo = criar_grafo (*N);
	for (i=0; i<*N; i++)
	{
		scanf("%d %d %f", &indice, &proximo, &distancia);
		inserir_adjacente (indice, proximo, distancia, grafo);
		getchar();
	}
	return grafo;
}
