#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

No *criarNo(int dado) {
    No *novoNo = (No*) malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = novoNo;
    return novoNo;
}

No *criarListaCircular(int n) {
    No *cabeca = criarNo(1);
    No *anterior = cabeca;
    for (int i = 2; i <= n; i++) {
        No *temp = criarNo(i);
        anterior->proximo = temp;
        anterior = temp;
    }
    anterior->proximo = cabeca;
    return cabeca;
}

void problemaJosephus(No **cabeca, int k) {
    No *anterior = NULL;
    No *atual = *cabeca;
    while (atual->proximo != atual) {
        for (int contagem = 1; contagem < k; contagem++) {
            anterior = atual;
            atual = atual->proximo;
        }
        printf("Removendo pessoa numero: %d\n", atual->dado);
        anterior->proximo = atual->proximo;
        free(atual);
        atual = anterior->proximo;
    }
    *cabeca = atual;
}
