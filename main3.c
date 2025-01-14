#include <stdio.h>
 
 int main(){
  
   int temperatura;

   printf("Insira a temperatura atual:");
   scanf("%d", &temperatura);

   if (temperatura >= 30 ){
    printf("Esta quente");
   } else {
    printf("Esta frio");
   }

    return 0;
 }