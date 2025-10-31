// programa que comeca com 2 itens, permite adicionar dinamicamente usando realloc e exibe a lista
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

static char *dup_trimmed(const char *s) {
    size_t len = strlen(s);
    // remover newline final se presente
    if (len > 0 && s[len - 1] == '\n') --len;
    char *p = malloc(len + 1);
    if (!p) return NULL;
    memcpy(p, s, len);
    p[len] = '\0';
    return p;
}

int main(void) {
    size_t n = 2;
    char **lista = calloc(n, sizeof *lista);
    if (lista == NULL) {
        printf("erro ao alocar memoria\n");
        return 1;
    }

    char buffer[BUF_SIZE];

    // ler os dois itens iniciais
    for (size_t i = 0; i < 2; ++i) {
        printf("item %zu: ", i + 1);
        if (fgets(buffer, sizeof buffer, stdin) == NULL) {
            printf("entrada invalida\n");
            for (size_t j = 0; j < i; ++j) free(lista[j]);
            free(lista);
            return 1;
        }
        lista[i] = dup_trimmed(buffer);
        if (lista[i] == NULL) {
            printf("erro ao alocar memoria\n");
            for (size_t j = 0; j < i; ++j) free(lista[j]);
            free(lista);
            return 1;
        }
    }

    // permitir que o usuario acrescente itens dinamicamente
    for (;;) {
        printf("deseja adicionar mais um item? (s/n): ");
        if (fgets(buffer, sizeof buffer, stdin) == NULL) break;
        if (buffer[0] == '\n') continue;
        char opc = buffer[0];
        if (opc == 'n' || opc == 'N') break;
        if (opc == 's' || opc == 'S') {
            printf("novo item: ");
            if (fgets(buffer, sizeof buffer, stdin) == NULL) break;
            char **tmp = realloc(lista, (n + 1) * sizeof *lista);
            if (tmp == NULL) {
                printf("erro ao realocar memoria\n");
                break;
            }
            lista = tmp;
            lista[n] = dup_trimmed(buffer);
            if (lista[n] == NULL) {
                printf("erro ao alocar memoria\n");
                break;
            }
            ++n;
        } else {
            continue;
        }
    }

    // exibir todos os itens
    printf("lista de compras (%zu itens):\n", n);
    for (size_t i = 0; i < n; ++i) {
        printf("%zu: %s\n", i + 1, lista[i]);
    }

    // liberar memoria
    for (size_t i = 0; i < n; ++i) free(lista[i]);
    free(lista);

    return 0;
}