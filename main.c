//Giordano Süffert Monteiro - Criado: 10/11/17 - Última atualização: 16/11/17

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "lista_adjacencia.h"
#include "prim_mst.h"
#include "entrada.h"

int main ()
{
	int N;
	vertice** grafo;
	grafo = ler_entrada(&N);
	prim_mst(N, grafo);
	return 0;
}