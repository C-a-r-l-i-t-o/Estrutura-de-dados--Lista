#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo o tipo de dados para a lista
struct LISTA {
    int num;
    struct LISTA *prox;
    struct LISTA *ant;
};

int main() {
    // Definindo o ponteiro para o início e fim da lista
    struct LISTA *inicio = NULL;
    struct LISTA *fim = NULL;
    struct LISTA *aux;

    // Variáveis adicionadas
    int op, numero, achou;
    
    // Loop do menu
    do {
        printf("\nMenu de Opcoes\n");
        printf("1 - Inserir no inicio da lista\n");
        printf("2 - Inserir no final da lista\n");
        printf("3 - Consultar a lista do inicio ao fim\n");
        printf("4 - Consultar a lista do fim ao inicio\n");
        printf("5 - Remover da lista\n");
        printf("6 - Esvaziar a lista\n");
        printf("7 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);

        if (op < 1 || op > 7)
            printf("\nOpcao invalida!!");
        
        if (op == 1) {
            printf("\nDigite o numero a ser inserido no inicio da lista: ");
            struct LISTA *novo = (struct LISTA*)malloc(sizeof(struct LISTA));
            scanf("%d", &(novo->num));

            if (inicio == NULL) {
                // A lista estava vazia e o elemento inserido será o primeiro e o último
                inicio = novo;
                fim = novo;
                novo->prox = NULL;
                novo->ant = NULL;
            } else {
                // A lista já contém elementos e o novo elemento será inserido no início da lista
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = NULL;
                inicio = novo;
            }
            printf("\nNumero inserido no inicio da lista!!");
        }

        if (op == 2) {
            printf("\nDigite o numero a ser inserido no fim da lista: ");
            struct LISTA *novo = (struct LISTA*)malloc(sizeof(struct LISTA));
            scanf("%d", &(novo->num));

            if (inicio == NULL) {
                // A lista estava vazia e o elemento inserido será o primeiro e o último
                inicio = novo;
                fim = novo;
                novo->prox = NULL;
                novo->ant = NULL;
            } else {
                // A lista já contém elementos e o novo elemento será inserido no fim da lista
                fim->prox = novo;
                novo->ant = fim;
                novo->prox = NULL;
                fim = novo;
            }
            printf("\nNumero inserido no fim da lista!!");
        }

        if (op == 3) {
            if (inicio == NULL) {
                // A lista está vazia
                printf("\nLista vazia!");
            } else {
                // A lista contém elementos e estes serão mostrados do início ao fim
                printf("\nConsultando a lista do inicio ao fim \n");
                aux = inicio;
                while (aux != NULL) {
                    printf("%d ", aux->num);
                    aux = aux->prox;
                }
            }
        }

        if (op == 4) {
            if (inicio == NULL) {
                // A lista está vazia 
                printf("\nLista vazia! ");
            } else {
                // A lista contém elementos e estes serão mostrados do fim ao início 
                printf("\nConsultando a lista do fim ao inicio\n");
                aux = fim;
                while (aux != NULL) {
                    printf("%d ", aux->num);
                    aux = aux->ant;
                }
            }
        }

        if (op == 5) {
            if (inicio == NULL) {
                // A lista está vazia
                printf("Lista vazia!!");
            } else {
                // A lista contém elementos e o elemento a ser removido deve ser digitado
                printf("\nDigite o elemento a ser removido: ");
                scanf("%d", &numero);

                // Todas as ocorrências da lista, iguais ao número digitado, serão removidas
                aux = inicio;
                achou = 0;
                while (aux != NULL) {
                    if (aux->num == numero) {
                        // O número digitado foi encontrado na lista e será removido
                        achou = achou + 1;
                        if (aux == inicio) {
                            // O número a ser removido é o primeiro da lista
                            inicio = aux->prox;
                            if (inicio != NULL) {
                                inicio->ant = NULL;
                                free(aux);
                                aux = inicio;
                            } else if (aux == fim) {
                                // O número a ser removido é o último da lista
                                fim = fim->ant;
                                if (fim != NULL) {
                                    fim->prox = NULL;
                                }
                                free(aux);
                                aux = NULL;
                            } else {
                                // O número a ser removido está no meio da lista 
                                aux->ant->prox = aux->prox;
                                aux->prox->ant = aux->ant;
                                struct LISTA *aux2 = aux->prox;
                                free(aux);
                                aux = aux2;
                            }
                        } else {
                            aux = aux->prox;
                        }
                    }
                }
                if (achou == 0)
                    printf("\nNumero nao encontrado");
                else if (achou == 1)
                    printf("\nNumero removido 1 vez");
                else
                    printf("\nNumero removido %d vezes", achou);
            }
        }

        if (op == 6) {
            if (inicio == NULL) {
                // A lista está vazia
                printf("Lista vazia!!");
            } else {
                // A lista será esvaziada
                aux = inicio;
                while (aux != NULL) {
                    inicio = inicio->prox;
                    free(aux);
                    aux = inicio;
                }
                printf("Lista esvaziada");
            }
        }

    } while (op != 7);

    return 0;
}

