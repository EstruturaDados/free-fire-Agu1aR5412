#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

// Estrutura para armazenar os dados do item
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Estrutura da lista encadeada
struct No {
    struct Item dados;
    struct No *proximo;
};

// ======================= VETOR =======================

// Função para cadastrar item no vetor
void inserirItem(struct Item mochila[], int *totalItens) {

    if (*totalItens < MAX) {

        printf("\nNome do item: ");
        scanf("%s", mochila[*totalItens].nome);

        printf("Tipo do item: ");
        scanf("%s", mochila[*totalItens].tipo);

        printf("Quantidade: ");
        scanf("%d", &mochila[*totalItens].quantidade);

        (*totalItens)++;

        printf("\nItem cadastrado com sucesso!\n");

    } else {

        printf("\nMochila cheia!\n");
    }
}

// Função para listar itens do vetor
void listarItens(struct Item mochila[], int totalItens) {

    printf("\n===== ITENS DO VETOR =====\n");

    if (totalItens == 0) {

        printf("Nenhum item cadastrado.\n");

    } else {

        for (int i = 0; i < totalItens; i++) {

            printf("\nItem %d", i + 1);
            printf("\nNome: %s", mochila[i].nome);
            printf("\nTipo: %s", mochila[i].tipo);
            printf("\nQuantidade: %d\n", mochila[i].quantidade);
        }
    }
}

// Busca sequencial no vetor
void buscarItem(struct Item mochila[], int totalItens) {

    char nomeBusca[30];
    int encontrado = 0;
    int comparacoes = 0;

    printf("\nDigite o nome do item: ");
    scanf("%s", nomeBusca);

    for (int i = 0; i < totalItens; i++) {

        comparacoes++;

        if (strcmp(nomeBusca, mochila[i].nome) == 0) {

            printf("\nItem encontrado!");
            printf("\nNome: %s", mochila[i].nome);
            printf("\nTipo: %s", mochila[i].tipo);
            printf("\nQuantidade: %d", mochila[i].quantidade);
            printf("\nComparacoes realizadas: %d\n", comparacoes);

            encontrado = 1;
        }
    }

    if (encontrado == 0) {

        printf("\nItem nao encontrado.");
        printf("\nComparacoes realizadas: %d\n", comparacoes);
    }
}

// Remover item do vetor
void removerItem(struct Item mochila[], int *totalItens) {

    char nomeRemover[30];
    int posicao = -1;

    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    for (int i = 0; i < *totalItens; i++) {

        if (strcmp(nomeRemover, mochila[i].nome) == 0) {

            posicao = i;
        }
    }

    if (posicao == -1) {

        printf("\nItem nao encontrado.\n");

    } else {

        for (int i = posicao; i < *totalItens - 1; i++) {

            mochila[i] = mochila[i + 1];
        }

        (*totalItens)--;

        printf("\nItem removido com sucesso!\n");
    }
}

// Ordenação Bubble Sort
void ordenarVetor(struct Item mochila[], int totalItens) {

    struct Item aux;

    for (int i = 0; i < totalItens - 1; i++) {

        for (int j = 0; j < totalItens - 1 - i; j++) {

            if (strcmp(mochila[j].nome, mochila[j + 1].nome) > 0) {

                aux = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = aux;
            }
        }
    }

    printf("\nItens ordenados com sucesso!\n");
}

