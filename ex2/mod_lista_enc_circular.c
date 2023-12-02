#include "mod_lista_enc_circular.h"
#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};

Lista* inicializa(void) {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;

    // Se a lista estiver vazia (l == NULL), o novo nó aponta para si mesmo.
    if (l == NULL) {
        novo->prox = novo;
        return novo;
    } else {
    // Se a lista já contiver elementos, o novo nó é inserido no início, e seu próximo é ajustado para apontar para o antigo primeiro nó.
        novo->prox = l->prox;
        l->prox = novo;
        return l;
    }
}


void imprime(Lista* l) {
    if (l != NULL) {
        // a função imprime percorre a lista a partir do nó seguinte ao nó inicial (l->prox) até encontrar novamente esse nó (aux != l)
        Lista* aux = l;
        do {
            aux = aux->prox; // aqui estamos avançando o ponteiro aux para o próximo nó da lista para pegar o maior valor
            printf("info = %d\n", aux->info);
        } while (aux != l);
    }
}

Lista* busca(Lista* l, int v) {
    if (l == NULL) return NULL;

    Lista* aux = l;
    do {
        if (aux->info == v) return aux;
        aux = aux->prox;
    } while (aux != l); // busca item por item ate retornar ao inicio da lista

    return NULL;
}

Lista* retira(Lista* l, int v) {
    if (l == NULL) return NULL;

    Lista* ant = l;
    Lista* aux = l;

    do {
        if (aux->info == v) {
            ant->prox = aux->prox;
            if (aux == l) l = (l->prox == l) ? NULL : ant;
            free(aux);
            return l;
        }
        ant = aux;
        aux = aux->prox;
    } while (aux != l);
    // retira item por item ate retornar ao inicio da lista

    return l;
}

void libera(Lista* l) {
    if (l != NULL) {
        Lista* aux = l;
        Lista* prox;

        do {
            prox = aux->prox;
            free(aux);
            aux = prox;
        } while (aux != l);
        // libera no por no separadamente
    }
}

