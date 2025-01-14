  #include <stdio.h>

int main() {
    int horario, trafego;
    int tempoVerde, tempoAmarelo, tempoVermelho;

    printf("Informe o horario do dia (1 = manha, 2 = tarde, 3 = noite): ");
    scanf("%d", &horario);
    printf("Informe o nivel de trafego (1 = baixo, 2 = medio, 3 = alto): ");
    scanf("%d", &trafego);

    tempoVerde = 0;
    tempoAmarelo = 0;
    tempoVermelho = 0;

    switch (horario) {
        case 1: 
            switch (trafego) {
                case 1: 
                    tempoVerde = 20; 
                    tempoAmarelo = 5; 
                    tempoVermelho = 30; 
                    break;
                case 2: 
                    tempoVerde = 25; 
                    tempoAmarelo = 7; 
                    tempoVermelho = 25; 
                    break;
                case 3: 
                    tempoVerde = 30; 
                    tempoAmarelo = 10; 
                    tempoVermelho = 20; 
                    break;
                default:
                    printf("Nivel de trafego invalido.\n");
                    return 1;
            }
            break;
        case 2: 
            switch (trafego) {
                case 1: 
                    tempoVerde = 25; 
                    tempoAmarelo = 5; 
                    tempoVermelho = 25; 
                    break;
                case 2: 
                    tempoVerde = 30; 
                    tempoAmarelo = 7; 
                    tempoVermelho = 20; 
                    break;
                case 3: 
                    tempoVerde = 35; 
                    tempoAmarelo = 10; 
                    tempoVermelho = 15; 
                    break;
                default:
                    printf("Nivel de trafego invalido.\n");
                    return 1;
            }
            break;
        case 3: 
            switch (trafego) {
                case 1: 
                    tempoVerde = 30; 
                    tempoAmarelo = 5; 
                    tempoVermelho = 20; 
                    break;
                case 2: 
                    tempoVerde = 35; 
                    tempoAmarelo = 7; 
                    tempoVermelho = 15; 
                    break;
                case 3: 
                    tempoVerde = 40; 
                    tempoAmarelo = 10; 
                    tempoVermelho = 10; 
                    break;
                default:
                    printf("Nivel de trafego invalido.\n");
                    return 1;
            }
            break;
        default:
            printf("Horario do dia invalido.\n");
            return 1;
    }

    printf("Tempo verde: %d segundos\n", tempoVerde);
    printf("Tempo amarelo: %d segundos\n", tempoAmarelo);
    printf("Tempo vermelho: %d segundos\n", tempoVermelho);

    return 0;
}
