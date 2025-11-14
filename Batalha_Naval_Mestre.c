#include <stdio.h>
#include <stdlib.h>

#define TABELA 10
#define NAVIO 3
#define THABILIDADE 5   // tamanho das matrizes das habilidades

// =====================================================
//  Função para aplicar habilidade no tabuleiro
// =====================================================
void aplicarHabilidade(int tabuleiro[TABELA][TABELA], int habilidade[THABILIDADE][THABILIDADE], int origemLinha, int origemColuna) {
    int centro = THABILIDADE / 2;

    for (int i = 0; i < THABILIDADE; i++) {
        for (int j = 0; j < THABILIDADE; j++) {
            if (habilidade[i][j] == 1) {

                int linhaTab = origemLinha + (i - centro);
                int colTab   = origemColuna + (j - centro);

                if (linhaTab >= 0 && linhaTab < TABELA &&
                    colTab >= 0 && colTab < TABELA) 
                {
                    if (tabuleiro[linhaTab][colTab] == 0)
                        tabuleiro[linhaTab][colTab] = 5;
                }
            }
        }
    }
}

//  MAIN
int main() {

    int tabuleiro[TABELA][TABELA] = {0};

    // POSICIONAR NAVIOS (2 retos + 2 diagonais)

    tabuleiro[2][1] = NAVIO;
    tabuleiro[2][2] = NAVIO;
    tabuleiro[2][3] = NAVIO;

    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;

    for (int i = 0; i < 3; i++)
        tabuleiro[1+i][1+i] = NAVIO;

    for (int i = 0; i < 3; i++)
        tabuleiro[6+i][3-i] = NAVIO;

    // ==================================
    // MATRIZES DE HABILIDADE
    // ==================================

    int cone[THABILIDADE][THABILIDADE] = {0};
    int cruz[THABILIDADE][THABILIDADE] = {0};
    int octaedro[THABILIDADE][THABILIDADE] = {0};

    // -================= ONE =================
    for (int i = 0; i < THABILIDADE; i++) {
        for (int j = 0; j < THABILIDADE; j++) {
            if (j >= (THABILIDADE/2 - i) && j <= (THABILIDADE/2 + i))
                cone[i][j] = 1;
        }
    }

    // ================ CRUZ =================
    for (int i = 0; i < THABILIDADE; i++) {
        for (int j = 0; j < THABILIDADE; j++) {
            if (i == THABILIDADE/2 || j == THABILIDADE/2)
                cruz[i][j] = 1;
        }
    }

    // ================= OCTAEDRO =================
    for (int i = 0; i < THABILIDADE; i++) {
        for (int j = 0; j < THABILIDADE; j++) {

            int di = abs(i - THABILIDADE/2);
            int dj = abs(j - THABILIDADE/2);

            if (di + dj <= THABILIDADE/2)
                octaedro[i][j] = 1;
        }
    }

    // ==================================
    // APLICAR HABILIDADES AO TABULEIRO
    // ==================================

    int origemConeLinha = 4, origemConeCol = 5;
    int origemCruzLinha = 7, origemCruzCol = 7;
    int origemOctLinha = 5, origemOctCol = 2;

    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeCol);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzCol);
    aplicarHabilidade(tabuleiro, octaedro, origemOctLinha, origemOctCol);

    // =================
    // EXIBIR TABULEIRO
    // =================

    printf("\n=== TABULEIRO FINAL (NAVIOS + HABILIDADES) ===\n\n");

    for (int i = 0; i < TABELA; i++) {
        for (int j = 0; j < TABELA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
