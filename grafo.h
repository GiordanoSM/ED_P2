//Giordano Süffert Monteiro - Criado: 01/11/17 - Última atualização: 14/11/17
#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista_adjacencia.h"

vertice** criar_grafo (int N);

void inserir_adjacente (int indice, int proximo, float distancia, vertice **grafo);

void remover_adjacente (int indice, int proximo, vertice **grafo);

void remover_vertice (int indice, vertice **grafo);

void remover_grafo(vertice** grafo, int N);

#endif