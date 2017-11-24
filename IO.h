#ifndef IO_H 
#define IO_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "Freq_prog.h"

int read(Graph *G);
int commmand_op(char* c);
void print_MST(Graph* G, unsigned int i, double* weight);
void print_distance(Graph *G, unsigned int end);
void print_Freq (DFD_List* l, int N);

#endif