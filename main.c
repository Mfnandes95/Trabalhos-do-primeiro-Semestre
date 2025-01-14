#include <stdio.h>
 
 int main(){

 int número;
    
    printf("Insira um numero:");
    scanf("%d", &número);

    if(número > 0){
        printf("O numero é positivo");
    } else if (número < 0){
        printf("O numero e negativo");
    }else {
        printf("O numero e zero");
    }
    return 0;
 }