// Busca binária
void buscarBinariaVetor(struct Item mochila[], int totalItens) {

    char nomeBusca[30];
    int inicio = 0;
    int fim = totalItens - 1;
    int comparacoes = 0;

    printf("\nDigite o nome do item: ");
    scanf("%s", nomeBusca);

    while (inicio <= fim) {

        int meio = (inicio + fim) / 2;

        comparacoes++;

        int resultado = strcmp(nomeBusca, mochila[meio].nome);

        if (resultado == 0) {

            printf("\nItem encontrado!");
            printf("\nNome: %s", mochila[meio].nome);
            printf("\nTipo: %s", mochila[meio].tipo);
            printf("\nQuantidade: %d", mochila[meio].quantidade);
            printf("\nComparacoes realizadas: %d\n", comparacoes);

            return;
        }

        if (resultado > 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    printf("\nItem nao encontrado.");
    printf("\nComparacoes realizadas: %d\n", comparacoes);
}

// ======================= LISTA ENCADEADA =======================

// Inserir item na lista
void inserirItemLista(struct No **inicio) {

    struct No *novo;

    novo = (struct No *) malloc(sizeof(struct No));

    printf("\nNome do item: ");
    scanf("%s", novo->dados.nome);

    printf("Tipo do item: ");
    scanf("%s", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = *inicio;
    *inicio = novo;

    printf("\nItem inserido na lista!\n");
}

// Listar lista encadeada
void listarItensLista(struct No *inicio) {

    printf("\n===== LISTA ENCADEADA =====\n");

    if (inicio == NULL) {

        printf("Lista vazia.\n");
    }

    while (inicio != NULL) {

        printf("\nNome: %s", inicio->dados.nome);
        printf("\nTipo: %s", inicio->dados.tipo);
        printf("\nQuantidade: %d\n", inicio->dados.quantidade);

        inicio = inicio->proximo;
    }
}

// Busca sequencial na lista
void buscarItemLista(struct No *inicio) {

    char nomeBusca[30];
    int comparacoes = 0;

    printf("\nDigite o nome do item: ");
    scanf("%s", nomeBusca);

    while (inicio != NULL) {

        comparacoes++;

        if (strcmp(nomeBusca, inicio->dados.nome) == 0) {

            printf("\nItem encontrado!");
            printf("\nComparacoes realizadas: %d\n", comparacoes);

            return;
        }

        inicio = inicio->proximo;
    }

    printf("\nItem nao encontrado.");
    printf("\nComparacoes realizadas: %d\n", comparacoes);
}

// Remover item da lista
void removerItemLista(struct No **inicio) {

    struct No *atual = *inicio;
    struct No *anterior = NULL;
    char nomeRemover[30];

    printf("\nDigite o nome do item que deseja remover: ");
    scanf("%s", nomeRemover);

    while (atual != NULL && strcmp(atual->dados.nome, nomeRemover) != 0) {

        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {

        printf("\nItem nao encontrado.\n");

    } else {

        if (anterior == NULL) {

            *inicio = atual->proximo;

        } else {

            anterior->proximo = atual->proximo;
        }

        free(atual);

        printf("\nItem removido com sucesso!\n");
    }
}

// ======================= MAIN =======================

int main() {

    struct Item mochila[MAX];
    struct No *lista = NULL;

    int totalItens = 0;
    int opcao;

    do {

        printf("\n===== MENU =====");
        printf("\n1 - Cadastrar item no vetor");
        printf("\n2 - Remover item do vetor");
        printf("\n3 - Buscar item no vetor");
        printf("\n4 - Listar itens do vetor");
        printf("\n5 - Ordenar vetor");
        printf("\n6 - Busca binaria no vetor");
        printf("\n7 - Inserir item na lista");
        printf("\n8 - Remover item da lista");
        printf("\n9 - Buscar item na lista");
        printf("\n10 - Listar lista encadeada");
        printf("\n0 - Sair");
        printf("\nEscolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            inserirItem(mochila, &totalItens);
            break;

        case 2:
            removerItem(mochila, &totalItens);
            break;

        case 3:
            buscarItem(mochila, totalItens);
            break;

        case 4:
            listarItens(mochila, totalItens);
            break;

        case 5:
            ordenarVetor(mochila, totalItens);
            break;

        case 6:
            buscarBinariaVetor(mochila, totalItens);
            break;

        case 7:
            inserirItemLista(&lista);
            break;

        case 8:
            removerItemLista(&lista);
            break;

        case 9:
            buscarItemLista(lista);
            break;

        case 10:
            listarItensLista(lista);
            break;

        case 0:
            printf("\nPrograma encerrado.\n");
            break;

        default:
            printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}