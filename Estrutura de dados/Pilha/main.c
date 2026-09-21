/*
 * main.c
 * Interface simples para testar as operacoes da Pilha por Encadeamento.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

static void menu(void) {
    printf("\n================ PILHA ENCADEADA ================\n");
    printf("1 - Empilhar (push)\n");
    printf("2 - Desempilhar (pop)\n");
    printf("3 - Consultar o topo (top)\n");
    printf("4 - Informar tamanho (size)\n");
    printf("5 - Exibir pilha\n");
    printf("6 - Verificar se a pilha esta vazia (empty)\n");
    printf("0 - Sair\n");
    printf("==================================================\n");
}

int main(void) {

     Pilha *pilha = iniciar();

    if (pilha == NULL) {
        printf("Nao foi possivel criar a pilha.\n");
        return EXIT_FAILURE;
    }

    int opcao;

    do {
        menu();

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            /* PUSH - insere um novo elemento no topo. */
            case 1: {
                int numero;

                printf("Digite o valor que deseja empilhar: ");
                scanf("%d", &numero);

                push(pilha, numero);
                printf("Valor %d empilhado com sucesso.\n", numero);
                break;
            }

            /* POP - remove o elemento do topo. */
            case 2: {
                int removido = pop(pilha);

                if (removido != -1) {
                    printf("Valor desempilhado: %d\n", removido);
                }
                break;
            }

            /* TOP - consulta o topo sem remover. */
            case 3: {
                int valor = top(pilha);

                if (valor != -1) {
                    printf("Valor no topo: %d\n", valor);
                }
                break;
            }

            /* SIZE - informa a quantidade de elementos. */
            case 4:
                printf("Tamanho da pilha: %d\n", size(pilha));
                break;

            /* EXIBIR - mostra a pilha do topo para a base. */
            case 5:
                exibir(pilha);
                break;

            /* EMPTY - verifica se a pilha esta vazia. */
            case 6:
                if (empty(pilha)) {
                    printf("A pilha esta vazia.\n");
                } else {
                    printf("A pilha nao esta vazia.\n");
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    /* Libera toda a memoria utilizada. */
    liberar(pilha);

    return EXIT_SUCCESS;
}
