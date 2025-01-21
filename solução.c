#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int INFINITO = 10000000; 
const int POS_MAXIMO = 7;
const int POS_MINIMO = 0;

int MovimentosEm_X[8] = {-1,1,2,2,1,-1,-2,-2};
int MovimentosEm_Y [8]= {2,2,1,-1,-2,-2,-1,1};

int validaMovimento(int x, int y);
int dijkstra(int cx, int cy, int dx, int dy, int posicoesVisitadas[][8]);
void inicializaMatrizes( int matriz1[8][8], int matriz2[8][8]);

int main() {
 
    char Posicao_inicial[3];
    char Destino[3];
    int input_xCavalo = 0;
    int input_yCavalo = 0;
    int input_xDestino = 0;
    int input_yDestino = 0;

    fgets(Posicao_inicial, 3, stdin);
    fgets(Destino, 3, stdin);

    input_yCavalo = Posicao_inicial[1] - 96;  // converte os valores de char
    input_xCavalo = Posicao_inicial[2] - 47;  // para inteiros  
    input_yDestino = Destino[1] - 96;         // com base na tabela ASCII
    input_xDestino = Destino[2] - 47;

    return 0;
}

int validaMovimento(int x, int y){

    return(( x >= 0 && x <= 7 ) && ( y >= 0 && y <= 7 ));

}

void relaxamento(int MatrizDePosicao[][8], int X_atual, int Y_atual,int movimentos)
{
    int X_movimento = 0;
    int Y_movimento = 0;
    
    for(int i = 0; i <= POS_MAXIMO; i++)
    {
        X_movimento = X_atual - MovimentosEm_X[i];
        Y_movimento = Y_atual - MovimentosEm_Y[i];

        if(validaMovimento(X_movimento, Y_movimento) == 1)
        {
            MatrizDePosicao[X_movimento][Y_movimento];
        }
    }
}

void inicializaMatrizes( int matriz_Tabuleiro[8][8], int matriz_Visitados[8][8])
{
    int x = 0;
    int y = 0;

    for(; x <= POS_MAXIMO; x++ ){
        for(; y<= POS_MAXIMO; y++)
        matriz_Tabuleiro[x][y] = INFINITO;
        matriz_Visitados[x][y] = 0;
    }
}

int dijkstra(int cx, int cy, int dx, int dy, int posicoesVisitadas[][8])
{    
    int Tabuleiro[8][8];
    int Visitados[8][8];
    int x = 0;
    int y = 0;
    int PosicaoAtual_X = 0;
    int PosicaoAtual_Y = 0;

    inicializaMatrizes(Tabuleiro, Visitados);

    Tabuleiro[cx][cy] = 0;
    int numMovimentos = 0;



    for(; x <= POS_MAXIMO; x++ ){
        for(; y<= POS_MAXIMO; y++)
        {
            if( Visitados[x][y] == 0 && Tabuleiro[x][y] > numMovimentos)
            {
                int PosicaoAtual_X = x;
                int PosicaoAtual_Y = y;

                Visitados[x][y] = 1;


            }
        }
        
    }



}

