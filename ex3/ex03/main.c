#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.c"

int main() {
    int n, k;
    printf("Informe o numero de pessoas: ");
    scanf("%d", &n);

    printf("Informe o numero de contagem: ");
    scanf("%d", &k);

    No *cabeca = criarListaCircular(n);

    problemaJosephus(&cabeca, k);

    printf("A ultima pessoa restante foi: %d\n", cabeca->dado);

    free(cabeca);
    return 0;
}
