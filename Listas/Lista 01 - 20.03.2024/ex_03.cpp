/*
Escreva um trecho de código que reproduza a ilustração acima
Escreva um trecho de código que imprima os valores 1, 2, 3, 4, 5, 6
Utilize notação de sua preferência
*/

#include <iostream>

void print_matriz(int l, int c, int**v){
    for (int i=0; i<l; i++){
        for (int j=0; j<c; j++){
            printf("%d, ",v[i][j]);
        }
    }
    printf("\b\b \n");
}

int main(){
    int v1[] = {1, 2, 3};
    int* p1 = v1;
    int v2[] = {4, 5, 6};
    int* p2 = v2;
    int* m[] = {v1, v2};
    int** pm = m;

    print_matriz(2, 3, pm);

    return 0;
}

//github.com/tiagodefendi
