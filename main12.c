#include <stdio.h>
 
  int main(){
    
    int ano;

    printf("insira o ano");
    scanf("%d", &ano);

    if (ano % 4 == 0 ){
        printf("Ano bissexto!");
    } else if (ano % 400 == 0) {
        printf("Ano bissesxto");
    } else {
        printf("Nao e bissexto");
    }
    return 0;
  }