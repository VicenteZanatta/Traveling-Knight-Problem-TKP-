#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

 
const int MAXIMO = 7;
const int MINIMO = 0;

int validaPosicao(int x, int y);
int calculaDistancia(int x, int y, int dx, int dy);
 
int main() {
 
    char Posicao_inicial[3];
    char Destino[3];

    int posicaoCavalo[1][1];
    int destino[1][1];
    int xCavalo = 0;
    int yCavalo = 0;
    int xDestino = 0;
    int yDestino = 0;

    fgets(Posicao_inicial, 3, stdin);
    fgets(Destino, 3, stdin);

    yCavalo = Posicao_inicial[1] - 96;  // converte os valores de char
    xCavalo = Posicao_inicial[2] - 47;  // para inteiros  
    yDestino = Destino[1] - 96;         // om base na tabela ASCII
    xDestino = Destino[2] - 47;

    posicaoCavalo[xCavalo][yCavalo];
    destino[xDestino][yDestino];

    return 0;
}

int validaPosicao(int x, int y){

    return(( x > 0 && x < 7 ) && ( y > 0 && y < 7 ));

}

int calculaDistancia(int x, int y, int dx, int dy){
                                                    // calcula o mudola da distancia entre uma 
    return (((x - dx)^2 + (y - dy)^2)^(1/2));       // posicao (x,y) e o destino (dx,dy)

}                                               
