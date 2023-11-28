//Expressoes
//Gabriela e Camila
#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    char dados[100000];
    int topo;
} Pilha;

int vazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void push(Pilha *pilha, char c) {
    pilha->dados[++pilha->topo] = c;
}

char pop(Pilha *pilha) {
    return pilha->dados[pilha->topo--];
}

int bem_definida(char *s) {
    
    Pilha pilha;
    pilha.topo = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            
            push(&pilha, s[i]);

        } else {
            
            if (vazia(&pilha)) {
                return 0;
            }
           
            char topo = pop(&pilha);
            if ((s[i] == '}' && topo != '{') || (s[i] == ']' && topo != '[') || (s[i] == ')' && topo != '(')) {
                return 0;
            }
        }
    }
    return vazia(&pilha);
}

int main() {
    int T;
    char s[100000 + 1];

    scanf("%d", &T);

    char resultados[T];
    
    for (int i = 0; i < T; i++) {
        scanf("%s", s);
        resultados[i] = bem_definida(s) ? 'S' : 'N';
    }
    for (int i = 0; i < T; i++) {
        printf("%c\n", resultados[i]);
    }
    return 0;
}