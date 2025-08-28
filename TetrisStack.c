#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5 

typedef struct {
    char tipo; 
    int id;    
} Peca;

typedef struct {
    Peca pecas[MAX];
    int frente, tras, tamanho;
} Fila;

void inicializarFila(Fila *fila);
int estaVazia(Fila *fila);
int estaCheia(Fila *fila);
void enfileirar(Fila *fila, Peca nova);
Peca desenfileirar(Fila *fila);
void exibirFila(Fila *fila);

Peca gerarPeca(int id);

int main() {
    Fila fila;
    inicializarFila(&fila);

    int id = 0; 
    int opcao;

    for (int i = 0; i < MAX; i++) {
        enfileirar(&fila, gerarPeca(id++));
    }

    do {
        printf("\n=== FILA DE PECAS DO TETRIS STACK ===\n");
        exibirFila(&fila);

        printf("\nOpcoes:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!estaVazia(&fila)) {
                    Peca jogada = desenfileirar(&fila);
                    printf("Peca [%c %d] jogada com sucesso!\n", jogada.tipo, jogada.id);
                } else {
                    printf("Fila vazia! Nenhuma peca para jogar.\n");
                }
                break;

            case 2:
                if (!estaCheia(&fila)) {
                    enfileirar(&fila, gerarPeca(id++));
                    printf("Nova peca inserida!\n");
                } else {
                    printf("Fila cheia! Nao e possivel inserir nova peca.\n");
                }
                break;

            case 0:
                printf("Encerrando simulacao...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

int estaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

int estaCheia(Fila *fila) {
    return fila->tamanho == MAX;
}

void enfileirar(Fila *fila, Peca nova) {
    if (estaCheia(fila)) return;
    fila->tras = (fila->tras + 1) % MAX;
    fila->pecas[fila->tras] = nova;
    fila->tamanho++;
}

Peca desenfileirar(Fila *fila) {
    Peca removida = fila->pecas[fila->frente];
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;
    return removida;
}

void exibirFila(Fila *fila) {
    if (estaVazia(fila)) {
        printf("\nFila vazia!\n");
        return;
    }

    printf("\nFila de pecas: ");
    for (int i = 0; i < fila->tamanho; i++) {
        int indice = (fila->frente + i) % MAX;
        printf("[%c %d] ", fila->pecas[indice].tipo, fila->pecas[indice].id);
    }
    printf("\n");
}

Peca gerarPeca(int id) {
    Peca nova;
    char tipos[] = {'I', 'O', 'T', 'L'};
    int indice = rand() % 4;  // Sorteia entre 0 e 3
    nova.tipo = tipos[indice];
    nova.id = id;
    return nova;
}
