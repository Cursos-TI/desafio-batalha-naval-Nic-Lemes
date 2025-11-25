#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro
#define NAVIO 3    // Tamanho dos navios

// ---------------------------------------------------
// Verifica se navio cabe no tabuleiro
// orientacao:
// 0 = horizontal
// 1 = vertical
// 2 = diagonal principal (linha++ / coluna++)
// 3 = diagonal secundaria (linha++ / coluna--)
// ---------------------------------------------------
int cabe(int linha, int coluna, int orientacao) {
    switch (orientacao) {
        case 0:  // horizontal
            return (coluna + NAVIO <= TAM);
        case 1:  // vertical
            return (linha + NAVIO <= TAM);
        case 2:  // diagonal principal
            return (linha + NAVIO <= TAM && coluna + NAVIO <= TAM);
        case 3:  // diagonal secundária
            return (linha + NAVIO <= TAM && coluna - (NAVIO - 1) >= 0);
    }
    return 0;
}

// ---------------------------------------------------
// Verifica sobreposição com outros navios
// ---------------------------------------------------
int sobrepoe(int tab[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        switch (orientacao) {
            case 0: // horizontal
                if (tab[linha][coluna + i] != 0) return 1;
                break;
            case 1: // vertical
                if (tab[linha + i][coluna] != 0) return 1;
                break;
            case 2: // diagonal principal
                if (tab[linha + i][coluna + i] != 0) return 1;
                break;
            case 3: // diagonal secundária
                if (tab[linha + i][coluna - i] != 0) return 1;
                break;
        }
    }
    return 0;
}

// ---------------------------------------------------
// Posiciona navio no tabuleiro
// ---------------------------------------------------
void posicionar(int tab[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        switch (orientacao) {
            case 0: tab[linha][coluna + i] = 3; break;          // horizontal
            case 1: tab[linha + i][coluna] = 3; break;          // vertical
            case 2: tab[linha + i][coluna + i] = 3; break;      // diagonal principal
            case 3: tab[linha + i][coluna - i] = 3; break;      // diagonal secundária
        }
    }
}

// ---------------------------------------------------
// PROGRAMA PRINCIPAL
// ---------------------------------------------------
int main() {

    // Criar tabuleiro 10x10 e inicializar com 0
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // Definir 4 navios (posições escolhidas)

    // Navio 1 – Horizontal
    int l1 = 2, c1 = 1, o1 = 0;

    // Navio 2 – Vertical
    int l2 = 5, c2 = 7, o2 = 1;

    // Navio 3 – Diagonal principal
    int l3 = 0, c3 = 0, o3 = 2;

    // Navio 4 – Diagonal secundária
    int l4 = 1, c4 = 8, o4 = 3;

    // Validar e posicionar cada navio
    if (cabe(l1, c1, o1) && !sobrepoe(tabuleiro, l1, c1, o1))
        posicionar(tabuleiro, l1, c1, o1);

    if (cabe(l2, c2, o2) && !sobrepoe(tabuleiro, l2, c2, o2))
        posicionar(tabuleiro, l2, c2, o2);

    if (cabe(l3, c3, o3) && !sobrepoe(tabuleiro, l3, c3, o3))
        posicionar(tabuleiro, l3, c3, o3);

    if (cabe(l4, c4, o4) && !sobrepoe(tabuleiro, l4, c4, o4))
        posicionar(tabuleiro, l4, c4, o4);

    // Exibir tabuleiro 10x10
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
