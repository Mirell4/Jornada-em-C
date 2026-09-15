#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *iniciar(void){
	Lista *l = malloc(sizeof(Lista));
	
	if(l == NULL){
		return NULL;
	}
	
	l->inicio = NULL;
	l->fim = NULL;
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
		e->anterior = NULL; //>>>
		e->proximo = NULL;
		l->inicio = e;
		l->fim = e; //>>>
	} else {
		Elemento *e = malloc(sizeof(Elemento));

		if(e == NULL){
			printf("Erro de alocacao de memoria.\n");
			return;
		}
		Elemento *antigo_inicio = l->inicio;
		e->valor = numero;
		e->anterior = NULL;//>>>
		e->proximo = antigo_inicio;
		antigo_inicio->anterior = e;//>>>
		l->inicio = e;
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
	e->anterior = e_anterior; //>>>
	
	e_atual->anterior = e; //>>>
	
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
	
	if(posicao <=  (l->tamanho + 1)/2){
		int i = 1;
		Elemento *e = l->inicio;
		
		while(i<posicao){
			e = e->proximo;
			i++;
		}
		return e->valor;
	}else{
		int i = l->tamanho;
		Elemento *e = l->fim;
		
		while(i<posicao){
			e = e->anterior;
			i--;
		}
		return e->valor;
	}
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
	
	if(posicao <=  (l->tamanho + 1)/2){
		int i = 1;
		Elemento *e = l->inicio;
		
		while(i<posicao){
			e = e->proximo;
			i++;
		}
		e->valor = numero;
	}else{
		int i = l->tamanho;
		Elemento *e = l->fim;
		
		while(i<posicao){
			e = e->anterior;
			i--;
		}
		e->valor = numero;
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
		
		if(l->inicio != NULL){
			l->inicio->anterior = NULL;
		}else{
			l->fim = NULL;
		}		
		
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
	
	//>>>
	if(e_atual->proximo != NULL){
		e_atual->proximo->anterior = e_anterior;
	}else{
		l->fim = e_anterior;
	}
	
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

void exibir_reverso(Lista *l){
	if(empty(l)){
		printf("Lista vazia");
		return;
	}
	Elemento *e = l->fim;
	printf("Lista - fim pra inicio:\n");
	
	while(e!=NULL){
		printf("%3d", e->valor);
		e = e->anterior;
	}
	printf("\n");
	
	
}


