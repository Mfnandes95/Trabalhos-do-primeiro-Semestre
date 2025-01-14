#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>

#define LARGURA 80
#define ALTURA 40
#define BARRA_LARGURA 10
#define BARRA_Y (ALTURA - 2)
#define NUM_BLOCOS 60
#define ATRASO_TIQUE 50
#define MAX_CORACOES 3 
#define MAX_BLOCOS 100

typedef struct {
    int x, y;
    int dx, dy;
    WORD cor;
} Bola;

typedef struct {
    int x, y;
    int ativo;
} Bloco;

int pontuacao = 0;
int coracoes = MAX_CORACOES; 
int num_blocos = NUM_BLOCOS;
int nivel_atual = 1;
Bloco blocos[MAX_BLOCOS];

Bola bola;
HANDLE console;
int barraX = (LARGURA - BARRA_LARGURA) / 2;

CHAR_INFO bufferConsole[LARGURA * ALTURA];
COORD tamanhoBuffer = {LARGURA, ALTURA};
COORD posicaoEscrita = {0, 0};  
SMALL_RECT areaEscritaConsole = {0, 0, LARGURA - 1, ALTURA - 1};

void definir_cor(int x, int y, wchar_t caractere, WORD cor) {
    bufferConsole[y * LARGURA + x].Char.UnicodeChar = caractere;
    bufferConsole[y * LARGURA + x].Attributes = cor;
}

void desenhar_borda();

