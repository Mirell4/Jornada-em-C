/*
 * arvore.c
 * Operacoes recursivas da Arvore Binaria de Busca.
 * Nesta implementacao, valores repetidos nao sao inseridos.
 */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *iniciar(void) {
    return NULL;
}

int inserir(No **raiz, int valor) {
	if( *raiz==NULL){ // se n existe
		No *novo=malloc(sizeof(No));
		if(novo==NULL){
			return -1;
		}
		novo->valor = valor;
		novo->esquerda = NULL;
		novo->direita = NULL; // inserção nova
		*raiz = novo;
		return 1;
	}
	
	if(valor <(*raiz)-> valor){
		return inserir(&(*raiz)-> esquerda, valor); // add esquerda se menor
	}
	if(valor >(*raiz)-> valor){
		return inserir(&(*raiz)-> direita, valor); // add direita se maior
	}
	return 0;
}

const No *buscar(const No *raiz, int valor) { // esquerda, direita
	
	if (raiz == NULL || raiz->direita, valor){ // nulo n tenho, ou estou na posição q o usuario quer
		return raiz;
	}
	
	if(valor < raiz->valor){
		return buscar(raiz->esquerda, valor); // se menor define raiz esquerda e busca
	}else{
		return buscar(raiz->direita, valor); // se maior define raiz direita e busca
	}
}

void preOrdem(const No *raiz) { //nó, esquerda, direita
	
	if (raiz != NULL){
		printf("%d ", raiz-> valor);
		preOrdem(raiz->esquerda);
		preOrdem(raiz->direita);
	}
}

void emOrdem(const No *raiz) { //esquerda, nó, direita
	if (raiz != NULL){
		emOrdem(raiz->esquerda);
		printf("%d ", raiz-> valor);
		emOrdem(raiz->direita);
	}
}

void posOrdem(const No *raiz) {
	if (raiz != NULL){
		posOrdem(raiz->esquerda);
		posOrdem(raiz->direita);
		printf("%d ", raiz-> valor);
	}
}

int remover(No **raiz, int valor) {
	if(*raiz == NULL){
		return 0;
	}
	
	if(valor< (*raiz) ->valor){
		return remover(&(*raiz)->esquerda, valor);
	}
	if(valor> (*raiz) ->valor){
		return remover(&(*raiz)->direita, valor);
	}
	
	if((*raiz)-> esquerda == NULL || (*raiz)->direita == NULL){
		No *removido = *raiz;
		if( removido ->esquerda!= NULL){
			*raiz = removido->esquerda;
		} else{
			*raiz = removido->direita;
		}
		free(removido);
		return 1;
	}
	
	No *sucessor = (*raiz) -> direita; 
	
	while(sucessor -> esquerda != NULL){ //vou no menor valor dentro da direita (todas as esquerdas
		sucessor = sucessor -> esquerda;
	}
	
	int valorSucessor = sucessor->valor; //valor armazenado é o sucessor
	(*raiz) -> valor = valorSucessor;
	
	remover(&(*raiz)-> direita, valorSucessor); //remove
	return 1;
	
}

void liberar(No **raiz) {
	if(*raiz != NULL){
		liberar(&(*raiz)->esquerda);
		liberar(&(*raiz)->direita);
		free(*raiz);
		*raiz = NULL;
	}
	
}
