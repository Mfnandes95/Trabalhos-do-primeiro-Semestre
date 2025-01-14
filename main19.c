#include <stdio.h>

int main() {
    int tipoProduto;
    int quantidade;
    float precoUnitario;
    float precoTotal;
    float desconto;
    float precoFinal;

    printf("Informe o tipo de produto (1-5): ");
    scanf("%d", &tipoProduto);
    printf("Informe a quantidade adquirida: ");
    scanf("%d", &quantidade);

    
    switch (tipoProduto) {
        case 1:
            precoUnitario = 150.00;
            break;
        case 2:
            precoUnitario = 50.00;
            break;
        case 3:
            precoUnitario = 80.00;
            break;
        case 4:
            precoUnitario = 120.00;
            break;
        case 5:
            precoUnitario = 90.00;
            break;
        default:
            printf("Tipo de produto inválido.\n");
            return 1; 
    }

    precoTotal = precoUnitario * quantidade;

    if (quantidade >= 1 && quantidade <= 5) {
        desconto = 0.05; 
    } else if (quantidade >= 6 && quantidade <= 10) {
        desconto = 0.10; 
    } else if (quantidade > 10) {
        desconto = 0.15; 
    } else {
        desconto = 0.0;
    }

    precoFinal = precoTotal * (1 - desconto);

    printf("Preço final apos o desconto e: R$%.2f\n", precoFinal);

    return 0;
}