void desenhar_tela_inicial() {
    for (int i = 0; i < LARGURA * ALTURA; i++) {
        definir_cor(i % LARGURA, i / LARGURA, L' ', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }

    desenhar_borda();

    wchar_t *titulo = L"BRICK BREAK";
    int centroX = (LARGURA - wcslen(titulo)) / 2;
    for (int i = 0; i < wcslen(titulo); i++) {
        definir_cor(centroX + i, ALTURA / 4, titulo[i], FOREGROUND_GREEN | FOREGROUND_RED);
    }

    wchar_t *instrucoes = L"PRESSIONE ENTER para começar";
    centroX = (LARGURA - wcslen(instrucoes)) / 2;
    for (int i = 0; i < wcslen(instrucoes); i++) {
        definir_cor(centroX + i, ALTURA / 2, instrucoes[i], FOREGROUND_BLUE);
    }
    WriteConsoleOutputW(console, bufferConsole, tamanhoBuffer, posicaoEscrita, &areaEscritaConsole);
}

void mostrar_fase(int fase) {
    for (int i = 0; i < LARGURA * ALTURA; i++) {
        definir_cor(i % LARGURA, i / LARGURA, L' ', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }
    
    desenhar_borda();

    wchar_t fase_texto[20];
    swprintf(fase_texto, 20, L"Nível %d", fase);
    int centroX = (LARGURA - wcslen(fase_texto)) / 2;  
    for (int i = 0; i < wcslen(fase_texto); i++) { 
        definir_cor(centroX + i, ALTURA / 2, fase_texto[i], FOREGROUND_BLUE);
    }

    WriteConsoleOutputW(console, bufferConsole, tamanhoBuffer, posicaoEscrita, &areaEscritaConsole);

    Sleep(3000);
}

void reiniciar_jogo() {
    bola.x = LARGURA / 2;
    bola.y = ALTURA / 2;
    bola.dx = (rand() % 2 == 0) ? 1 : -1;
    bola.dy = -1;
    bola.cor = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;

    num_blocos = NUM_BLOCOS + (nivel_atual - 1) * 10;

    for (int i = 0; i < NUM_BLOCOS; i++) {
        blocos[i].x = (i % (LARGURA / 10)) * 10 + 1;
        blocos[i].y = (i / (LARGURA / 10)) + 10;
        blocos[i].ativo = 1;
    }
}

void atualizar_blocos() {
    if (num_blocos < MAX_BLOCOS) {
        int novos_blocos = 10;
        for (int i = num_blocos; i < num_blocos + novos_blocos && i < MAX_BLOCOS; i++) {
            blocos[i].x = (i % (LARGURA / 10)) * 10 + 1;
            blocos[i].y = (i / (LARGURA / 10)) + 10;
            blocos[i].ativo = 1;
        }
        num_blocos += novos_blocos;
    }
}

void aumentar_dificuldade() {
    if (pontuacao % 30 == 0) {
        atualizar_blocos();
    }
}

void desenhar_borda() {
    for (int x = 0; x < LARGURA; x++) {
        definir_cor(x, 0, L'#', FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        definir_cor(x, ALTURA - 1, L'#', FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    }

    for (int y = 1; y < ALTURA - 1; y++) {
        definir_cor(0, y, L'#', FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        definir_cor(LARGURA - 1, y, L'#', FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    }
}

void game_over() {
    wchar_t *msg = L"GAME OVER! Pressione Enter";
    int centroX = (LARGURA - wcslen(msg)) / 2;

    for (int i = 0; i < LARGURA * ALTURA; i++) {
        definir_cor(i % LARGURA, i / LARGURA, L' ', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }

    desenhar_borda();

    for (int i = 0; i < wcslen(msg); i++) {
        definir_cor(centroX + i, ALTURA / 2, msg[i], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    WriteConsoleOutputW(console, bufferConsole, tamanhoBuffer, posicaoEscrita, &areaEscritaConsole);

    while (!GetAsyncKeyState(VK_RETURN)) {
        Sleep(100);
    }

    Sleep(500);
    desenhar_tela_inicial();
}


void desenhar_corações() {
    for (int i = 0; i < MAX_CORACOES; i++) {
        if (i < coracoes) {
            definir_cor(65 + i, 1, L'♥', FOREGROUND_RED);
        } else {
            definir_cor(65 + i, 1, L' ', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
        }
    }
}

void desenhar_tela() {
    for (int i = 0; i < LARGURA * ALTURA; ++i) {
        definir_cor(i % LARGURA, i / LARGURA, L' ', FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    }

    desenhar_borda();
    definir_cor(bola.x, bola.y, L'O', bola.cor);

    for (int i = 0; i < BARRA_LARGURA; ++i) {
        definir_cor(barraX + i, BARRA_Y, L'=', FOREGROUND_BLUE | FOREGROUND_GREEN);
    }

    for (int i = 0; i < num_blocos; i++) {
        if (blocos[i].ativo) {
            for (int h = 0; h < 2; h++) {
                for (int w = 0; w < 8; w++) {
                    definir_cor(blocos[i].x + w, blocos[i].y + h, L'■', FOREGROUND_RED | FOREGROUND_GREEN);
                }
            }
        }
    }

    wchar_t placar[20];
    swprintf(placar, 20, L"Placar: %d", pontuacao);
    int placarPosX = 83; // Posição do placar
    for (int i = 0; i < wcslen(placar); i++) {
        definir_cor(placarPosX + i, 1, placar[i], FOREGROUND_BLUE);
    }

    desenhar_corações();
    WriteConsoleOutputW(console, bufferConsole, tamanhoBuffer, posicaoEscrita, &areaEscritaConsole);
}

void atualizar_posicao_bola() {
    bola.x += bola.dx;
    bola.y += bola.dy;

    if (bola.x <= 1 || bola.x >= LARGURA - 2) {
        bola.dx *= -1;
    }

    if (bola.y <= 1) {
        bola.dy *= -1;
    }

    // Colisão com a barra
    if (bola.y == BARRA_Y - 1 && bola.x >= barraX && bola.x < barraX + BARRA_LARGURA) {
        bola.dy *= -1;
    }

    // Colisão com blocos
    for (int i = 0; i < num_blocos; i++) {
        if (blocos[i].ativo && bola.y >= blocos[i].y && bola.y < blocos[i].y + 2 && 
            bola.x >= blocos[i].x && bola.x < blocos[i].x + 8) {
            // Verificar se a colisão foi pela parte superior ou inferior do bloco
            if (bola.y < blocos[i].y + 1) { // Parte superior
                bola.dy = -1;
            } else { // Parte inferior
                bola.dy = 1;
            }
            blocos[i].ativo = 0; // Desativar o bloco
            pontuacao++;
            aumentar_dificuldade();
            break; // Sair do loop para evitar múltiplas quebras
        }
    }
    
    int todos_bloqueados = 1;
    for (int i = 0; i < NUM_BLOCOS; i++) {
        if (blocos[i].ativo){
            todos_bloqueados = 0;
            break;
        }
    }
    
    if (todos_bloqueados){
        nivel_atual++;
        pontuacao = 0;
        mostrar_fase(nivel_atual);
        reiniciar_jogo();
    }

    // Derrota
    if (bola.y >= ALTURA) {
        coracoes--;
        if (coracoes <= 0) {
            game_over();
            coracoes = MAX_CORACOES; // Resetar corações
        }
        pontuacao = 0;
        reiniciar_jogo();
    }
}

void mover_barra(int direcao) {
    int velocidadeBarra = 2; 
    barraX += direcao * velocidadeBarra;
    if (barraX < 1) barraX = 1; 
    if (barraX > LARGURA - BARRA_LARGURA - 1) barraX = LARGURA - BARRA_LARGURA - 1;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    console = GetStdHandle(STD_OUTPUT_HANDLE);
  
    desenhar_tela_inicial();

    while (!GetAsyncKeyState(VK_RETURN)) {
        Sleep(100);
    }

    int fase_atual = 1; 
    mostrar_fase(fase_atual);

    reiniciar_jogo();
   
    while (1) {
        if (GetAsyncKeyState(VK_LEFT)) mover_barra(-1);
        if (GetAsyncKeyState(VK_RIGHT)) mover_barra(1);

        atualizar_posicao_bola();
        desenhar_tela();
        Sleep(ATRASO_TIQUE);
    }

    return 0;
}