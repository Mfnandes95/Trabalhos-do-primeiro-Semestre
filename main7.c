#include <stdio.h>
  int main(){
    
    int niveldaagua;

    printf("Insira o nivel da agua:");
    scanf("%d", &niveldaagua);

     if(niveldaagua >= 0 && niveldaagua <= 20 ){
        printf("Tanque Baixo!\n");
     } else if (niveldaagua > 20 && niveldaagua <= 60){
        printf("Tanque Medio!!\n");
        } else if (niveldaagua > 60 && niveldaagua <= 120){
            printf("Tanque Cheio!!!");
        } else {
            printf("Numero Invalido!!!!");
        }
     

    return 0;
  }