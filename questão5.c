#include <stdio.h>

int main() {
    int altura;
    char opcao;

    
    printf("Informe a altura do triângulo: ");
    scanf("%d", &altura);


    printf("Preenchido (P) ou vazado (V): ");
    scanf(" %c", &opcao); 

    if (opcao == 'p' || opcao == 'P') {
      
        for (int i = 0; i < altura; i++) {
          
            for (int j = 0; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else if (opcao == 'v' || opcao == 'V') {
    
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j <= i; j++) {
             
                if (i == altura - 1 || j == 0 || j == i) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    } else {
      
        printf("Insira uma opcao valida!\n");
    }

    return 0;
}
