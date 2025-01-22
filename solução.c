#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000
#define POS_MAXIMO 7
#define POS_MINIMO 0

int MovimentosEm_X[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int MovimentosEm_Y[8] = {2, 2, 1, -1, -2, -2, -1, 1};

int validaMovimento(int x, int y);
int dijkstra(int cx, int cy, int dx, int dy);
void inicializaMatrizes(int matriz1[8][8], int matriz2[8][8]);
void relaxamento(int MatrizDePosicao[8][8], int X_atual, int Y_atual);

int main() {
    
    int count = 0;

    while(count < 64*64){ 
    char Posicao_inicial[3];
    char Destino[3];
    int input_xCavalo = 0;
    int input_yCavalo = 0;
    int input_xDestino = 0;
    int input_yDestino = 0;
    int Resposta = 0;

    scanf("%s", Posicao_inicial);
    scanf("%s", Destino);

    input_xCavalo = Posicao_inicial[0] - 'a';  // Converte a letra para coordenada X
    input_yCavalo = Posicao_inicial[1] - '1';  // Converte o número para coordenada Y
    input_xDestino = Destino[0] - 'a';
    input_yDestino = Destino[1] - '1';

    Resposta = dijkstra(input_xCavalo, input_yCavalo, input_xDestino, input_yDestino);
    printf("To get from %s to %s takes %d knight moves.\n", Posicao_inicial, Destino, Resposta);
    
       count++;
    } 
}

int validaMovimento(int x, int y) {
    return (x >= POS_MINIMO && x <= POS_MAXIMO && y >= POS_MINIMO && y <= POS_MAXIMO);
}

void inicializaMatrizes(int matriz_Tabuleiro[8][8], int matriz_Visitados[8][8]) {
    for (int x = 0; x <= POS_MAXIMO; x++) {
        for (int y = 0; y <= POS_MAXIMO; y++) {
            matriz_Tabuleiro[x][y] = INFINITO;
            matriz_Visitados[x][y] = 0;
        }
    }
}

void relaxamento(int MatrizDePosicao[8][8], int X_atual, int Y_atual) {
    for (int i = 0; i < 8; i++) {
        int X_movimento = X_atual + MovimentosEm_X[i];
        int Y_movimento = Y_atual + MovimentosEm_Y[i];

        if (validaMovimento(X_movimento, Y_movimento)) {
            if (MatrizDePosicao[X_movimento][Y_movimento] > MatrizDePosicao[X_atual][Y_atual] + 1) {
                MatrizDePosicao[X_movimento][Y_movimento] = MatrizDePosicao[X_atual][Y_atual] + 1;
            }
        }
    }
}

int dijkstra(int cx, int cy, int dx, int dy) {
    int Tabuleiro[8][8], Visitados[8][8];
    inicializaMatrizes(Tabuleiro, Visitados);

    Tabuleiro[cx][cy] = 0;

    while (1) {
        int MenorDistancia = INFINITO;
        int x_atual = -1; 
        int y_atual = -1;

        
        for (int x = 0; x <= POS_MAXIMO; x++) {
            for (int y = 0; y <= POS_MAXIMO; y++) {
                if (Visitados[x][y] == 0 && Tabuleiro[x][y] < MenorDistancia) {
                    MenorDistancia = Tabuleiro[x][y];
                    x_atual = x;
                    y_atual = y;
                }
            }
        }

        if (x_atual == -1 || y_atual == -1) break;  // Sem nós restantes para processar
        if (x_atual == dx && y_atual == dy) 
            return Tabuleiro[dx][dy];

        Visitados[x_atual][y_atual] = 1;
        relaxamento(Tabuleiro, x_atual, y_atual);
    }

    return -1;  // Caminho não encontrado (caso não esperado em tabuleiro de xadrez)
}
