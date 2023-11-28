#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100000

// Definição da estrutura da pilha
typedef struct {
    char pilha[TAMANHO_MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para empilhar um caractere
void empilhar(Pilha *p, char c) {
    p->pilha[++(p->topo)] = c;
}

// Função para desempilhar um caractere
char desempilhar(Pilha *p) {
    return p->pilha[(p->topo)--];
}

// Função para obter o topo da pilha sem remover
char topo(Pilha *p) {
    return p->pilha[p->topo];
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return (p->topo == -1);
}

// Função para verificar se uma expressão é bem definida
int ehBemDefinida(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char caractereAtual = expressao[i];
        if (caractereAtual == '{' || caractereAtual == '[' || caractereAtual == '(') {
            empilhar(&pilha, caractereAtual);
        } else if (caractereAtual == '}' || caractereAtual == ']' || caractereAtual == ')') {
            if (estaVazia(&pilha) || caractereAtual != topo(&pilha)) {
                return 0; // Não é bem definida
            } else {
                desempilhar(&pilha);
            }
        }
    }

    return estaVazia(&pilha); // É bem definida se a pilha estiver vazia no final
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        char expressao[TAMANHO_MAX];
        scanf("%s", expressao);

        if (ehBemDefinida(expressao)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
