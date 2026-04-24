#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios
    // Navio horizontal em linha 2, coluna C (índice 2)
    int linha_horizontal = 1; // linha 2
    int coluna_horizontal = 2; // coluna C

    // Navio vertical em linha 5, coluna G
    int linha_vertical = 4; // linha 5
    int coluna_vertical = 6; // coluna G

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (coluna_horizontal + i < TAM_TABULEIRO &&
            tabuleiro[linha_horizontal][coluna_horizontal + i] == 0) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
        }
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (linha_vertical + i < TAM_TABULEIRO &&
            tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
            tabuleiro[linha_vertical + i][coluna_vertical] = 3;
        }
    }

    // Exibe cabeçalho das colunas (A–J)
    printf("    ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf(" %c ", 'A' + j);
    }
    printf("\n");

    // Exibe o tabuleiro com linhas numeradas (1–10)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d |", i + 1); // número da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
