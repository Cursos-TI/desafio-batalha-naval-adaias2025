#include <stdio.h>

#define TAM 10        // Tamanho fixo do tabuleiro (10x10)
#define NAVIO 3       // Valor que representa navio
#define HABILIDADE 5  // Valor que representa área de habilidade
#define TAM_HAB 5     // Tamanho fixo das matrizes de habilidade (5x5)

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tab[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro formatado
void exibirTabuleiro(int tab[TAM][TAM]) {
    printf("\n🌊 TABULEIRO DE BATALHA NAVAL 🌊\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tab[i][j] == 0)
                printf("~ ");   // Água
            else if (tab[i][j] == NAVIO)
                printf("⛵ ");   // Navio
            else if (tab[i][j] == HABILIDADE)
                printf("🔥 ");   // Área de habilidade
            else
                printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio simples horizontal (para manter consistência com níveis anteriores)
void posicionarNavioHorizontal(int tab[TAM][TAM], int linha, int coluna) {
    if (coluna + 3 <= TAM) {
        for (int j = 0; j < 3; j++) {
            tab[linha][coluna + j] = NAVIO;
        }
    }
}

// Função para criar matriz de habilidade em formato de CONE
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Padrão de cone (expandindo para baixo)
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i) && i <= TAM_HAB / 2)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade em formato de CRUZ
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cruz = linha e coluna central
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade em formato de OCTAEDRO (losango)
void criarOctaedro(int octa[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Distância de Manhattan até o centro
            int dist = abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2);
            if (dist <= TAM_HAB / 2)
                octa[i][j] = 1;
            else
                octa[i][j] = 0;
        }
    }
}

// Função para aplicar a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tab[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                // Garantir que não ultrapasse o tabuleiro
                if (linhaTab >= 0 && linhaTab < TAM && colunaTab >= 0 && colunaTab < TAM) {
                    // Não sobrescrever navio, apenas água
                    if (tab[linhaTab][colunaTab] == 0)
                        tab[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posicionar um navio horizontal (exemplo fixo)
    posicionarNavioHorizontal(tabuleiro, 4, 3);

    // Criar matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octa[TAM_HAB][TAM_HAB];

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octa);

    // Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);   // Cone no topo esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);   // Cruz no centro
    aplicarHabilidade(tabuleiro, octa, 7, 7);   // Octaedro na parte inferior

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}