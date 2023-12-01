#include "lista.h"


int main() {
    int n_pessoas, contador;

    printf("Digite a quantidade de pessoas e o numero de contagem: ");
    scanf("%d %d", &n_pessoas, &contador);

    Lista* lista = inicializa();


    for (int i = 0; i < n_pessoas; i++) {
        lista = insere(lista, i+1);
    }

    int ultimo = jogo(lista, contador);

    if (ultimo != -1) printf("\nO vencedor é: %d\n", ultimo);

    libera(lista);
    return 0;
}