#include <stdio.h>

   int main(){

     int numero;

     printf("Insira um numero");
     scanf("%d", &numero);

     if(numero < 2){
        printf("Insira um numero maior");
     }

       for(int i  = 1; i <= numero; i++){
           for(int k = 1; k <= numero; k++){
           for(int j = 1; j <= i; j++){
              printf("%d", j);
           }
           printf("\n");
       }
        }
    
    return 0;
   }