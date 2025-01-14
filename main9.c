#include <stdio.h>
   
   int main(){
    
    int nota;

    printf("Insira sua nota:");
    scanf("%d", &nota);

 if (nota >= 80 && nota < 100){
    printf("Excelente!!\n");
 } else if (nota >= 60 && nota < 79){
    printf("Bom!!");
 } else if (nota >= 40 && nota < 59){
    printf("Suficiente!");
 } else if (nota < 40) {
    printf("Insuficiente!");
 } else {
    printf("Insira uma nota valida");
 }

    return 0;
   }