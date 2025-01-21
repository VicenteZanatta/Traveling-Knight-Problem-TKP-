#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int INFINITO = 10000000; 
const int POS_MAXIMO = 7;
const int POS_MINIMO = 0;

int MovimentosEm_X[7] = {-1,1,2,2,1,-1,-2,-2};
int MovimentosEm_Y [7]= {2,2,1,-1,-2,-2,-1,1};

typedef struct no{

    int x;
    int y;
    int visitado;
    int movimentos;
}No;

int validaPosicao(int x, int y);
int dijkstra(int cx, int cy, int dx, int dy, int numMovimentos, int posicoesVisitadas[][7]);
void inicializaMatrizes( int matriz1[7][7], int matriz2[7][7]);

int main() {
 
    char Posicao_inicial[3];
    char Destino[3];



    No posicaoCavalo;
    No destino;
    int input_xCavalo = 0;
    int input_yCavalo = 0;
    int input_xDestino = 0;
    int input_yDestino = 0;

    int posicoesVisitadas[7][7];

    fgets(Posicao_inicial, 3, stdin);
    fgets(Destino, 3, stdin);

    input_yCavalo = Posicao_inicial[1] - 96;  // converte os valores de char
    input_xCavalo = Posicao_inicial[2] - 47;  // para inteiros  
    input_yDestino = Destino[1] - 96;         // com base na tabela ASCII
    input_xDestino = Destino[2] - 47;

    posicaoCavalo.x = input_xCavalo;
    posicaoCavalo.y = input_yCavalo;
    posicaoCavalo.movimentos = 0;
    destino.x = input_xDestino;
    destino.y = input_yDestino;


    return 0;
}

int validaPosicao(int x, int y){

    return(( x > 0 && x < 7 ) && ( y > 0 && y < 7 ));

}

void relaxamento(int MatrizDePosicao[][7], int X_atual, int Y_atual,int movimentos)
{
    
}

void inicializaMatrizes( int matriz_Tabuleiro[7][7], int matriz_Visitados[7][7])
{
    int x = 0;
    int y = 0;

    for(; x <= POS_MAXIMO; x++ ){
        for(; y<= POS_MAXIMO; y++)
        matriz_Tabuleiro[x][y] = INFINITO;
        matriz_Visitados[x][y] = 0;
    }
}

int dijkstra(int cx, int cy, int dx, int dy, int posicoesVisitadas[][7])
{    
    int Tabuleiro[7][7];
    int Visitados[7][7];
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

