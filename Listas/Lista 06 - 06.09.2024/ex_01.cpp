/*
Exercício01. O máximo divisor comum (MDC) de dois inteiros, x e y,
é definido recursivamente por:

mdc(x, y) = y se (y ≤ x) && (x%y == 0)
mdc(x, y) = mdc(y, x) se x < y
mdc(x, y) = mdc(y, x%y), caso contrário
*/

#include <iostream>

int mdc(int x, int y){
    if ((y <= x) and (x%y == 0)){ // se x for maior e o resto da divisão de x por y for 0 y é o mdc
        return y;
    }
    else if (x < y){ // caso x for menor chamar a função com parâmetros invertids
        return mdc(y, x);
    }
    else { // se não
        return mdc(y, x%y);
    }
}

int main(){
    printf("%d", mdc(12, 3));

    return 0;
}
