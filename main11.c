#include <stdio.h>
  
  int main(){
    
    int l1, l2,l3; 
    
    printf("Insira os tres lados\n");
    scanf("%d %d %d", &l1, &l2, &l3);

    if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1){

          if (l1 == l2 && l2 == l3){
            printf("O triangulo e equilatero\n");
          } else if (l1 == l2 || l1 == l3 || l2 == l3){
            printf("O triangulo e isoceles\n");
          } else {
            printf("O triangulo e escaleno\n");
          }
    } else {
        printf("Os valores nao forma um triangulo");
    }
    return 0;
  }