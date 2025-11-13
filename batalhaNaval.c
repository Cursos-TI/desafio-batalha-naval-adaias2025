#include <stdio.h>

#define TAM 10          // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3         // Valor que representa parte do navio
#define TAM_NAVIO 3     // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Criar quatro navios de tamanho 3
    // (Dois normais e dois diagonais)
    int navio1[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Horizontal
    int navio2[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Vertical
    int navio3[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Diagonal ↘
    int navio4[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO}; // Diagonal ↙

    // 3️⃣ Definir coordenadas iniciais (linha, coluna)
    int linhaH = 1, colunaH = 2; // Navio 1 - horizontal
    int linhaV = 5, colunaV = 6; // Navio 2 - vertical
    int linhaD1 = 0, colunaD1 = 0; // Navio 3 - diagonal principal ↘
    int linhaD2 = 2, colunaD2 = 9; // Navio 4 - diagonal secundária ↙

    int sobrepoe = 0; // Flag para sobreposição

    // 🟦 Navio 1: Horizontal
    if (colunaH + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            if (tabuleiro[linhaH][colunaH + j] != 0)
                sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (j = 0; j < TAM_NAVIO; j++)
                tabuleiro[linhaH][colunaH + j] = navio1[j];
        } else {
            printf("❌ Erro: Sobreposição no navio horizontal!\n");
            return 1;
        }
    } else {
        printf("❌ Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    sobrepoe = 0; // resetar flag

    // 🟦 Navio 2: Vertical
    if (linhaV + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0)
                sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaV + i][colunaV] = navio2[i];
        } else {
            printf("❌ Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    } else {
        printf("❌ Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    sobrepoe = 0; // resetar flag

    // 🟦 Navio 3: Diagonal principal ↘ (linha e coluna aumentam)
    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
                sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = navio3[i];
        } else {
            printf("❌ Erro: Sobreposição no navio diagonal ↘!\n");
            return 1;
        }
    } else {
        printf("❌ Erro: Navio diagonal ↘ fora dos limites!\n");
        return 1;
    }

    sobrepoe = 0; // resetar flag

    // 🟦 Navio 4: Diagonal secundária ↙ (linha aumenta e coluna diminui)
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
                sobrepoe = 1;
        }
        if (!sobrepoe) {
            for (i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD2 + i][colunaD2 - i] = navio4[i];
        } else {
            printf("❌ Erro: Sobreposição no navio diagonal ↙!\n");
            return 1;
        }
    } else {
        printf("❌ Erro: Navio diagonal ↙ fora dos limites!\n");
        return 1;
    }

    // 6️⃣ Exibir o tabuleiro completo
    printf("\n🟦 TABULEIRO DE BATALHA NAVAL 🟦\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}