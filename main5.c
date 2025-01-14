#include <stdio.h>
  int main(){
    
    int numero;

    printf("Insira um numero:");
    scanf("%d", &numero);

    if (numero & 5 ){
        printf("o numero e multiplo de 5");
    } else {
        printf("O numero nao e multiplo de 5");
    }

    return 0;
  }