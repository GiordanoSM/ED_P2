//Giordano Süffert Monteiro - Criado: 01/11/17 - Última atualização: 14/11/17
#include "lista_adjacencia.h"

void criarlvazia (l_adjacencia* l) //Recebe uma variável lista de alunos por referência a fim de criar a sua célula cabeça.
{
	l->primeira = (celula*) malloc (sizeof (celula));
	l->primeira->prox = NULL; //Aterra os ponteiros da lista.
	l->ultima = l->primeira;
}

int iflvazia (l_adjacencia* l) //Recebe uma lista de alunos por refêrência para verificar se ela está vazia.
{					
	if (l->primeira->prox==NULL) //Verifica se a célula cabeça está aterrada.
		return 1;
	else
		return 0;
}

void inserir_celula (l_adjacencia* l, int proximo, float distancia) //Recebe uma lista de alunos por referência e uma variável que contém os dados do aluno a ser inserido.
{
	l->ultima->prox = (celula*) malloc (sizeof(celula)); //Aloca um espaço para o novo aluno.
	l->ultima = l->ultima->prox; //Adiciona um aluno no final da lista
	l->ultima->vizinho.peso = proximo;
	l->ultima->vizinho.aresta_peso = distancia;
	l->ultima->prox = NULL; //Aterra o final da lista
}

int retirar_celula (l_adjacencia* l, int proximo) //Recebe uma lista de alunos por referência e a chave do aluno a ser retirado.
{
	celula *ant;
	celula *rmv = l->primeira->prox;
	if (iflvazia(l))
		return 1; 
	while (rmv->vizinho.peso != proximo) //Percorre toda a lista a procura da chave dada
	{
		ant = rmv;
		if (rmv->prox != NULL)
			rmv=rmv->prox; 
		else
			return 1;
	}
	ant->prox = rmv->prox; //Remove o aluno de chave k.
	free (rmv);
	return 0;
}

void deletar_lista (l_adjacencia* l) //Recebe uma lista de alunos como parâmetro por referência a fim de desalocar todos os espaços alocados.
{
	celula *aux;
	while (!iflvazia(l)) //Percorre toda a lista removendo e desalocando todos os seus elementos.
	{
		aux = l->primeira->prox;
		l->primeira->prox = aux->prox;
		free(aux);
	}
	free (l->primeira); //Desaloca a célula cabeça da lista.
}
