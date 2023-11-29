#include <stdio.h>
#include <stdlib.h>

struct arvbin
{
    int info;
    int FB;
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

void imprime_emOrdem(Arv* a)
{
    if (!vazia(a))
    {
        imprime_emOrdem(a->esq);
        printf("%d ", a->info);
        imprime_emOrdem(a->dir);
    }
}

int main(void)
{
    int n, num;
    Arv* a = inicializa();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a = insere(a, num);
    }
    imprime_emOrdem(a);
    printf("\n");
    return 0;
}
