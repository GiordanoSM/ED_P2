//Giordano Süffert Monteiro - Criado: 13/11/17 - Última atualização: 14/11/17
#ifndef PRIM_MST_H
#define PRIM_MST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "lista_adjacencia.h"

typedef struct v_mst {
	int identidade;
}v_mst;

typedef struct dados_mst {
	int referencia;
	int parente;
	float peso_mst;
	int retirado;
}dados_mst;

void extract_min_mst (v_mst* mst, dados_mst* dados, int c, int p);

void min_heapfy_mst (v_mst* mst, dados_mst* dados, int c, int p);

void atualizar_peso (v_mst* mst, int c, vertice **grafo, dados_mst* dados);

void imprimir_mst (dados_mst* dados, v_mst* mst, int peso_total, int N);

void prim_mst (int N, vertice ** grafo);

#endif
