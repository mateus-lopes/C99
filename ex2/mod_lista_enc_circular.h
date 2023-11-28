#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

struct Node {
    int info;
    struct Node *prox;
};

typedef struct Node Node;

Node* inicializa(void);
Node* insere(Node* l, int i);
void imprime(Node* l);
Node* busca(Node* l, int v);
Node* retira(Node* l, int v);
void libera(Node* l);

#endif
