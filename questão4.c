#include <stdio.h> 

int main() {
    int altura;
    char opcao;

    printf("Insira a altura do quadrado: ");
    scanf("%d", &altura);

   
    printf("Preenchido (P) ou vazado (V): ");
    scanf(" %c", &opcao); 

    if (opcao == 'p' || opcao == 'P') {
      
        for (int i = 0; i < altura; i++) { 
            for (int j = 0; j < altura; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else if (opcao == 'v' || opcao == 'V') {
       
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < altura; j++) {
                if (i == 0 || i == altura - 1 || j == 0 || j == altura - 1) {
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
