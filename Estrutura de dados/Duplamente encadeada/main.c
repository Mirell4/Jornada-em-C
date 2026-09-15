#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

static void menu(void) {
    printf("\n========== LISTA DUPLAMENTE ENCADEADA ==========\n"); //>>>
    printf("1 - Adicionar no inicio\n");
    printf("2 - Consultar elemento por posicao\n");
    printf("3 - Informar tamanho\n");
    printf("4 - Exibir lista do inicio para o fim\n"); //>>>
    printf("5 - Adicionar em uma posicao\n");
    printf("6 - Alterar elemento de uma posicao\n");
    printf("7 - Excluir elemento de uma posicao\n");
    printf("8 - Verificar se a lista esta vazia\n");
    printf("9 - Exibir lista do fim para o inicio\n"); //>>>
    printf("0 - Sair\n");
    printf("================================================\n");
}

int main(void) {

    Lista *lista = iniciar();

    if (lista == NULL) {
        printf("Nao foi possivel criar a lista.\n");
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

                printf("Digite o valor: ");
                scanf("%d", &numero);

                add(lista, numero);
                break;
            }

            case 2: {
                int posicao;

                printf("Digite a posicao: ");
                scanf("%d", &posicao);

                int valor = get(lista, posicao);

                if (valor != -1) {
                    printf("Valor encontrado: %d\n", valor);
                }

                break;
            }

            case 3:
                printf("Tamanho da lista: %d\n", size(lista));
                break;

            case 4:
                exibir(lista);
                break;

            case 5: {
                int numero;
                int posicao;

                printf("Digite o valor: ");
                scanf("%d", &numero);

                printf("Digite a posicao: ");
                scanf("%d", &posicao);

                add_pos(lista, numero, posicao);
                break;
            }

            case 6: {
                int numero;
                int posicao;

                printf("Digite a posicao que sera alterada: ");
                scanf("%d", &posicao);

                printf("Digite o novo valor: ");
                scanf("%d", &numero);

                set(lista, numero, posicao);
                break;
            }

            case 7: {
                int posicao;

                printf("Digite a posicao que sera excluida: ");
                scanf("%d", &posicao);

                int removido = delete(lista, posicao);

                if (removido != -1) {
                    printf("Valor removido: %d\n", removido);
                }

                break;
            }

            case 8:
                if (empty(lista)) {
                    printf("A lista esta vazia.\n");
                } else {
                    printf("A lista nao esta vazia.\n");
                }
                break;

            case 9:
                exibir_reverso(lista);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberar(lista);

    return EXIT_SUCCESS;
}
