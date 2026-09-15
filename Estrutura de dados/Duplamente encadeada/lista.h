#pragma once

#ifndef LISTA_H
#define LISTA_H

typedef struct elemento {
    int valor;
    struct elemento *anterior;
    struct elemento *proximo;
} Elemento;
typedef struct {
    Elemento *inicio;
    Elemento *fim;
    int tamanho;
} Lista;

/* Criacao da lista */
Lista *iniciar(void);

/* Verificacao */
int empty(Lista *l);

/* Insercao no inicio */
void add(Lista *l, int numero);

/* Consulta por posicao */
int get(Lista *l, int posicao);

/* Quantidade de elementos */
int size(Lista *l);

/* Exibicao do inicio para o fim */
void exibir(Lista *l);

/* Insercao em posicao especifica */
void add_pos(Lista *l, int numero, int posicao);

/* Alteracao em posicao especifica */
void set(Lista *l, int numero, int posicao);

/* Remocao em posicao especifica */
int delete(Lista *l, int posicao);

/* Liberacao de toda a memoria ocupada pela lista */
void liberar(Lista *l);

/* Exibicao do fim para o inicio */
void exibir_reverso(Lista *l);



#endif
