#include "mod_lista_enc_circular.h"
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

void imprime(Lista* l) {
    if (l != NULL) {
        Lista* aux = l->prox;
        do {
            printf("info = %d\n", aux->info);
            aux = aux->prox;
        } while (aux != l->prox);
    }
}

Lista* busca(Lista* l, int v) {
    if (l == NULL) return NULL;

    Lista* aux = l->prox;
    do {
        if (aux->info == v) return aux;
        aux = aux->prox;
    } while (aux != l->prox);

    return NULL;
}

Lista* retira(Lista* l, int v) {
    if (l == NULL) return NULL;

    Lista* ant = l;
    Lista* aux = l->prox;

    while (aux != l && aux->info != v) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == l) return l;

    ant->prox = aux->prox;

    if (aux == l->prox) l = (l->prox == l) ? NULL : ant;
    
    free(aux);
    return l;
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
