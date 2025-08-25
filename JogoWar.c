#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Representa cada território do jogo com:
// - nome: até 30 caracteres
// - cor do exército: até 10 caracteres
// - tropas: número inteiro representando quantidade de tropas
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor para armazenar 5 territórios
    Territorio territorios[5];

    // Cadastro dos 5 territórios
    printf("=== Cadastro de Territorios ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);

        // Leitura do nome
        printf("Digite o nome do territorio: ");
        scanf(" %[^\n]", territorios[i].nome);  // Lê string com espaço

        // Leitura da cor
        printf("Digite a cor do exercito: ");
        scanf(" %s", territorios[i].cor); // Lê string sem espaços

        // Leitura da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territorios Cadastrados ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
