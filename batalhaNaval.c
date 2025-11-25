#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro (10x10)
#define NAVIO 3    // Tamanho dos navios (3 posições)

// -------------------------------------------
// Função auxiliar para verificar se o navio cabe
// -------------------------------------------
int cabeNoTabuleiro(int linha, int coluna, int orientacao) {
    if (orientacao == 0) {  // 0 = horizontal
        return (coluna + NAVIO <= TAM);
    } else {                // 1 = vertical
        return (linha + NAVIO <= TAM);
    }
}

// -------------------------------------------
// Função auxiliar para verificar sobreposição
// -------------------------------------------
int sobrepoe(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 0) { // horizontal
            if (tabuleiro[linha][coluna + i] != 0)
                return 1; // sobrepôs
        } else { // vertical
            if (tabuleiro[linha + i][coluna] != 0)
                return 1; // sobrepôs
        }
    }
    return 0;
}

// -------------------------------------------
// Função para posicionar um navio
// -------------------------------------------
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        if (orientacao == 0) {
            tabuleiro[linha][coluna + i] = 3;
        } else {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// -------------------------------------------
// Programa principal
// -------------------------------------------
int main() {
    int tabuleiro[TAM][TAM];

    // Inicializando o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------------
    // Definição das coordenadas
    // -------------------------------
    int linhaH = 2, colunaH = 1;  // Navio horizontal
    int linhaV = 5, colunaV = 7;  // Navio vertical

    // -------------------------------
    // Validações para o navio horizontal
    // -------------------------------
    if (!cabeNoTabuleiro(linhaH, colunaH, 0)) {
        printf("Erro: navio horizontal nao cabe no tabuleiro!\n");
        return 1;
    }
    if (sobrepoe(tabuleiro, linhaH, colunaH, 0)) {
        printf("Erro: navio horizontal sobrepoe outro navio!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, linhaH, colunaH, 0);

    // -------------------------------
    // Validações para o navio vertical
    // -------------------------------
    if (!cabeNoTabuleiro(linhaV, colunaV, 1)) {
        printf("Erro: navio vertical nao cabe no tabuleiro!\n");
        return 1;
    }
    if (sobrepoe(tabuleiro, linhaV, colunaV, 1)) {
        printf("Erro: navio vertical sobrepoe outro navio!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, linhaV, colunaV, 1);

    // -------------------------------
    // Exibir Tabuleiro
    // -------------------------------
    printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
