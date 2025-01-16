#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
const int MAXIMO = 7;
const int MINIMO = 0;
 
 
int main() {
 
    char Posicao_inicial[3];
    char Destino[3];

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

    return 0;
}