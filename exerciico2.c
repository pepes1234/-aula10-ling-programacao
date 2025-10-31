#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n1, n2;

    // ler tamanhos dos vetores
    printf("tamanho do primeiro vetor: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) {
        printf("entrada invalida\n");
        return 1;
    }
    printf("tamanho do segundo vetor: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) {
        printf("entrada invalida\n");
        return 1;
    }

    // alocar os dois vetores
    int *v1 = malloc(n1 * sizeof *v1);
    if (v1 == NULL) {
        printf("erro ao alocar memoria\n");
        return 1;
    }
    int *v2 = malloc(n2 * sizeof *v2);
    if (v2 == NULL) {
        printf("erro ao alocar memoria\n");
        free(v1);
        return 1;
    }

    // preencher v1
    for (int i = 0; i < n1; ++i) {
        printf("v1[%d]: ", i + 1);
        if (scanf("%d", &v1[i]) != 1) {
            printf("entrada invalida\n");
            free(v1);
            free(v2);
            return 1;
        }
    }

    // preencher v2
    for (int i = 0; i < n2; ++i) {
        printf("v2[%d]: ", i + 1);
        if (scanf("%d", &v2[i]) != 1) {
            printf("entrada invalida\n");
            free(v1);
            free(v2);
            return 1;
        }
    }

    // criar vetor concatenado
    int n3 = n1 + n2;
    int *v3 = malloc(n3 * sizeof *v3);
    if (v3 == NULL) {
        printf("erro ao alocar memoria\n");
        free(v1);
        free(v2);
        return 1;
    }

    // copiar valores para v3
    for (int i = 0; i < n1; ++i) v3[i] = v1[i];
    for (int i = 0; i < n2; ++i) v3[n1 + i] = v2[i];

    // exibir vetor concatenado
    printf("vetor concatenado (%d elementos):\n", n3);
    for (int i = 0; i < n3; ++i) {
        printf("%d%c", v3[i], (i + 1 == n3) ? '\n' : ' ');
    }

    // liberar toda a memoria
    free(v1);
    free(v2);
    free(v3);

    return 0;
}