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

int jogo(Lista* l, int cont) {
    if (l == NULL || cont <= 0) return -1;

    Lista* atual = l, *anterior = NULL, *remover;

    reinicio_do_loop:

    while (atual->prox != atual) {
        for (int x = 1; x < cont; x++) {
            anterior = atual;
            atual = atual->prox;
            printf("%d", anterior->info);
        }
        remover = atual;
    
        // Verificar se o valor de atual é 1
        if (atual->info == 1) {
            printf("- O valor de atual é 1\n");
            remover = anterior->prox;  // ou remover = atual; dependendo da lógica desejada
            goto reinicio_do_loop;
        }else {
            printf("- %d removido do jogo\n", remover->info);
            anterior->prox = atual->prox;
        
        }
    
        if (remover == l) l = anterior->prox;
        free(remover);
        atual = anterior->prox;
    }
    return l->info;
}
