#include <stdio.h>

#define TAM 10       // Tabuleiro 10x10
#define NAVIO 3      // Tamanho dos navios
#define HAB 5        // Matrizes das habilidades: 5x5
#define AFETADO 5    // Valor para área de efeito

// ===============================================================
// Funções auxiliares para posicionar navios (nível anterior)
// ===============================================================
int cabe(int linha, int coluna, int orientacao) {
    switch (orientacao) {
        case 0: return (coluna + NAVIO <= TAM);                 // horizontal
        case 1: return (linha + NAVIO <= TAM);                  // vertical
        case 2: return (linha + NAVIO <= TAM && coluna + NAVIO <= TAM); // diagonal principal
        case 3: return (linha + NAVIO <= TAM && coluna - (NAVIO - 1) >= 0); // diagonal secundária
    }
    return 0;
}

int sobrepoe(int tab[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        switch (orientacao) {
            case 0: if (tab[linha][coluna + i] != 0) return 1; break;
            case 1: if (tab[linha + i][coluna] != 0) return 1; break;
            case 2: if (tab[linha + i][coluna + i] != 0) return 1; break;
            case 3: if (tab[linha + i][coluna - i] != 0) return 1; break;
        }
    }
    return 0;
}

void posicionar(int tab[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int i = 0; i < NAVIO; i++) {
        switch (orientacao) {
            case 0: tab[linha][coluna + i] = 3; break;
            case 1: tab[linha + i][coluna] = 3; break;
            case 2: tab[linha + i][coluna + i] = 3; break;
            case 3: tab[linha + i][coluna - i] = 3; break;
        }
    }
}

// ===============================================================
// Criar MATRIZ de habilidade: CONE (5x5)
// ===============================================================
void criarHabilidadeCone(int cone[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            // Linha 0: só o centro
            // Linha 1: três posições
            // Linha 2: cinco posições (expandindo)
            if (i == 0 && j == 2) cone[i][j] = 1;
            else if (i == 1 && (j >= 1 && j <= 3)) cone[i][j] = 1;
            else if (i == 2) cone[i][j] = 1;
            else cone[i][j] = 0;
        }
    }
}

// ===============================================================
// Criar MATRIZ de habilidade: CRUZ (5x5)
// ===============================================================
void criarHabilidadeCruz(int cruz[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == centro || j == centro) cruz[i][j] = 1;
            else cruz[i][j] = 0;
        }
    }
}

// ===============================================================
// Criar MATRIZ de habilidade: OCTAEDRO / LOSANGO (5x5)
// ===============================================================
void criarHabilidadeOctaedro(int oct[HAB][HAB]) {
    int centro = HAB / 2;
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            // Fórmula do losango: |i - centro| + |j - centro| <= raio
            if (abs(i - centro) + abs(j - centro) <= 2)
                oct[i][j] = 1;
            else
                oct[i][j] = 0;
        }
    }
}

// ===============================================================
// Sobrepor habilidade no tabuleiro
// ===============================================================
void aplicarHabilidade(int tab[TAM][TAM], int hab[HAB][HAB], int origemL, int origemC) {
    int raio = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {

            if (hab[i][j] == 1) {  
                // Converter coordenadas da habilidade para o tabuleiro
                int linha = origemL + (i - raio);
                int coluna = origemC + (j - raio);

                // Validar limites
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    // Não sobrescreve navio (valor 3)
                    if (tab[linha][coluna] == 0)
                        tab[linha][coluna] = AFETADO;
                }
            }
        }
    }
}

// ===============================================================
// PROGRAMA PRINCIPAL
// ===============================================================
int main() {

    // -----------------------------------------------------------
    // 1. Criar tabuleiro 10x10
    // -----------------------------------------------------------
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    // -----------------------------------------------------------
    // 2. Posicionar 4 navios do desafio anterior
    // -----------------------------------------------------------
    int navios[4][3] = {
        {2, 1, 0},  // linha, coluna, orientacao (horizontal)
        {5, 7, 1},  // vertical
        {0, 0, 2},  // diagonal principal
        {1, 8, 3}   // diagonal secundária
    };

    for (int i = 0; i < 4; i++) {
        int l = navios[i][0];
        int c = navios[i][1];
        int o = navios[i][2];

        if (cabe(l, c, o) && !sobrepoe(tabuleiro, l, c, o))
            posicionar(tabuleiro, l, c, o);
    }

    // -----------------------------------------------------------
    // 3. Criar as matrizes de habilidades (cone, cruz e octaedro)
    // -----------------------------------------------------------
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // -----------------------------------------------------------
    // 4. Definir posições das habilidades no tabuleiro
    // -----------------------------------------------------------
    int origemConeL = 5, origemConeC = 3;
    int origemCruzL = 2, origemCruzC = 5;
    int origemOctL  = 7, origemOctC  = 5;

    // -----------------------------------------------------------
    // 5. Aplicar cada habilidade no tabuleiro
    // -----------------------------------------------------------
    aplicarHabilidade(tabuleiro, cone, origemConeL, origemConeC);
    aplicarHabilidade(tabuleiro, cruz, origemCruzL, origemCruzC);
    aplicarHabilidade(tabuleiro, octaedro, origemOctL, origemOctC);

    // -----------------------------------------------------------
    // 6. Exibir tabuleiro final
    // -----------------------------------------------------------
    printf("\n======= TABULEIRO FINAL – HABILIDADES =======\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
