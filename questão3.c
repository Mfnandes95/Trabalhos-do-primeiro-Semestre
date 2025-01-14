#include <stdio.h>

int main() {
    int largura;

    printf("Informe a largura: ");
    scanf("%d", &largura);

    if (largura % 2 == 0) {
        printf("Numero par. Por favor, insira um numero impar.\n");
        return 1;
    }

    int metade = largura / 2;


    for (int i = 0; i <= metade; i++) {
    
        for (int j = i; j < metade; j++) {
            printf(" ");
        }
      
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = metade - 1; i >= 0; i--) {
     
        for (int j = i; j < metade; j++) {
            printf(" ");
        }
        
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

