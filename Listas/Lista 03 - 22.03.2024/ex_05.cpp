/*
Exercício 05
Escreva uma função que recebe dois arrays de inteiros (e seus tamanhos) e devolve um terceiro, alocado dinamicamente (int*), que concatena os elementos de ambos.
O array retornado deve ser criado internamente, pela função.
Assinatura: 		int* arrayConcat(int* v1, int n1, int* v2, int n2);
Exemplo
int v1[3] = { 2, 9, 6 };
int v2[4] = { 3, 7, 7, 9 };
int* v3 = arrayConcat(v1, 3, v2, 4);
// resultado { 2, 9, 6, 3, 7, 7, 9};
*/

#include <iostream>
#include <string>
using namespace std;

int* arrayConcat(int* v1, int n1, int* v2, int n2);
void print_vet(int n, int* v);

int main(){
    int v1[3] = { 2, 9, 6 };
    int v2[4] = { 3, 7, 7, 9 };
    int* v3 = arrayConcat(v1, 3, v2, 4);
    print_vet(7, v3);
    delete v3;

    return 0;
}

int* arrayConcat(int* v1, int n1, int* v2, int n2){
    int* new_array = new int[n1+n2];
    for(int i=0; i<n1; i++) new_array[i] = v1[i];
    for(int i=0; i<n2; i++) new_array[n1+i] = v2[i];

    return new_array;
}

void print_vet(int n, int* v){
    for (int i=0; i<n; i++) printf("%d, ",v[i]);
    printf("\b\b \n");
}

//github.com/tiagodefendi
