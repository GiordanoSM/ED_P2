#ifndef Dijkstra_PROG_H
#define Dijkstra_PROG_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"

void Relax(Graph *G, List_Node *v, unsigned int i);

void Dijkstra(Graph *G, unsigned int r);



#endif