//Giordano Süffert Monteiro - Criado: 13/11/17 - Última atualização: 16/11/17
#include "prim_mst.h"

void extract_min_mst (v_mst* mst, dados_mst* dados, int c, int p)
{
	int aux2;
	while(dados[p].referencia != 0)
	{
		if(dados[p].peso_mst < dados[mst[(int) ceil(dados[p].referencia / 2 - 1)].identidade].peso_mst)
		{
			aux2 = dados[p].referencia;
			mst[dados[p].referencia].identidade = mst[(int) ceil(dados[p].referencia / 2 - 1)].identidade;
			mst[(int) ceil(dados[p].referencia / 2 - 1)].identidade = p;
			dados[p].referencia = (int) ceil(dados[p].referencia / 2 - 1);
			dados[mst[aux2].identidade].referencia = aux2;
		}
		else
			break;
	}
	aux2 = mst[0].identidade;
	mst[0].identidade = mst[c-1].identidade;
	mst[c-1].identidade = aux2;
	dados[mst[0].identidade].referencia = 0;
	dados[mst[c-1].identidade].referencia = c-1;

	min_heapfy_mst (mst, dados, c-1, mst[0].identidade);

}

void min_heapfy_mst (v_mst* mst, dados_mst* dados, int c, int p)
{	
	float left;
	float right;
	int aux;
	float menor;
	if (dados[p].referencia * 2 + 1 < c) 
	{
		left = dados[mst[dados[p].referencia * 2 + 1].identidade].peso_mst;
		if (dados[p].peso_mst < left)
		{
			menor = left;
		}
	}
	else 
		menor = dados[p].peso_mst;

	if (dados[p].referencia * 2 + 2 < c)
	{
		right = dados[mst[dados[p].referencia * 2 + 2].identidade].peso_mst;
		 if (right < menor)
		 {
		 	menor = right;
		 }
	}
	if (menor != dados[p].peso_mst)
	{
		aux = dados[p].referencia;
		if (menor == left)
		{
			mst[dados[p].referencia].identidade = mst[dados[p].referencia * 2 + 1].identidade;
			mst[dados[p].referencia * 2 + 1].identidade = p;
			dados[p].referencia = dados[p].referencia * 2 + 1;
			dados[mst[aux].identidade].referencia = aux;
		}
		else 
		{
			mst[dados[p].referencia].identidade = mst[dados[p].referencia * 2 + 2].identidade;
			mst[dados[p].referencia * 2 + 2].identidade = p;
			dados[p].referencia = dados[p].referencia * 2 + 2;
			dados[mst[aux].identidade].referencia = aux;
		}
		min_heapfy_mst (mst, dados, c, p);
	}
}

void atualizar_peso (v_mst* mst, int c, vertice **grafo, dados_mst* dados)
{
	int p, i=0;
	celula* aux;
	aux = grafo[mst[c].identidade]->adjacentes.primeira;
	while (aux->prox != NULL)
	{
		aux = aux->prox;
		if (aux->vizinho.aresta_peso < dados[aux->vizinho.peso].peso_mst && dados[aux->vizinho.peso].retirado == 0)
		{
			dados[aux->vizinho.peso].parente = mst[c].identidade;
			dados[aux->vizinho.peso].peso_mst = aux->vizinho.aresta_peso;
			p = aux->vizinho.peso; 
			extract_min_mst (mst, dados, c, p);
			i=1;	
		}
	}
	if(i==0)
	{
		extract_min_mst (mst, dados, c, i);
	}
}

void imprimir_mst (dados_mst* dados, v_mst* mst, int peso_total, int N)
{
	int i;
	printf ("%d\n", N);
	for (i=N-2; i>0; i--)
	{
		printf("%d %d %f\n", dados[mst[i].identidade].parente, mst[i].identidade, dados[mst[i].identidade].peso_mst);
	}
	printf ("%d\n", peso_total);
}

void prim_mst (int N, vertice ** grafo)
{
	v_mst mst[N];
	dados_mst dados[N+1];
	int c, i;
	float peso_total=0; 
	for (i=0; i<N; i++)
	{
		mst[i].identidade = N - i;
		dados[i+1].peso_mst = INT_MAX;
		dados[i+1].retirado = 0;
		dados[i+1].referencia = (unsigned int ) (i - N + 1);
	}
	for (c=N-1;c>=0; c--)
	{
		if (c==N-1)
		{
			dados[1].peso_mst = 0;
			dados[1].parente = 0;
		}
		dados[mst[c].identidade].retirado = 1;
		peso_total += dados[mst[c].identidade].peso_mst;
		atualizar_peso (mst, c, grafo, dados);
	}
	imprimir_mst (dados, mst, peso_total, N);
}

