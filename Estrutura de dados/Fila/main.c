/*
 * main.c
 * Interface simples para testar as operacoes da Fila por Encadeamento.
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


/*
 * Exibe as operacoes disponiveis para o usuario.
 */
static void menu(void) {

    printf("\n================ FILA ENCADEADA =================\n");
    printf("1 - Enfileirar (enqueue)\n");
    printf("2 - Desenfileirar (dequeue)\n");
    printf("3 - Consultar o primeiro elemento (front)\n");
    printf("4 - Consultar o ultimo elemento (rear)\n");
    printf("5 - Informar tamanho (size)\n");
    printf("6 - Exibir fila\n");
    printf("7 - Verificar se a fila esta vazia (empty)\n");
    printf("0 - Sair\n");
    printf("==================================================\n");
}


int main(void) {

    Fila *fila = iniciar();

    if (fila == NULL) {
        printf("Nao foi possivel criar a fila.\n");
        return EXIT_FAILURE;
    }

    int opcao;

    do {

        menu();

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {

                int numero;

                printf("Digite o valor que deseja enfileirar: ");
                scanf("%d", &numero);

                enqueue(fila, numero);

                printf("Valor %d enfileirado com sucesso.\n", numero);

                break;
            }

            case 2: {

                int removido = dequeue(fila);

                if (removido != -1) {
                    printf("Valor desenfileirado: %d\n", removido);
                }

                break;
            }

            case 3: {

                int valor = front(fila);

                if (valor != -1) {
                    printf("Primeiro elemento: %d\n", valor);
                }

                break;
            }

            case 4: {

                int valor = rear(fila);

                if (valor != -1) {
                    printf("Ultimo elemento: %d\n", valor);
                }

                break;
            }

            case 5:

                printf(
                    "Tamanho da fila: %d\n",
                    size(fila)
                );

                break;

            case 6:

                exibir(fila);

                break;

            case 7:

                if (empty(fila)) {
                    printf("A fila esta vazia.\n");
                } else {
                    printf("A fila nao esta vazia.\n");
                }

                break;


            case 0:

                printf("Encerrando...\n");

                break;


            default:

                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberar(fila);

    return EXIT_SUCCESS;
}
