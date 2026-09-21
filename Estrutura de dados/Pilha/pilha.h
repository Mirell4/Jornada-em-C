/*
 * pilha.h
 * Header de definicao da Estrutura de Dados Pilha por Encadeamento.
 * Author: BBFL
 */

#pragma once

#ifndef PILHA_H
#define PILHA_H

/*
 * Estrutura que representa cada elemento da pilha.
 * Cada elemento armazena:
 * - um valor inteiro;
 * - um ponteiro para o elemento imediatamente abaixo dele.
 */
typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;

/*
 * Estrutura que representa a pilha.
 * A pilha mantem:
 * - um ponteiro para o elemento que esta no topo;
 * - a quantidade atual de elementos.
 */
typedef struct {
    Elemento *topo;
    int tamanho;
} Pilha;

/* Criacao da pilha */
Pilha *iniciar(void);

/* Verifica se a pilha esta vazia */
int empty(Pilha *p);

/* Insere um novo elemento no topo */
void push(Pilha *p, int numero);

/* Remove e retorna o elemento do topo */
int pop(Pilha *p);

/* Consulta o topo sem remove-lo */
int top(Pilha *p);

/* Retorna a quantidade de elementos */
int size(Pilha *p);

/* Exibe a pilha do topo para a base */
void exibir(Pilha *p);

/* Libera toda a memoria ocupada pela pilha */
void liberar(Pilha *p);

#endif
