#include "mod_lista_enc_circular.h"
#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    Lista* lista = inicializa();

    // 1. Inserção de 10 elementos
    for (int i = 1; i <= 10; i++) {
        lista = insere(lista, i);
    }

    // 2. Impressão de todos elementos
    printf("Lista inicial:\n");
    imprime(lista);

    // 3. Busca de 1 elemento presente na lista
    Lista* resultado_busca = busca(lista, 5);
    if (resultado_busca != NULL) {
        printf("Elemento 5 encontrado.\n");
    } else {
        printf("Elemento 5 não encontrado.\n");
    }
    
    // 4. Busca de 1 elemento não presente na lista
    Lista* resultado_busca = busca(lista, 98);
    if (resultado_busca != NULL) {
        printf("Elemento 98 encontrado.\n");
    } else {
        printf("Elemento 98 não encontrado.\n");
    }

    // 5. Impressão de todos elementos
    printf("Lista após buscas:\n");
    imprime(lista);

    // 6. Retirar 2 elementos e liberação de todos os elementos da lista
    lista = retira(lista, 3);
    lista = retira(lista, 8);

    // 7. Impressão de todos elementos
    printf("Lista após retirar elementos:\n");
    imprime(lista);

    // 8. Liberação de todos elementos da memória
    libera(lista);

    return 0;
}