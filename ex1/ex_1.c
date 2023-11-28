#include <stdio.h>
#include <stdlib.h>

struct lista_enc {
    int info;
    struct lista_enc *prox;
};

typedef struct lista_enc Lista;

Lista* inicializa(void) {
    return NULL;
}

Lista* insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

int vazia(Lista* l) {
    return (l == NULL);
}

Lista* busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v)
            return p;
    }
    return NULL;
}

Lista* retira(Lista* l, int v) {
    Lista* ant = NULL;
    Lista* p = l;
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
        return l;
    if (ant == NULL) {
        l = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

void libera(Lista* l) {
    Lista* p = l;
    Lista* t = NULL;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}

Lista* insere_ordenado(Lista* l, int v) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = NULL;

    Lista** p = &l;

    while (*p != NULL && v > (*p)->info) {
        p = &(*p)->prox;
    }

    novo->prox = *p;
    *p = novo;

    return l;
}


int main(void) {
    Lista* lista = inicializa();

    lista = insere_ordenado(lista, 4);
    lista = insere_ordenado(lista, 2);
    lista = insere_ordenado(lista, 5);
    lista = insere_ordenado(lista, 3);
    lista = insere_ordenado(lista, 1);
    lista = insere_ordenado(lista, 6);

    printf("Lista ordenada: \n");
    imprime(lista);
    libera(lista);

    return 0;
}