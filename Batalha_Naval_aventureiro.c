#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3

int main() {
    int tabuleiro[TABULEIRO][TABULEIRO] = {0};

    // Coordenadas iniciais dos Navios
    int linha1 = 2, coluna1 = 4; // navio horizontal
    int linha2 = 5, coluna2 = 1; // navio vertical

    int linha3 = 1, coluna3 = 1; // navio diagonal principal 
    int linha4 = 8, coluna4 = 2; // navio diagonal invertida 

    // Vetores representando os navios 
    int navioHorizontal[NAVIO] = {3, 3, 3};
    int navioVertical[NAVIO]   = {3, 3, 3};
    int navioDiag1[NAVIO]      = {3, 3, 3};
    int navioDiag2[NAVIO]      = {3, 3, 3};

    // =======================================
    //      VALIDAÇÃO DE LIMITES DOS NAVIOS
    // =======================================
    // NAVIO HORIZONTAL 
    if (coluna1 + NAVIO > TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // NAVIO VERTICAL
    if (linha2 + NAVIO > TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // NAVIO DIAGONAL  (i++, j++)
    if (linha3 + NAVIO > TABULEIRO || coluna3 + NAVIO > TABULEIRO) {
        printf("Erro: Navio diagonal principal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // NAVIO DIAGONAL  (i--, j++)
    if (linha4 - (NAVIO - 1) < 0 || coluna4 + NAVIO > TABULEIRO) {
        printf("Erro: Navio diagonal invertida ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // ===========================================
    //      VERIFICAÇÃO DE SOBREPOSIÇÃO
    // ===========================================

    for (int i = 0; i < NAVIO; i++) {

        // horizontal
        if (tabuleiro[linha1][coluna1 + i] == 3) {
            printf("Erro: Navio horizontal sobrepoe outro navio.\n");
            return 1;
        }

        // vertical
        if (tabuleiro[linha2 + i][coluna2] == 3) {
            printf("Erro: Navio vertical sobrepoe outro navio.\n");
            return 1;
        }

        // diagonal 
        if (tabuleiro[linha3 + i][coluna3 + i] == 3) {
            printf("Erro: Navio diagonal principal sobrepoe outro navio.\n");
            return 1;
        }

        // diagonal 
        if (tabuleiro[linha4 - i][coluna4 + i] == 3) {
            printf("Erro: Navio diagonal invertida sobrepoe outro navio.\n");
            return 1;
        }
    }

    // =========================================
    //      POSICIONAMENTO DOS NAVIOS
    // =========================================

    // POS navio horizontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha1][coluna1 + i] = navioHorizontal[i];
    }

    // POS navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha2 + i][coluna2] = navioVertical[i];
    }

    // POS navio diagonal 
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha3 + i][coluna3 + i] = navioDiag1[i];
    }

    // POS navio diagonal 
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha4 - i][coluna4 + i] = navioDiag2[i];
    }

    // ===========================================
    //      EXIBIÇÃO DO TABULEIRO
    // ============================================

    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
