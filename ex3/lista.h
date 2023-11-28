#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int info;
    struct Lista* prox;
} Lista;

Lista* inicializa(void);
Lista* insere(Lista* l, int i);
void imprime(Lista* l);
int vazia(Lista* l);
Lista* busca(Lista* l, int v);
Lista* retira(Lista* l, int v);
void libera(Lista* l);
int josephus(Lista* l, int k);

#endif /* LISTA_H */
