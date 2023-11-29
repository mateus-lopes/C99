#include <stdio.h>
#include <stdlib.h>

#define max 100000

typedef struct Pilha {
    char pilha[max];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, char c) {
    p->pilha[++(p->topo)] = c;
}

int vazia(Pilha *p) {
    return (p->topo == -1);
}

char pop(Pilha *p) {
    if(vazia(p)) return '\0';
    return p->pilha[(p->topo)--];
}

int validarExpressao(char *expressao) {    
    Pilha pilha;
    inicializar(&pilha);
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '{' || expressao[i] == '[' || expressao[i] == '(') {
            push(&pilha, expressao[i]);
        } else {
            if (vazia(&pilha)) return 0;
            char topo = pop(&pilha);
            if ((expressao[i] == '}' && topo != '{') || (expressao[i] == ']' && topo != '[') || (expressao[i] == ')' && topo != '(')) {
                return 0;
            }
        }
    }
    return vazia(&pilha);
}

int main() {
    int tentativas;
    scanf("%d", &tentativas);

    while (tentativas--) {
        char expressao[max];
        scanf("%s", expressao);
        (validarExpressao(expressao)) ? printf("S\n") : printf("N\n");
    }

    return 0;
}
