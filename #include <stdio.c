#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 4        // navio representado com 4
#define TAM_HABILIDADE 3   // habilidades compactas

int dentro_tabuleiro(int linha, int coluna) {
    return (linha >= 0 && linha < TAM_TABULEIRO &&
            coluna >= 0 && coluna < TAM_TABULEIRO);
}

// Cone pequeno
void aplica_cone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origem_linha, int origem_coluna) {
    int padrao[2][3] = {
        {0,1,0},
        {1,1,1}
    };
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            if (padrao[i][j]==1) {
                int linha = origem_linha + i;
                int coluna = origem_coluna + j-1;
                if (dentro_tabuleiro(linha,coluna) && tabuleiro[linha][coluna]==0)
                    tabuleiro[linha][coluna] = 1;
            }
        }
    }
}

// Cruz pequena
void aplica_cruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origem_linha, int origem_coluna) {
    int padrao[3][3] = {
        {0,3,0},
        {3,3,3},
        {0,3,0}
    };
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (padrao[i][j]==3) {
                int linha = origem_linha + i-1;
                int coluna = origem_coluna + j-1;
                if (dentro_tabuleiro(linha,coluna) && tabuleiro[linha][coluna]==0)
                    tabuleiro[linha][coluna] = 3;
            }
        }
    }
}

// Octaedro pequeno
void aplica_octaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origem_linha, int origem_coluna) {
    int padrao[3][3] = {
        {0,2,0},
        {2,2,2},
        {0,2,0}
    };
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (padrao[i][j]==2) {
                int linha = origem_linha + i-1;
                int coluna = origem_coluna + j-1;
                if (dentro_tabuleiro(linha,coluna) && tabuleiro[linha][coluna]==0)
                    tabuleiro[linha][coluna] = 2;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa tabuleiro
    for (int i=0; i<TAM_TABULEIRO; i++)
        for (int j=0; j<TAM_TABULEIRO; j++)
            tabuleiro[i][j] = 0;

    // Exemplo: navio
    tabuleiro[1][2] = TAM_NAVIO;
    tabuleiro[1][3] = TAM_NAVIO;
    tabuleiro[1][4] = TAM_NAVIO;

    // Aplica habilidades
    aplica_cone(tabuleiro, 5, 5);     // Cone → 1
    aplica_cruz(tabuleiro, 2, 2);     // Cruz → 3
    aplica_octaedro(tabuleiro, 7, 7); // Octaedro → 2

    // Exibe tabuleiro
    printf("    ");
    for (int j=0; j<TAM_TABULEIRO; j++) printf(" %d ", j);
    printf("\n");

    for (int i=0; i<TAM_TABULEIRO; i++) {
        printf("%2d |", i);
        for (int j=0; j<TAM_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
