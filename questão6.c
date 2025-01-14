#include <stdio.h>

int main() {
    int B, L, A;

    do {
        printf("Digite o valor de B (ímpar, >= 3): ");
        scanf("%d", &B);

        if (B < 3 || B % 2 == 0) {
            printf("Erro: B deve ser um número ímpar e maior ou igual a 3.\n");
        }
    } while (B < 3 || B % 2 == 0); 


    do {
        printf("Digite o valor de L (ímpar, >= 1 e <= metade de B): ");
        scanf("%d", &L);

        printf("Digite o valor de A (>= 2 e <= metade de B): ");
        scanf("%d", &A);

        if (L < 1 || L > B / 2 || L % 2 == 0) {
            printf("Erro: L deve ser um número ímpar, pelo menos 1 e no máximo metade de B.\n");
        }

        if (A < 2 || A > B / 2) {
            printf("Erro: A deve ser pelo menos 2 e no máximo metade de B.\n");
        }
    } while ((L < 1 || L > B / 2 || L % 2 == 0) || (A < 2 || A > B / 2));


    int espacos = B / 2;
    int asteriscos = 1;

   
    for (int i = 0; i < (B / 2) + 1; i++) {
        for (int j = 0; j < espacos; j++) {
            printf(" ");
        }
        for (int j = 0; j < asteriscos; j++) {
            printf("*");
        }
        printf("\n");

        espacos--;
        asteriscos += 2;
    }


    int espacos_tronco = (B - L) / 2;

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < espacos_tronco; j++) {
            printf(" ");
        }
        for (int j = 0; j < L; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
