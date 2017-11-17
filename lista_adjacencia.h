//Giordano Süffert Monteiro - Criado: 01/11/17 - Última atualização: 14/11/17
#ifndef LISTA_ADJACENCIA_H 
#define LISTA_ADJACENCIA_H 


#include <stdio.h>
#include <stdlib.h>

typedef struct adjacente {
	int peso;
	float aresta_peso;
}adjacente;

typedef struct celula {
	adjacente vizinho;
	struct celula *prox;
}celula;

typedef struct l_adjacencia {
	celula* primeira;
	celula* ultima;
} l_adjacencia;

typedef struct vertice {
	int indice;
	l_adjacencia adjacentes; 
}vertice;

void criarlvazia (l_adjacencia* l);

void inserir_celula (l_adjacencia* l, int proximo, float distancia);

int retirar_celula (l_adjacencia* l, int proximo);

void deletar_lista (l_adjacencia* l);

#endif