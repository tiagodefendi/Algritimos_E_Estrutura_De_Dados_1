/*
Exercício 03. Escreva uma função que busque um elemento em um array utilizando a busca binária.
Implemente 2 versões: uma iterativa e uma recursiva.

bool buscaBinariaIterativa(int elemento, int* v, int tam);

bool buscaBinariaRecursiva(int elemento, int* v, int tam);
*/

#include <iostream>

bool buscaBinariaIterativa(int elemento, int* v, int tam) {
    for (int i=tam/2; (i<tam) and (i>=0);){
        if (v[i] == elemento){
            return true;
        }
        else if (v[i] > elemento){
            i--;
        }
        else {
            i++;
        }
    }
    return false;
}

bool buscaBinariaRecursiva(int elemento, int* v, int tam) {
    if (tam<0) {
        return false;
    }

    int meio = tam/2;

    if (v[meio] == elemento){
        return true;
    }
    else if (v[meio] > elemento){
        return buscaBinariaRecursiva(elemento, v, meio);
    }
    else {
        return buscaBinariaRecursiva(elemento, v+meio+1, meio);
    }
}

int main() {
    int v[] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d", buscaBinariaRecursiva(7, v, 10));

    return 0;
}
