/*
 * main.c
 * Menu para testar uma Arvore Binaria de Busca.
 */
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

static void menu(void) {
    printf("\n========== ARVORE BINARIA DE BUSCA ==========\n");
    printf("1 - Inserir valor\n");
    printf("2 - Buscar valor\n");
    printf("3 - Percorrer em pre-ordem\n");
    printf("4 - Percorrer em ordem\n");
    printf("5 - Percorrer em pos-ordem\n");
    printf("6 - Remover valor\n");
    printf("7 - Verificar se a arvore esta vazia\n");
    printf("0 - Sair\n");
    printf("=============================================\n");
}

int main(void) {
    /* A arvore comeca vazia, depois recebe os valores da aula. */
    No *raiz = iniciar();
    int valores[] = {4, 78, 12, 3, 65, 21, 34, 77, 98, 11};
    int quantidade = (int)(sizeof(valores) / sizeof(valores[0]));
    int i;

    for (i = 0; i < quantidade; i++) {
        if (inserir(&raiz, valores[i]) == -1) {
            printf("Falha ao alocar memoria.\n");
            liberar(&raiz);
            return EXIT_FAILURE;
        }
    }
    printf("Arvore inicial criada com os valores da aula.\n");
    int opcao;
    do {
        menu();
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Encerrando.\n");
            liberar(&raiz);
            return EXIT_FAILURE;
        }
        switch (opcao) {
            case 1: {
                int valor;
                printf("Valor a inserir: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida.\n");
                    liberar(&raiz);
                    return EXIT_FAILURE;
                }
                int resultado = inserir(&raiz, valor);
                if (resultado == 1) printf("Valor inserido.\n");
                else if (resultado == 0) printf("Valor ja existente.\n");
                else printf("Falha ao alocar memoria.\n");
                break;
            }
            case 2: {
                int valor;
                printf("Valor a buscar: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida.\n");
                    liberar(&raiz);
                    return EXIT_FAILURE;
                }
                if (buscar(raiz, valor) != NULL) printf("Valor encontrado.\n");
                else printf("Valor nao encontrado.\n");
                break;
            }
            case 3:
                printf("Pre-ordem: ");
                preOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Em ordem: ");
                emOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Pos-ordem: ");
                posOrdem(raiz);
                printf("\n");
                break;
            case 6: {
                int valor;
                printf("Valor a remover: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida.\n");
                    liberar(&raiz);
                    return EXIT_FAILURE;
                }
                if (remover(&raiz, valor)) printf("Valor removido.\n");
                else printf("Valor nao encontrado.\n");
                break;
            }
            case 7:
                printf(raiz == NULL ? "Arvore vazia.\n" : "Arvore nao vazia.\n");
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    /* Libera todos os nos antes de terminar. */
    liberar(&raiz);
    return EXIT_SUCCESS;
}
