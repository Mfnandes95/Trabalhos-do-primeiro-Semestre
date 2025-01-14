#include <stdio.h>

int main() {
    int n1, n2, operador, resultado;

    printf("Insira um numero: ");
    scanf("%d", &n1);

    printf("Insira outro numero: ");
    scanf("%d", &n2);

    printf("Escolha um operador (1 - soma, 2 - subtracao, 3 - multiplicacao, 4 - divisao): ");
    scanf("%d", &operador);

    switch (operador) {
        case 1:
            resultado = n1 + n2;
            printf("O resultado da soma e: %d\n", resultado);
            break;
        case 2:
            resultado = n1 - n2;
            printf("O resultado da subtração e: %d\n", resultado);
            break;
        case 3:
            resultado = n1 * n2;
            printf("O resultado da multiplicação e: %d\n", resultado);
            break;
        case 4:
            if (n2 != 0) {
                resultado = n1 / n2;
                printf("O resultado da divisão e: %d\n", resultado);
            } else {
                printf("Erro: Divisao por zero nao e permitida.\n");
            }
            break;
        default:
            printf("Operador invalido.\n");
            break;
    }

    return 0;
}
