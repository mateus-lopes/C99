#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    char letras[4];
    struct Pilha* proximo;
} Pilha;

Pilha* inicializa() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->proximo = NULL;
    return pilha;
}

Pilha* push(Pilha** topo, char* item) {
    Pilha* copia = (Pilha*)malloc(sizeof(Pilha));
    for (int x = 0; x < 4; x++) 
        copia->letras[x] = item[x];
    copia->proximo = (*topo);
    (*topo) = copia;
}

int vazia(Pilha* topo) {
    return topo == NULL;
}

void pop(Pilha** topo) {
    if(vazia(*topo)) return;
    Pilha* temp = *topo;
    *topo = (*topo)->proximo;
    free(temp);
}

int busca(Pilha* topo, char* dados) {
    for (int x = 0; x < 4; x++) {
        if (topo->letras[x] != dados[3 - x]) return 0;
    }
    return 1;
}


int main() {
    int n_participantes;
    char letras[4];
    
    Pilha* pilha = inicializa();
    
    for (int x = 0; x < 4; x++)
        pilha->letras[x] = "FACE"[x];
    pilha->proximo = NULL;

    while (1) {
        scanf("%d", &n_participantes);
        if (n_participantes == 0) break;

        int num_presentes = 0;
        for (int i = 0; i < n_participantes; i++) {
            for (int x = 0; x < 4; x++)
                scanf(" %c", &letras[x]);

            if (busca(pilha, letras)) {
                num_presentes++;
                pop(&pilha);

                if (pilha == NULL) push(&pilha, "FACE");
            } else {
                push(&pilha, letras);
            }
        }

        printf("%d\n", num_presentes);
        exit(0);
    }

    return 0;
}