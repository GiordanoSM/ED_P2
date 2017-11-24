#include "IO.h"

int read(Graph *G)
{
	int flag = 0;
	unsigned int v1, v2;
	double w;
	while(scanf("%u %u %lf%*c", &v1, &v2, &w) == 3)
	{
		if (w <= 0)
		{
			flag = 1; 
		}
		Graph_updater(G, v1, v2, w);
	}

	return flag;
}

void print_MST(Graph* G, unsigned int i, double* weight)
{	
	List_Node *adj;
	for(adj = G->Vertex[i-1].head->next; adj != NULL; adj = adj->next)
	{
		if (G->Vertex[adj->id-1].pi == i)
		{
			printf("Vertices Weight\n");
			printf("%u - %u  %lf\n", i, adj->id, adj->WT);
			*weight += adj->WT;
			print_MST(G, adj->id, weight);
		} 
	}
}

void print_distance(Graph *G, unsigned int end)
{
	if(G->Vertex[end-1].pi == 0){
		return;
	}
	double weight = (G->Vertex[end-1].key) - (G->Vertex[(G->Vertex[end-1].pi-1	)].key); 
	print_distance(G, G->Vertex[end-1].pi);
	printf("Vertices Weight\n");
	printf("%u - %u  %lf\n", G->Vertex[end-1].pi, 
		                  end, 
		    			  weight);

}

void print_Freq (DFD_List* l, int N)
{
	int number_pairs = N*(N-1)/2;
	Node* aux;
	aux = l->first;
	printf ("Distance : Frequency\n");
	while (aux->next != NULL)
	{
		aux = aux->next;
		printf ("%.2f : %.4lf\n", aux->dist, (double) aux->counter / number_pairs);
	}
	Delete_DFD_List (l);
}