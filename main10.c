#include <stdio.h>
  
  int main(){

   int velocidade;

   printf("Insira a velocidade do veiculo");
   scanf("%d", &velocidade);
    
    if (velocidade < 30){
        printf("Baixa!!");
    } else if (velocidade >= 30 && velocidade <= 60){
        printf("Media!!");
    } else if (velocidade > 60){
        printf("Alta!!");
    } else {
        printf("Insira uma velocidade valida");
    }

   return 0;
  }