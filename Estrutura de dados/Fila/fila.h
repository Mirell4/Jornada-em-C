/*
 * fila.h
 * Header de definicao da Estrutura de Dados Fila por Encadeamento.
 * Author: BBFL
 */

#pragma once

#ifndef FILA_H
#define FILA_H

/*
 * Estrutura que representa cada elemento da fila.
 *
 * Cada elemento armazena:
 * - um valor inteiro;
 * - um ponteiro para o proximo elemento.
 */
typedef struct elemento {
    int valor;
    struct elemento *proximo;
} Elemento;


/*
 * Estrutura que representa a fila.
 *
 * A fila mantem:
 * - um ponteiro para o primeiro elemento;
 * - um ponteiro para o ultimo elemento;
 * - a quantidade atual de elementos.
 */
typedef struct {
    Elemento *inicio;
    Elemento *fim;
    int tamanho;
} Fila;


/* Criacao da fila */
Fila *iniciar(void);


/* Verifica se a fila esta vazia */
int empty(Fila *f);


/* Insere um novo elemento no fim da fila */
void enqueue(Fila *f, int numero);


/* Remove e retorna o primeiro elemento da fila */
int dequeue(Fila *f);


/* Consulta o primeiro elemento sem remove-lo */
int front(Fila *f);


/* Consulta o ultimo elemento sem remove-lo */
int rear(Fila *f);


/* Retorna a quantidade de elementos */
int size(Fila *f);


/* Exibe os elementos do inicio para o fim */
void exibir(Fila *f);


/* Libera toda a memoria ocupada pela fila */
void liberar(Fila *f);


#endif
