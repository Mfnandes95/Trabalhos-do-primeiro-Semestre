#include <stdio.h>
  
int main() {
    float altura;
    float peso;
    float imc;

    printf("Insira sua altura (em metros): ");
    scanf("%f", &altura);
    printf("Insira seu peso (em kg): ");
    scanf("%f", &peso);

    imc = peso / (altura * altura);

    // Imprime o valor do IMC para verificação
    printf("Seu IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Peso normal\n");
    } else if (imc >= 25.0 && imc <= 29.9) {
        printf("Sobrepeso\n");
    } else {
        printf("Obeso\n");
    }
       
    return 0;
}
