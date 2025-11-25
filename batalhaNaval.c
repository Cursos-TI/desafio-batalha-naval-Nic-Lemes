#include <stdio.h>

int main() {

    // -----------------------------
    // 1. Criar tabuleiro 10x10 com água (0)
    // -----------------------------
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},   // linha 0
        {0,0,0,0,0,0,0,0,0,0},   // linha 1
        {0,0,0,0,0,0,0,0,0,0},   // linha 2
        {0,0,0,0,0,0,0,0,0,0},   // linha 3
        {0,0,0,0,0,0,0,0,0,0},   // linha 4
        {0,0,0,0,0,0,0,0,0,0},   // linha 5
        {0,0,0,0,0,0,0,0,0,0},   // linha 6
        {0,0,0,0,0,0,0,0,0,0},   // linha 7
        {0,0,0,0,0,0,0,0,0,0},   // linha 8
        {0,0,0,0,0,0,0,0,0,0}    // linha 9
    };

    // -----------------------------
    // 2. Criar navio horizontal (tamanho 3)
    // -----------------------------
    int navioH[3] = {3,3,3};

    // Posição inicial do navio horizontal
    int hLinha = 2;
    int hColuna = 1;

    tabuleiro[hLinha][hColuna]     = navioH[0];
    tabuleiro[hLinha][hColuna + 1] = navioH[1];
    tabuleiro[hLinha][hColuna + 2] = navioH[2];

    // -----------------------------
    // 3. Criar navio vertical (tamanho 3)
    // -----------------------------
    int navioV[3] = {3,3,3};

    // Posição inicial do navio vertical
    int vLinha = 5;
    int vColuna = 7;

    tabuleiro[vLinha][vColuna]     = navioV[0];
    tabuleiro[vLinha + 1][vColuna] = navioV[1];
    tabuleiro[vLinha + 2][vColuna] = navioV[2];

    // -----------------------------
    // 4. Exibir tabuleiro SEM FOR
    // -----------------------------
    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4],
           tabuleiro[0][5], tabuleiro[0][6], tabuleiro[0][7], tabuleiro[0][8], tabuleiro[0][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[1][3], tabuleiro[1][4],
           tabuleiro[1][5], tabuleiro[1][6], tabuleiro[1][7], tabuleiro[1][8], tabuleiro[1][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3], tabuleiro[2][4],
           tabuleiro[2][5], tabuleiro[2][6], tabuleiro[2][7], tabuleiro[2][8], tabuleiro[2][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[3][0], tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3], tabuleiro[3][4],
           tabuleiro[3][5], tabuleiro[3][6], tabuleiro[3][7], tabuleiro[3][8], tabuleiro[3][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[4][0], tabuleiro[4][1], tabuleiro[4][2], tabuleiro[4][3], tabuleiro[4][4],
           tabuleiro[4][5], tabuleiro[4][6], tabuleiro[4][7], tabuleiro[4][8], tabuleiro[4][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[5][0], tabuleiro[5][1], tabuleiro[5][2], tabuleiro[5][3], tabuleiro[5][4],
           tabuleiro[5][5], tabuleiro[5][6], tabuleiro[5][7], tabuleiro[5][8], tabuleiro[5][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[6][0], tabuleiro[6][1], tabuleiro[6][2], tabuleiro[6][3], tabuleiro[6][4],
           tabuleiro[6][5], tabuleiro[6][6], tabuleiro[6][7], tabuleiro[6][8], tabuleiro[6][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[7][0], tabuleiro[7][1], tabuleiro[7][2], tabuleiro[7][3], tabuleiro[7][4],
           tabuleiro[7][5], tabuleiro[7][6], tabuleiro[7][7], tabuleiro[7][8], tabuleiro[7][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[8][0], tabuleiro[8][1], tabuleiro[8][2], tabuleiro[8][3], tabuleiro[8][4],
           tabuleiro[8][5], tabuleiro[8][6], tabuleiro[8][7], tabuleiro[8][8], tabuleiro[8][9]);

    printf("%d %d %d %d %d %d %d %d %d %d\n",
           tabuleiro[9][0], tabuleiro[9][1], tabuleiro[9][2], tabuleiro[9][3], tabuleiro[9][4],
           tabuleiro[9][5], tabuleiro[9][6], tabuleiro[9][7], tabuleiro[9][8], tabuleiro[9][9]);

    return 0;
}
