#ifndef ESTRUTURA_DE_DADOS_LISTA_CIRCULAR_H
#define ESTRUTURA_DE_DADOS_LISTA_CIRCULAR_H


#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H


typedef struct No {
    int dado;
    struct No *proximo;
} No;

No *criarNo(int dado);
No *criarListaCircular(int n);
void problemaJosephus(No **cabeca, int k);


#endif
#endif //ESTRUTURA_DE_DADOS_LISTA_CIRCULAR_H
