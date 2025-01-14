#include <stdio.h>

int main() {
    int tipoEvento;
    int assentosDesejados;
    int capacidadeMaxima;
    int assentosDisponiveis;
    
    
    int capacidadeConcertos = 500;
    int capacidadeTeatros = 200;
    int capacidadeEventosEsportivos = 1000;
    int capacidadeConferencias = 300;

    printf("Selecione o tipo de evento:\n");
    printf("1: Concerto\n");
    printf("2: Teatro\n");
    printf("3: Evento Esportivo\n");
    printf("4: Conferencia\n");
    scanf("%d", &tipoEvento);

    switch (tipoEvento) {
        case 1:
            capacidadeMaxima = capacidadeConcertos;
            assentosDisponiveis = capacidadeConcertos;
            break;
        case 2:
            capacidadeMaxima = capacidadeTeatros;
            assentosDisponiveis = capacidadeTeatros;
            break;
        case 3:
            capacidadeMaxima = capacidadeEventosEsportivos;
            assentosDisponiveis = capacidadeEventosEsportivos;
            break;
        case 4:
            capacidadeMaxima = capacidadeConferencias;
            assentosDisponiveis = capacidadeConferencias;
            break;
        default:
            printf("Tipo de evento invalido.\n");
            return 1;
    }

    printf("Informe o numero de assentos desejados: ");
    scanf("%d", &assentosDesejados);


    if (assentosDesejados <= assentosDisponiveis) {
        assentosDisponiveis -= assentosDesejados;
        printf("Reserva confirmada. Numero de assentos reservados: %d\n", assentosDesejados);
        printf("Assentos restantes: %d\n", assentosDisponiveis);
    } else {
        printf("Nao ha assentos suficientes disponíveis para a reserva.\n");
    }

    return 0;
}
