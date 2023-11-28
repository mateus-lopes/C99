#include "lista.h"
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

    if (l == NULL) {
        //lista vazia, insere o primeiro elemento
        novo->prox = novo;
        return novo;
    }

    Lista* anterior = l;
    Lista* atual = l->prox;

    //encontra a posição correta para inserir o novo elemento
    while (atual != l && i > atual->info) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novo;
    novo->prox = atual;

    //se o novo elemento for menor que o primeiro, atualiza o início da lista
    if (i < l->info) {
        return novo;
    }

    return l;
}

void imprime(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Lista* p = l;
    do {
        printf("info = %d\n", p->info);
        p = p->prox;
    } while (p != l);
}

int vazia(Lista* l) {
    return (l == NULL);
}

int josephus(Lista* l, int k) {
    if (vazia(l)) {
        printf("Lista vazia\n");
        return -1; //valor de retorno para indicar erro
    }

    Lista* pessoaAtual = l;
    Lista* pessoaRemovida;
    Lista* ultimaPessoa = NULL;

    while (pessoaAtual->prox != pessoaAtual) {
        //encontra a pessoa a ser removida
        for (int i = 1; i < k; i++) {
            ultimaPessoa = pessoaAtual;
            pessoaAtual = pessoaAtual->prox;
        }

        pessoaRemovida = pessoaAtual;
        printf("Pessoa %d foi removida\n", pessoaRemovida->info);

        //remove a pessoa
        ultimaPessoa->prox = pessoaAtual->prox;

        //se a pessoa removida era a primeira da lista, atualizamos o ponteiro de início
        if (pessoaRemovida == l) {
            l = ultimaPessoa->prox;
        }

        free(pessoaRemovida);

        //move para a próxima pessoa
        pessoaAtual = ultimaPessoa->prox;
    }

    return l->info;
}


void libera(Lista* l) {
    if (vazia(l)) {
        return;
    }

    Lista* p = l->prox;
    while (p != l) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }

    free(l);
}