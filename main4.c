#include <stdio.h>
int main(){
  
   int idade;

   printf("Insira sua idade:");
   scanf("%d", &idade);

   if (idade >= 18){
    printf("Apto a votar");
   } else{
    printf("Inapto a votar");
   }

    return 0;
}