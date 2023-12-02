#ifndef mod_lista_enc_circular_h

struct Lista {
    int info;
    struct Lista *prox;
};

typedef struct Lista Lista;

Lista* inicializa(void);
Lista* insere(Lista* l, int i);
void imprime(Lista* l);
Lista* busca(Lista* l, int v);
Lista* retira(Lista* l, int v);
void libera(Lista* l);

#endif
