#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

Sala* criarSala(const char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro: não foi possível alocar memória para a sala.\n");
        exit(1);
    }
    
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    
    return novaSala;
}

void explorarSalas(Sala* atual) {
    char opcao;
    
    while (atual != NULL) {
        printf("\nVocê está na: %s\n", atual->nome);
        
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou a um cômodo sem saída!\n");
            printf("Exploração encerrada.\n");
            break;
        }
        
        printf("Opções disponíveis:\n");
        if (atual->esquerda != NULL) {
            printf("  (e) Ir para a esquerda - %s\n", atual->esquerda->nome);
        }
        if (atual->direita != NULL) {
            printf("  (d) Ir para a direita - %s\n", atual->direita->nome);
        }
        printf("  (s) Sair do jogo\n");
        
        printf("\nPara onde deseja ir? ");
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case 'e':
            case 'E':
                if (atual->esquerda != NULL) {
                    atual = atual->esquerda;
                } else {
                    printf("Não há caminho à esquerda!\n");
                }
                break;
                
            case 'd':
            case 'D':
                if (atual->direita != NULL) {
                    atual = atual->direita;
                } else {
                    printf("Não há caminho à direita!\n");
                }
                break;
                
            case 's':
            case 'S':
                printf("Saindo do jogo...\n");
                return;
                
            default:
                printf("Opção inválida! Use 'e' para esquerda, 'd' para direita ou 's' para sair.\n");
                break;
        }
    }
}

void liberarArvore(Sala* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    printf("=== Detective Quest ===\n");
    printf("Bem-vindo à mansão misteriosa!\n");
    printf("Explore os cômodos para encontrar pistas.\n");
    
    Sala* hallEntrada = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jardim = criarSala("Jardim");
    Sala* quarto = criarSala("Quarto Principal");
    Sala* porao = criarSala("Porão");
    Sala* escritorio = criarSala("Escritório Secreto");
    
    hallEntrada->esquerda = salaEstar;
    hallEntrada->direita = cozinha;
    
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    
    cozinha->esquerda = quarto;
    cozinha->direita = porao;
    
    porao->direita = escritorio;
    
    explorarSalas(hallEntrada);
    
    liberarArvore(hallEntrada);
    
    printf("\nObrigado por jogar Detective Quest!\n");
    return 0;
}
