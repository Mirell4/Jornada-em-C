#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

Pilha *iniciar(void){
	Pilha *p = malloc(sizeof(Pilha));
	
	if(p == NULL){
		return NULL;
	}
	
	p->topo = NULL;
	p->tamanho = 0;
 
 	return p;
 }
 
 int empty(Pilha *p){
 	return p->tamanho == 0;
 }
 
 void push(Pilha *p, int numero){
 	
 	Elemento *e = malloc(sizeof(Elemento));
 	if(e == NULL){
 		printf("Erro ao criar elemento\n");
 		return;
	 }
	 
	 e-> valor = numero;
	 e->proximo = p->topo;
	 p->topo = e;
	 
	 p->tamanho = p->tamanho + 1;
	 
 }
 
 int pop(Pilha *p){
 	
 	if(empty(p)){
 		printf("Pilha vazioa.\n");
	 	return -1;
	 }
 	
	Elemento *e = p->topo;
	int numero = e-> valor;
	
	p->topo = e->proximo;
	
	free(e);
	p->tamanho = p-> tamanho -1;	
	
	return numero; //indicar qual valor foi removido
	 
 }
 
 int top(Pilha *p){
 	if(empty(p)){
 		printf("Pilha vazia.\n");
 		return -1;
	 }
	 
	 return p->topo->valor;
 }
 
 int size(Pilha *p){
 	return p->tamanho;
 	
 }
 
 void exibir(Pilha *p){
 	if(empty(p)){
 		printf("Pilha vazia.\n");
 		return;
	 }
	 
	 Elemento *e = p->topo;
	 printf("\nPilha (topo->base):\n");
	 
	 while(e!= NULL){
	 	printf("| %d |\n", e->valor);
	 	e=e->proximo;
	 }
	 printf("------\n");
	 
 }
 
 void liberar(Pilha *p){
 	
 	if(p == NULL){
 		return;
	 }
	 
	 Elemento *atual = p->topo;
	 
	 while(atual != NULL){
	 	Elemento *proximo = atual -> proximo;
		free(atual);
		atual = proximo;	 
	 } 
	 free(p);
 }
