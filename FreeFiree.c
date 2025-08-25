#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10 

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Funções do sistema
void inserirItem(Item mochila[], int *qtdItens);
void removerItem(Item mochila[], int *qtdItens);
void listarItens(Item mochila[], int qtdItens);
void buscarItem(Item mochila[], int qtdItens);

int main() {
    Item mochila[MAX_ITENS]; 
    int qtdItens = 0;         
    int opcao;

    do {
        printf("\n=== SISTEMA DE INVENTARIO ===\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                inserirItem(mochila, &qtdItens);
                break;
            case 2:
                removerItem(mochila, &qtdItens);
                break;
            case 3:
                listarItens(mochila, qtdItens);
                break;
            case 4:
                buscarItem(mochila, qtdItens);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}

void inserirItem(Item mochila[], int *qtdItens) {
    if (*qtdItens >= MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n--- Inserir Novo Item ---\n");

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Tipo (arma, municao, cura, ferramenta...): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); 

    mochila[*qtdItens] = novo; 
    (*qtdItens)++;

    printf("Item adicionado com sucesso!\n");
}

void removerItem(Item mochila[], int *qtdItens) {
    if (*qtdItens == 0) {
        printf("A mochila esta vazia, nada para remover.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = -1;
    for (int i = 0; i < *qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item nao encontrado.\n");
        return;
    }

    for (int i = encontrado; i < *qtdItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*qtdItens)--;
    printf("Item removido com sucesso!\n");
}

void listarItens(Item mochila[], int qtdItens) {
    if (qtdItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\n--- Itens na Mochila ---\n");
    for (int i = 0; i < qtdItens; i++) {
        printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void buscarItem(Item mochila[], int qtdItens) {
    if (qtdItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado.\n");
}
