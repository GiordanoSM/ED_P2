//Giordano Süffert Monteiro - Criado: 01/11/17 - Última atualização: 16/11/17
#include "grafo.h"

vertice** criar_grafo (int N)
{
	int i;
	vertice **grafo = (vertice**) malloc ((N+1)*sizeof(vertice*));
	for (i=0; i<=N; i++)
	{
		grafo[i] = (vertice*) malloc (sizeof(vertice));
		grafo[i]->indice = i;
		criarlvazia (&grafo[i]->adjacentes);
	}
	return grafo;
}

void inserir_adjacente (int indice, int proximo, float distancia, vertice **grafo)
{
	inserir_celula (&grafo[indice]->adjacentes, proximo, distancia);
	inserir_celula (&grafo[proximo]->adjacentes, indice, distancia);
}

void remover_adjacente (int indice, int proximo, vertice **grafo)
{
	retirar_celula (&grafo[indice]->adjacentes, proximo);
	retirar_celula (&grafo[proximo]->adjacentes, indice);
}

void remover_vertice (int indice, vertice **grafo)
{
	while (!iflvazia(&grafo[indice]->adjacentes))
	{
		remover_adjacente (indice, grafo[indice]->adjacentes.primeira->prox->vizinho.peso, grafo);
	}
	deletar_lista (&grafo[indice]->adjacentes);
	grafo[indice]->indice = 0; 
}

void remover_grafo(vertice** grafo, int N)
{
	int i;
	for (i=0; i<=N; i++)
	{
		if(grafo[i]->indice != 0)
		{
			remover_vertice (i, grafo);
		}
		free(grafo[i]);
	}
	free(grafo);
}

