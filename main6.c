#include <stdio.h>
  
  int main(){
   
   int numero;
   
   printf("Insira um numero de zero a cem:");
   scanf("%d", &numero);

   if (numero > 100){
    printf("Acima de cem = invalido");
   } else{
    printf("Entre um e cem = valido");
   }
   
   return 0;
  }