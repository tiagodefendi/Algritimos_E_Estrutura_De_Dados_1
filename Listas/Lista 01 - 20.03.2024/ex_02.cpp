/*
Escreva um trecho de código que reproduza a ilustração acima
Escreva um trecho de código que imprima os valores 10, 20, 30, 40. Não é permetido uso de colchetes.
Utilize anotação de ponteiros (* e aritimética de ponteiro)
*/

#include <iostream>

void print_vector2(int n, int**v){
    for (int i=0; i<n; i++){
        printf("%d, ", **(v+i));
    }
    printf("\b\b \n");
}

int main(){
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int* v[] = {&a, &b, &c, &d};
    int** p = v;

    print_vector2(4, p);

    return 0;
}

//github.com/tiagodefendi
