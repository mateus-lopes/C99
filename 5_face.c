#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    char dados[4];
    struct Pilha* proximo;
} Pilha;

void empilhar(Pilha** topo, char* novos_dados) {
    Pilha* novo_no = (Pilha*) malloc(sizeof(Pilha));
    for(int part_atual = 0; part_atual < 4; part_atual++)
        novo_no->dados[part_atual] = novos_dados[part_atual];
    novo_no->proximo = (*topo);
    (*topo) = novo_no;
}

int verificar(Pilha* topo, char* dados) {
    for(int part_atual = 0; part_atual < 4; part_atual++) {
        if(topo->dados[part_atual] != dados[3-part_atual])
            return 0;
    }
    return 1;
}

void desempilhar(Pilha** topo) {
    Pilha* temp = *topo;
    *topo = (*topo)->proximo;
    free(temp);
}

int main() {
    int qtd_participante;
    char dados[4];
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    for(int part_atual = 0; part_atual < 4; part_atual++)
        pilha->dados[part_atual] = "FACE"[part_atual];
    pilha->proximo = NULL;
    while(1) {
        scanf("%d", &qtd_participante);
        if(qtd_participante == 0)
            break;
        int num_brindes = 0;
        for(int visitante_atual = 0; visitante_atual < qtd_participante; visitante_atual++) {
            for(int part_atual = 0; part_atual < 4; part_atual++)
                scanf(" %c", &dados[part_atual]);
            if(verificar(pilha, dados)) {
                num_brindes++;
                desempilhar(&pilha);
                if(pilha == NULL) {
                    empilhar(&pilha, "FACE");
                }
            } else {
                empilhar(&pilha, dados);
            }
        }
        printf("%d\n", num_brindes);
        exit(0);
        while(pilha != NULL)
            desempilhar(&pilha);
        empilhar(&pilha, "FACE");
    }
    return 0;
}