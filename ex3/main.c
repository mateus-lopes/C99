#include "lista.h"


int main() {
    int n, k;
    printf("Digite o numero de pessoas (n): ");
    scanf("%d", &n);
    printf("Digite o numero de contagem (k): ");
    scanf("%d", &k);

    Lista* lista = inicializa();

    for (int i = 1; i <= n; i++) {
        lista = insere(lista, i);
    }

    int ultima_pessoa = josephus(lista, k);

    if (ultima_pessoa != -1) {
        printf("\nA ultima pessoa restante e: %d\n", ultima_pessoa);
    }

    libera(lista);

    return 0;
}