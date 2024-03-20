/*
Escreva um trecho de código que reproduza a ilustração acima
Escreva um trecho de código que imprima os valores 1, 2, 3, 4 a partir da variável p.
Ultilize a notação de sua preferência
*/

#include <iostream>

void print_vector(int n, int* v){
    for (int i=0; i<n; i++){
        printf("%d, ",v[i]);
    }
    printf("\b\b \n");
}

int main(){
    int v[] = {1, 2, 3, 4};
    int* p = v;
    int* w = v+2;

    int i = 30;
    int* x = &i;

    print_vector(4, p);

    return 0;
}

//github.com/tiagodefendi
