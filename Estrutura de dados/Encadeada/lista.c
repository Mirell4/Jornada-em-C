#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *iniciar(void){
	Lista *l = malloc(sizeof(Lista));
	
	if(l == NULL){
		return NULL;
	}
	
	l->inicio = NULL;
	l->tamanho = 0;
	
	return l;
}

int empty(Lista *l){
	return l->tamanho == 0;
}

void add(Lista *l, int numero){
	if(empty(l)){
		Elemento *e = malloc(sizeof(Elemento));
		
		if(e == NULL){
			printf("Erro de alocacao de memoria.\n");
			return;
		}
		e->valor = numero;
		e->proximo = NULL;
		l->inicio = e;
	} else {
		Elemento *e = malloc(sizeof(Elemento));

		if(e == NULL){
			printf("Erro de alocacao de memoria.\n");
			return;
		}
		Elemento *antigo_inicio = l->inicio;
		e->valor = numero;
		l->inicio = e;
		e->proximo = antigo_inicio;
	}
	l->tamanho = l->tamanho+1;
}

int size(Lista *l){
	return l->tamanho;
}

void add_pos(Lista *l, int numero, int posicao){
	if(empty(l)){
		printf("Lista vazia. Nao e permitido inserir na posicao.");
		return;
	}

	if(posicao > l->tamanho || posicao <= 0){
		printf("Posicao invalida!");
		return;
	}
	
	if(posicao == 1){
		add(l, numero);
		return;
	}
	
	Elemento *e_atual = l->inicio;
	Elemento *e_anterior = NULL;
	Elemento *e = malloc(sizeof(Elemento));
	
	if(e == NULL){
		printf("Erro na alocacao.");
		return;
	}
	
	e->valor = numero;
	
	int i;
	for( i=1 ; i<posicao ; i++ ){
		e_anterior = e_atual;
		e_atual = e_atual->proximo;
	}
	
	e_anterior->proximo = e;
	e->proximo = e_atual;
	
	l->tamanho = l->tamanho + 1;
}

int get(Lista *l, int posicao){
	if(empty(l)){
		printf("Lista vazia.");
		return -1;
	}
	
	if( posicao > l->tamanho || posicao <=0 ){
		printf("Posicao invalida");
		return -1;
	}
	
	int i=1;
	Elemento *e = l->inicio;
	
	while( e!=NULL ){
		if( i == posicao ){
			return e->valor;
		}
		e = e->proximo;
		i++;
		
	}
	return -1;
}

void set(Lista *l, int numero, int posicao){
	if(empty(l)){
		printf("Lista vazia.");
		return;
	}
	
	if( posicao > l->tamanho || posicao <=0 ){
		printf("Posicao invalida");
		return;
	}
	
	int i=1;
	Elemento *e = l->inicio;
	
	while( e!=NULL ){
		if( i == posicao ){
			e->valor = numero;
			return;
		}
		e = e->proximo;
		i++;
		
	}
}

void exibir(Lista *l){
	if(empty(l)){
		printf("Lista vazia.");
		return;
	}
	
	Elemento *e = l->inicio;
	printf("Lista: ");
	
	while( e != NULL ){
		printf("%3d", e->valor);
		e = e->proximo;
	}
	printf("\n");
}

int delete(Lista *l, int posicao){
	if(empty(l)){
		printf("Lista vazia.");
		return -1;
	}
	
	if( posicao > l->tamanho || posicao <= 0 ){
		printf("Posicao invalida.");
		return;
	}
	
	if( posicao == 1){
		Elemento *e = l->inicio;
		int numero = e->valor;
		
		l->inicio = l->inicio->proximo;
		
		free(e);
		
		l->tamanho = l->tamanho - 1;
		return numero;
	}
	
	Elemento *e_atual = l->inicio;
	Elemento *e_anterior = NULL;
	
	int i;
	for( i=1 ; i<posicao ; i++ ){
		e_anterior = e_atual;
		e_atual = e_atual->proximo;
	}
	
	e_anterior->proximo = e_atual->proximo;
	int numero = e_atual->valor;
	
	free(e_atual);
	
	l->tamanho = l->tamanho - 1;
	
	return numero;
}

void liberar(Lista *l){
	if(l==NULL){
		return;
	}
	
	Elemento *atual = l->inicio;
	while( atual != NULL ){
		Elemento *proximo = atual->proximo;
		free(atual);
		atual = proximo;
	}
	free(l);
}






