#include "mod_lista_enc_circular.h"
#include <stdio.h>
#include <stdlib.h>

Node* inicializa(void) {
    return NULL;
}

Node* insere(Node* l, int i) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->info = i;

    if (l == NULL) {
        novo->prox = novo;  // Se a lista está vazia, faz o nó apontar para si mesmo
        return novo;  // Retorna o novo nó, que agora é o único nó da lista
    } else {
        novo->prox = l->prox;  // O novo nó aponta para o primeiro nó da lista
        l->prox = novo;  // O último nó da lista aponta para o novo nó
        return l;  // Retorna o último nó da lista, que continua sendo o último
    }
}

void imprime(Node* l) {
    if (l != NULL) {
        Node* aux = l->prox;  // Inicia a impressão a partir do primeiro nó da lista
        do {
            printf("info = %d\n", aux->info);
            aux = aux->prox;
        } while (aux != l->prox);  // Continua até chegar novamente ao primeiro nó
    }
}

Node* busca(Node* l, int v) {
    if (l == NULL) {
        return NULL;
    }

    Node* aux = l->prox;
    do {
        if (aux->info == v) {
            return aux;
        }
        aux = aux->prox;
    } while (aux != l->prox);

    return NULL;
}

Node* retira(Node* l, int v) {
    if (l == NULL) {
        return NULL;
    }

    Node* ant = l;
    Node* aux = l->prox;

    while (aux != l && aux->info != v) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == l) {
        return l;
    }

    ant->prox = aux->prox;
    if (aux == l->prox) {
        l = (l->prox == l) ? NULL : ant;  
    }

    free(aux);

    return l;
}

void libera(Node* l) {
    if (l != NULL) {
        Node* aux = l->prox;
        while (aux != l) {
            Node* prox = aux->prox;
            free(aux);
            aux = prox;
        }
        free(l);
    }
}
