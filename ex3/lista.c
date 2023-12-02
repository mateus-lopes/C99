#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* inicializa(void) {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;

    if (l == NULL) {
        novo->prox = novo; 
        return novo; 
    } else {
        novo->prox = l->prox;
        l->prox = novo; 
        return l;
    }
}

void libera(Lista* l) {
    if (l != NULL) {
        Lista* aux = l->prox;
        while (aux != l) {
            Lista* prox = aux->prox;
            free(aux);
            aux = prox;
        }
        free(l);
    }
}

int jogo(Lista* l, int cont) {
    if (l == NULL) return -1;

    Lista* atual = l, *anterior = NULL, *remover;

    while (atual->prox != atual) {
        for (int x = 1; x < cont; x++) {
            anterior = atual;
            atual = atual->prox;
        }
        remover = atual;
        printf("Pessoa %d está removida do jogo\n", remover->info);

        anterior->prox = atual->prox;

        if (remover == l) l = anterior->prox;
        free(remover);
        atual = anterior->prox;
    }
    return l->info;
}