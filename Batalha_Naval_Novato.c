#include <stdio.h>

#define TABULEIRO 10
#define NAVIO 3

int main() {
    int tabuleiro[TABULEIRO][TABULEIRO] = {0};

    // Coordenadas iniciais do Navio
    int linha1 = 2, coluna1 = 4; // navio horizontal
    int linha2 = 5, coluna2 = 1; // navio vertical

    // Vetores representando os navios 
    int navioHorizontal[NAVIO] = {3, 3, 3};
    int navioVertical[NAVIO]   = {3, 3, 3};

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

    // Fazendo a verificação da sobreposição
    for (int i = 0; i < NAVIO; i++) {
        if (tabuleiro[linha1][coluna1 + i] == 3) {
            printf("Erro: Navio horizontal sobrepoe outro navio.\n");
            return 1;
        }
        if (tabuleiro[linha2 + i][coluna2] == 3) {
            printf("Erro: Navio vertical sobrepoe outro navio.\n");
            return 1;
        }
    }

    // POS navio horinzontal
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha1][coluna1 + i] = navioHorizontal[i];
    }

    // POS navio vertical
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linha2 + i][coluna2] = navioVertical[i];
    }

    // TABULEIRO
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TABULEIRO; i++) {
        for (int j = 0; j < TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
