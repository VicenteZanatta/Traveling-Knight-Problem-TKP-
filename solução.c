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
int dijkstra(int cx, int cy, int dx, int dy);
void inicializaMatrizes( int matriz1[8][8], int matriz2[8][8]);

int main() {
 
    char Posicao_inicial[3];
    char Destino[3];
    int input_xCavalo = 0;
    int input_yCavalo = 0;
    int input_xDestino = 0;
    int input_yDestino = 0;
    int Resposta = 0;

    scanf("%s", &Posicao_inicial);
    scanf("%s", &Destino);

    input_xCavalo = Posicao_inicial[0] - 'a';  // converte os valores de char
    input_yCavalo = Posicao_inicial[1] - '0';  // para inteiros  
    input_xDestino = Destino[0] - 'a';         // com base na tabela ASCII
    input_yDestino = Destino[1] - '0';
    
    Resposta = dijkstra(input_xCavalo, input_yCavalo, input_xDestino, input_yCavalo);
    printf("To get from %s to %s takes %d knight moves.\n", &Posicao_inicial, &Destino, Resposta);

    return 0;

}

int validaMovimento(int x, int y){

    return(( x >= 0 && x <= 7 ) && ( y >= 0 && y <= 7 ));

}

void relaxamento(int MatrizDePosicao[][8], int X_atual, int Y_atual)
{
    int X_movimento = 0;
    int Y_movimento = 0;
    int numMovimentos = MatrizDePosicao[X_atual][Y_atual]++;
    
    for(int i = 0; i <= POS_MAXIMO; i++)
    {
        X_movimento = X_atual - MovimentosEm_X[i];
        Y_movimento = Y_atual - MovimentosEm_Y[i];

        if(validaMovimento(X_movimento, Y_movimento) == 1)
        {
            MatrizDePosicao[X_movimento][Y_movimento] = numMovimentos;

        }
    }
}

void inicializaMatrizes( int matriz_Tabuleiro[8][8], int matriz_Visitados[8][8])
{
    int x = 0;
    int y = 0;

    for(; x <= POS_MAXIMO; x++ ){
        for(; y<= POS_MAXIMO; y++)
        { 
        
            matriz_Tabuleiro[x][y] = INFINITO;
            matriz_Visitados[x][y] = 0;
        }
    }
}

int dijkstra(int cx, int cy, int dx, int dy)
{    
    int Tabuleiro[8][8];            //contem o numero de movimentos cara chegar adetermionada posição
    int Visitados[8][8];            //armazena a informação se algum no ja foi visitado (1) ou não (0)           
    int x = 0;
    int y = 0;
    int MenorDistancia = INFINITO;
    inicializaMatrizes(Tabuleiro, Visitados);

    Tabuleiro[cx][cy] = 0;
    int numMovimentos = 0;
    int *pnt_Movimentos = &numMovimentos;



    for(; x <= POS_MAXIMO; x++ ){
        for(; y<= POS_MAXIMO; y++)
        {
            if( Visitados[x][y] == 0 && Tabuleiro[x][y] < MenorDistancia)
            {
                
                MenorDistancia = Tabuleiro[x][y];
                Visitados[x][y] = 1;
                relaxamento(Tabuleiro, x, y);
                

                if(x == dx && y == dy)
                    return MenorDistancia;

            }
        }
        
    }
    return -1;
}

