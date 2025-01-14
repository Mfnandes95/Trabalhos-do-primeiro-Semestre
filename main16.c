#include <stdio.h>

int main() {
    float valorCompra;
    float valorFinal;
    float desconto;

    printf("Informe o valor da compra: R$");
    scanf("%f", &valorCompra);

    if (valorCompra <= 100) {
        desconto = 0.05; 
    } else if (valorCompra <= 500) {
        desconto = 0.10; 
    } else {
        desconto = 0.15; 
    }

    valorFinal = valorCompra * (1 - desconto);

    printf("O valor final da compra apos o desconto e: R$%.2f\n", valorFinal);

    return 0;
}
