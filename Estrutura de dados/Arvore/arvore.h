/*
 * arvore.h
 * Definicoes da Arvore Binaria de Busca (ABB).
 */
#ifndef ARVORE_H
#define ARVORE_H

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
} No;

No *iniciar(void);

int inserir(No **raiz, int valor);
int remover(No **raiz, int valor);

const No *buscar(const No *raiz, int valor);

void preOrdem(const No *raiz);
void emOrdem(const No *raiz);
void posOrdem(const No *raiz);

void liberar(No **raiz);

#endif
