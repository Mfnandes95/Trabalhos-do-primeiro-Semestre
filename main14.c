#include <stdio.h>
   
   int main(){
      
      int numero;
   
    printf("Insira um numero");
    scanf("%d", &numero);
  
    if (numero & 2 && numero & 3 && numero & 5){
        printf("O numero e divisivel por 2, 3 e 5");
    } else {
        printf("O numero nao e divisivel por 2, 3 e 5");
    }
    return 0;
   }