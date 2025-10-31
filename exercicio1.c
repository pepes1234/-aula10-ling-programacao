#include <stdio.h>
#include <stdlib.h>

// programa que le uma quantidade n de numeros, exibe apenas os pares e libera memoria
int main(void) {
    int n;

    // solicitar ao usuario quantos numeros ele quer digitar
    printf("quantos numeros deseja digitar? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("entrada invalida\n");
        return 1;
    }

    // alocar dinamicamente um vetor de inteiros
    int *vetor = malloc(n * sizeof *vetor);
    if (vetor == NULL) {
        printf("erro ao alocar memoria\n");
        return 1;
    }

    // ler os numeros
    for (int i = 0; i < n; ++i) {
        printf("numero %d: ", i + 1);
        if (scanf("%d", &vetor[i]) != 1) {
            printf("entrada invalida\n");
            free(vetor);
            return 1;
        }
    }

    // exibir apenas os numeros pares
    printf("numeros pares:\n");
    int encontrou = 0;
    for (int i = 0; i < n; ++i) {
        if (vetor[i] % 2 == 0) {
            printf("%d\n", vetor[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("nenhum numero par\n");
    }

    // liberar a memoria
    free(vetor);
    return 0;
}