#include <stdio.h>

int main() {
    float clima;
    float temperatura;

    printf("Informe o tipo de clima (1 = ensolarado, 2 = nublado, 3 = chuvoso): ");
    scanf("%f", &clima);
    printf("Informe a temperatura atual em graus Celsius: ");
    scanf("%f", &temperatura);

    if (clima == 1) { 
        if (temperatura > 25) {
            printf("Sugestoes: Ir a praia ou fazer um piquenique.\n");
        } else if (temperatura >= 15 && temperatura <= 25) {
            printf("Sugestoes: Caminhadas ou passeios de bicicleta.\n");
        } else if (temperatura < 15) {
            printf("Sugestoes: Fotografia da natureza ou observacao de passaros.\n");
        }
    } else if (clima == 2) { 
        if (temperatura > 20) {
            printf("Sugestoes: Visitar museus ou fazer compras em centros comerciais ao ar livre.\n");
        } else if (temperatura >= 10 && temperatura <= 20) {
            printf("Sugestoes: Passeios culturais, como galerias de arte ou teatros.\n");
        } else if (temperatura < 10) {
            printf("Sugestoes: Leitura em bibliotecas ou sessoes de cinema.\n");
        }
    } else if (clima == 3) { 
        if (temperatura > 15) {
            printf("Sugestoes: Visitar um spa ou fazer aulas de culinaria.\n");
        } else if (temperatura >= 5 && temperatura <= 15) {
            printf("Sugestoes: Museus de ciencia ou sessoes de boliche.\n");
        } else if (temperatura < 5) {
            printf("Sugestoes: Tarde de jogos de tabuleiro em casa ou uma maratona de filmes.\n");
        }
    } else {
        printf("Tipo de clima invalido.\n");
    }

    return 0;
}
