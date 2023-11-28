#include <stdio.h>
#include <stdlib.h>

#define max 1000

struct Pilha {
    int topo;
    int itens[max];
};

typedef struct Pilha Pilha;

void inicializaPilha(Pilha* pilha) { pilha->topo = -1; }

int pilhaVazia(Pilha* pilha) { return pilha->topo == -1; }

int pilhaCheia(Pilha* pilha) { return pilha->topo == max - 1; }

int push(Pilha* pilha, int valor) {
    if (pilhaCheia(pilha)) {
        printf("Erro: Pilha cheia, não é possível inserir mais elementos.\n");
        return 0;
    }
    pilha->topo++;
    pilha->itens[pilha->topo] = valor;
    return valor;
}

int pop(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Erro: Pilha vazia, não é possível remover elementos.\n");
        return -1;
    }
    int valorRemovido = pilha->itens[pilha->topo];
    pilha->topo--;
    return valorRemovido;
}

int main() {
    Pilha pilha;
    inicializaPilha(&pilha);
    printf("-PUSH----------------------\n");
    printf("Elemento sendo adicionado: %d\n", push(&pilha, 1));
    printf("Elemento sendo adicionado: %d\n", push(&pilha, 2));
    printf("Elemento sendo adicionado: %d\n", push(&pilha, 3));
    printf("-POP-----------------------\n");
    printf("Elemento sendo removido: %d\n", pop(&pilha));
    printf("Elemento sendo removido: %d\n", pop(&pilha));
    printf("Elemento sendo removido: %d\n", pop(&pilha));
    printf("-LISTA---------------------\n");
    printf("A lista esta vazia agora\n");
    return 0;
}
