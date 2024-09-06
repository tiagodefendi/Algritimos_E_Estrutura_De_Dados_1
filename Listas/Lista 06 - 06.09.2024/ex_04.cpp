/*
Exercício 04. Seja A uma matriz de inteiros 10x10 que representa um labirinto.
A entrada do labirinto está na posição (0, 0) e a saída em (9, 9).
Considere que esta matriz inicialmente tenha apenas valores 0 e 1,
onde 0 indica uma posição vazia e 1 indica uma posição ocupada.
Faça um algoritmo para encontrar um caminho da entrada até a saída.
Seu algoritmo deve imprimir as posições (linha, coluna) que estão no caminho,
não necessariamente na ordem a partir do início. Caso não haja um caminho,
imprima “Não existe um caminho para a saída!”.
Somente movimentos para as quatro posições adjacentes são permitidos, ou seja,
não são permitidos movimentos nas diagonais.
Seu algoritmo não precisa encontrar o caminho mais curto.
*/

#include <iostream>

bool explorar(int l[10][10], int i, int j){
    // verificar se a posição é válida

    // verificar se a posição está ocupada ou se já foi visitada

    // Para marcar que a posição foi visitada, atribua o valor 2
    l[i][j] = 2;
    printf("[%d, %d]", i,j);
    // Imprima a posição que foi visitada

    // Verificar se a posição é a 9,9.
    // Caso seja a saída, devolver TRUE

    // Explorar as quatro possibilidades a partir da posição atual (i,j)
    // A possibilidades são para baixo, para direita, para cima e para baixo
    if (explorar(l, i+1, j)) return true;

    if (explorar(l, i, j+1)) return true;
        if (explorar(l, i, j-1)) return true;
        if (explorar(l, i-1, j)) return true;

    return false;

    // Caso não haja caminho para nenhum dos lados, devolver false.

}

int labirinto[10][10] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
};

int imprimir_labirinto(int l[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", l[i][j]);
        }
        printf("\n");
    }
}

int main(){
    imprimir_labirinto(labirinto);
    bool encontreiSaida = explorar(labirinto, 0, 0);
    if(encontreiSaida){
        printf("Achei o caminho para a saída :(");
    } else {
            printf("Não achei o caminho para a saída :(");
        }
    printf("\n");
    imprimir_labirinto(labirinto);
    return 0;
}
