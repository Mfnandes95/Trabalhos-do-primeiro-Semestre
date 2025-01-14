#include <stdio.h>

int main() {
    int numero;
    int dist10, dist100, dist1000;
    int maisProximo;

    printf("Informe um numero inteiro: ");
    scanf("%d", &numero);

    dist10 = (numero > 10) ? (numero - 10) : (10 - numero);
    dist100 = (numero > 100) ? (numero - 100) : (100 - numero);
    dist1000 = (numero > 1000) ? (numero - 1000) : (1000 - numero);

    if (dist10 <= dist100 && dist10 <= dist1000) {
        maisProximo = 10;
    } else if (dist100 <= dist10 && dist100 <= dist1000) {
        maisProximo = 100;
    } else {
        maisProximo = 1000;
    }

    printf("O numero %d esta mais proximo de %d.\n", numero, maisProximo);

    return 0;
}
