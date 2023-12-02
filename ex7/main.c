// mateus lopes albano
// Vinicius Uliano

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

Arv* cria(int c, Arv* filho_esq, Arv* filho_dir)
{
    // diferença das listas e pilhas, aqui não precisamos criar um nó auxiliar
    // outra diferença é que aqui não precisamos verificar se a árvore está vazia
    Arv* p = (Arv*)malloc(sizeof(Arv)); // aloca memória para o nó
    p->info = c; // atribui o valor do nó
    p->esq = filho_esq; // atribui o filho da esquerda
    p->dir = filho_dir; // atribui o filho da direita
    return p;
}

int vazia(Arv* a)
{
    return a == NULL;
}

Arv* busca(Arv* a, int c)
{
    // aqui acontece a busca binária, muito diferente da busca sequencial
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
    // diferenta da lista circular, aqui não precisamos liberar no por no
    // diferente da lista encadeada, aqui não precisamos de um auxiliar
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
    // diferente da lista circular, aqui não precisamos inserir no final
    // diferente da lista encadeada, aqui não precisamos de um auxiliar também
    // ------
    // antes de inserir, precisamos verificar se a árvore está vazia 
    // e se o valor a ser inserido é menor ou maior que o valor da raiz
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
        imprime_emOrdem(a->esq); // Percorre e imprime os elementos do filho à esquerda
        printf("%d ", a->info);  // Imprime o valor do nó atual
        imprime_emOrdem(a->dir); // Percorre e imprime os elementos do filho à direita
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
