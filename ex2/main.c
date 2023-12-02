// mateus lopes albano
// Vinicius Uliano

#include "mod_lista_enc_circular.h"
#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    Lista* lista = inicializa();
    int i = 0;
    
    printf("\n1. Inserção de 10 elementos\n");
    while (i <= 10) {
        lista = insere(lista, i);
        i++;
    }

    printf("\n2. Impressão de todos elementos\n");
    imprime(lista);

    printf("\n3. Busca de 1 elemento presente na lista\n");
    Lista* resultado_busca = busca(lista, 5);
    if (resultado_busca != NULL) {
        printf("Elemento 5 encontrado.\n");
    } else {
        printf("Elemento 5 não encontrado.\n");
    }
    
    printf("\n4. Busca de 1 elemento não presente na lista\n");
    Lista* resultado_busca2 = busca(lista, 98);
    if (resultado_busca2 != NULL) {
        printf("Elemento 98 encontrado.\n");
    } else {
        printf("Elemento 98 não encontrado.\n");
    }

    printf("\n5. Impressão de todos elementos\n");
    imprime(lista);


    printf("\n6. Retirar 2 elementos e liberação de todos os elementos da lista\n");
    lista = retira(lista, 3);
    lista = retira(lista, 8);

    printf("\n7. Impressão de todos elementos\n");
    imprime(lista);


    printf("\n8. Liberação de todos elementos da memória\n");
    libera(lista);

    return 0;
}