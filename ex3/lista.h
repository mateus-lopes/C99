#ifndef LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int info;
    struct Lista* prox;
} Lista;

typedef struct Lista Lista;

Lista* inicializa(void);
Lista* insere(Lista* l, int i);
void libera(Lista* l);
int jogo(Lista* l, int cont);

#endif