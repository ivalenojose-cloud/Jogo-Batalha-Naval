#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função auxiliar para verificar se uma posição está livre
int posicao_valida(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    return (linha >= 0 && linha < TAM_TABULEIRO &&
            coluna >= 0 && coluna < TAM_TABULEIRO &&
            tabuleiro[linha][coluna] == 0);
}

// Função para posicionar navio horizontal
void posiciona_horizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicao_valida(tabuleiro, linha, coluna + i)) {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

// Função para posicionar navio vertical
void posiciona_vertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicao_valida(tabuleiro, linha + i, coluna)) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para posicionar navio diagonal (↘)
void posiciona_diagonal_principal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicao_valida(tabuleiro, linha + i, coluna + i)) {
            tabuleiro[linha + i][coluna + i] = 3;
        }
    }
}

// Função para posicionar navio diagonal (↙)
void posiciona_diagonal_secundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (posicao_valida(tabuleiro, linha + i, coluna - i)) {
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona os quatro navios
    posiciona_horizontal(tabuleiro, 1, 2);   // Linha 2, coluna C
    posiciona_vertical(tabuleiro, 4, 6);     // Linha 5, coluna G
    posiciona_diagonal_principal(tabuleiro, 0, 0); // Diagonal principal a partir de (1,1)
    posiciona_diagonal_secundaria(tabuleiro, 2, 8); // Diagonal secundária a partir de (3,J)

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
