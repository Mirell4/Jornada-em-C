#include<stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *iniciar(void){
	Fila *f = malloc(sizeof(Fila));
	
	if(f == NULL){
		return NULL;
	}
	
	f->inicio = NULL;
	f->fim = NULL;
	f->tamanho = 0;
	
	return f;
	
}

int empty(Fila *f){
	
	return f->tamanho == 0;	
}

void enqueue(Fila *f, int numero){
	
	Elemento *e = malloc(sizeof(Elemento));
	
	if(e==NULL){
		printf("Erro na criacao do elemento!");
		return;
	}
	
	e->valor = numero;
	e -> proximo = NULL;
	
	if(empty(f)){
		
		f->inicio = e;
		f->fim = e;
		
	}else{
		
		f->fim->proximo = e;
		f->fim = e; // n mexe no começo, so insere no final exceto quando a fila for vazia
		
	}
	
	f->tamanho = f->tamanho +1;
}

int dequeue(Fila *f){
	if(empty(f)){
		printf("Fila vazia.\n");
		return -1;
	}
	
	Elemento *e = f->inicio;
	int numero = e->valor;
	f->inicio = e->proximo;
	
	if(f->inicio = NULL){
		f->fim == NULL;
		
	}
	
	free(e);
	f->tamanho = f->tamanho -1;
	
	return numero;
	
}

int front(Fila *f){
	
	if(empty(f)){
		printf("Fila vazia.\n");
		return -1;
	}
	return f->inicio->valor;
}

int rear(Fila *f){
	if(empty(f)){
		printf("Fila vazia.\n");
		return -1;
	}
	return f->fim->valor;
}

int size(Fila *f){
	return f->tamanho;
	
}

void exibir(Fila *f){
	if(empty(f)){
		printf("Fila vazia.\n");
		return -1;
	}
	
	Elemento *e = f->inicio;
	
	printf("\nFila(inicio -> fim: \n)");
	
	while(e != NULL){
		printf("[ %d ]", e->valor);
		
		if(e -> proximo != NULL){
			printf(" -> ");
		}
		
		e = e->proximo;
	}
	printf("\n");
}

void liberar(Fila *f){
	
	if(f == NULL){
		return;
	}
	
	Elemento *atual = f->inicio;
	
	while(atual!= NULL){
		Elemento *proximo = atual->proximo;
		
		free(atual);
		
		atual = proximo;
	}
	
	free(f);
	
}
