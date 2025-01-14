#include <stdio.h>
  int main(){
    
    int dia;

    printf("Insira o  dia da semana:");
    scanf("%d", &dia);

    switch (dia)
    {
    case 1:
       (dia = 1);
       printf("Segunda-Feira\n");
        break;
    case 2:
       (dia = 2);
       printf("Terca-feira\n");
       break;
    case 3:
       (dia = 3);
       printf("Quarta-feira\n");
       break;
    case 4: 
      (dia = 4);
      printf("Quinta-feira\n");
      break;
    case 5:
      (dia = 5);
      printf("Sexta-feira\n");
      break;
    case 6: 
      (dia = 6);
      printf("Sabado\n");
      break;
    case 7: 
      (dia = 7);
      printf("Domingo!\n");
      break;
    default:
        break;
    }
    return 0;
  }