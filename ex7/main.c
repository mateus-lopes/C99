#include <stdio.h>
#include <stdlib.h>

struct arvbin
{
    char info;
    struct arvbin *esq;
    struct arvbin *dir;
};

typedef struct arvbin Arv;

Arv* inicializa(void)
{
    return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(Arv* a)
{
    return a == NULL;
}

Arv* busca(Arv* a, int c)
{
    if (vazia(a))
        return NULL;
    else if (a->info > c)
        return busca(a->esq, c);
    else if (a->info < c)
        return busca(a->dir, c);
    else
        return a;
}

Arv* libera(Arv* a)
{
    if (!vazia(a))
    {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

Arv* insere(Arv* a, int c)
{
    if (vazia(a))
        a = cria(c, NULL, NULL);
    else if (a->info > c)
        a->esq = insere(a->esq, c);
    else
        a->dir = insere(a->dir, c);
    return a;
}

void imprime(Arv* a)
{
    if (!vazia(a))
    {
        printf("%c", a->info); // mostra raiz
        imprime(a->esq); // mostra sae
        imprime(a->dir); // mostra sad
    }
}

int main(void)
{
    Arv* a1= cria('c', inicializa(), inicializa()); // sub-arvore com 'd'
    Arv* a2= cria('b', inicializa(), a1); // sub-arvore com 'b' e 'd'
    Arv* a3= cria('e', inicializa(), inicializa()); // sub-arvore com 'e'
    Arv* a4= cria('f', inicializa(), inicializa()); // sub-arvore com 'f'
    Arv* a5= cria('d', a3, a4); // sub-arvore com 'c', 'e' e 'f'
    Arv* a= cria('a', a2, a5); // arvore com 'a', 'b', 'c', 'd', 'e' e 'f'
    printf("Arvore a:\n");
    imprime(a);
    printf("\n");
    
    return 0;
}