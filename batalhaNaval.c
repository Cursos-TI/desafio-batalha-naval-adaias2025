#include <stdio.h>

#define TAM 10   // Tamanho fixo do tabuleiro
#define NAVIO 3  // Valor que representa uma parte do navio
#define TAM_NAVIO 3 // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // 1️⃣ Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2️⃣ Declarar navios (valores representativos)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    // 3️⃣ Definir coordenadas iniciais (linha, coluna)
    int linhaH = 2, colunaH = 4; // Navio horizontal começa na posição (2,4)
    int linhaV = 5, colunaV = 6; // Navio vertical começa na posição (5,6)

    // 4️⃣ Verificar se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO <= TAM) {
        // Posicionar navio horizontal
        for (j = 0; j < TAM_NAVIO; j++) {
            // Garantir que não sobreponha outro navio
            if (tabuleiro[linhaH][colunaH + j] == 0) {
                tabuleiro[linhaH][colunaH + j] = navioHorizontal[j];
            }
        }
    } else {
        printf("❌ Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    // 5️⃣ Verificar se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO <= TAM) {
        // Verificar se não há sobreposição
        int sobrepoe = 0;
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobrepoe = 1;
                break;
            }
        }

        if (!sobrepoe) {
            // Posicionar navio vertical
            for (i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        } else {
            printf("❌ Erro: Navios se sobrepõem!\n");
            return 1;
        }
    } else {
        printf("❌ Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // 6️⃣ Exibir o tabuleiro formatado
    printf("\n🟦 TABULEIRO DE BATALHA NAVAL 🟦\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}