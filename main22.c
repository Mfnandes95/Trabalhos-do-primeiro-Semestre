#include <stdio.h>

int main() {
    float renda;
    float imposto;
    int faixa;

    printf("Informe sua renda anual em R$: ");
    scanf("%f", &renda);

    if (renda <= 22000) {
        faixa = 1;
    } else if (renda <= 45000) {
        faixa = 2; 
    } else {
        faixa = 3; 
    }

    switch (faixa) {
        case 1:
            imposto = renda * 0.05; 
            break;
        case 2:
            imposto = renda * 0.15; 
            break;
        case 3:
            imposto = renda * 0.25;
            break;
        default:
            printf("Faixa de imposto invalida.\n");
            return 1;
    }

    printf("O imposto a ser pago e: R$%.2f\n", imposto);

    return 0;
}
