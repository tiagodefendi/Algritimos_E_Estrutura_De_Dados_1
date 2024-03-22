/*
# Exercício 04

Escreva uma função que cria e devolve um array de inteiros **alocado dinamicamente (int*)**.
O array deve ser preenchido com números em ordem crescente (order=true), iniciando em 1, ou em ordem decrescente (order=false), iniciando em N.

A função deve receber dois parâmetros: o tamanho do array e a ordem do preenchimento

Assinatura:		`int* createArray(int n, bool asc);`
*/

#include <iostream>
#include <string>
using namespace std;

int* createArray(int n, bool asc);
void print_vet(int n, int* v);

int main(){
    int* v = createArray(10, true);
    print_vet(10, v);
    delete[] v;
    v = createArray(10, false);
    print_vet(10, v);
    delete[] v;

    return 0;
}

int* createArray(int n, bool asc){
    int *array = new int[n];
    if (asc){
        for (int i=0; i<n; i++){
            array[i] = i+1;
        }
    }
    else {
        for (int i=0, j=n; i<n; i++, j--){
            array[i] = j;
        }
    }
    return array;
}

void print_vet(int n, int* v){
    for (int i=0; i<n; i++) printf("%d, ",v[i]);
    printf("\b\b \n");
}

//github.com/tiagodefendi
