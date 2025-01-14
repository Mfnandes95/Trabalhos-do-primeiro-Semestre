#include <stdio.h>

int main() {
    int horas;
    float custo;

    printf("Informe o numero total de horas que o carro ficou estacionado: ");
    scanf("%d", &horas);

    custo = 0;

    if (horas <= 2) {
        custo = horas * 5.00;
    } else if (horas <= 5) {
        custo = 2 * 5.00 + (horas - 2) * 3.00;
    } else {
        custo = 2 * 5.00 + 3 * 3.00 + (horas - 5) * 2.00;
    }

    printf("O custo total do estacionamento e: R$%.2f\n", custo);

    return 0;
}
