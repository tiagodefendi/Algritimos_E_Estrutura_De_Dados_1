/*
Exercício 06
Escreva uma função que recebe dois arrays de inteiros ordenados crescentemente (e seus tamanhos) e devolve um terceiro,
alocado dinamicamente (int*), que mescla os elementos de ambos. O array retornado deve ser criado internamente, pela função.
Você deve assumir que os arrays de entrada estão ordenados.
Assinatura: 		int* arrayMerge(int* v1, int n1, int* v2, int n2);
Exemplo:
int v1[5] = { 1, 2, 4, 6, 8 };
int v2[4] = { 3, 5, 9, 20 };
int* v3 = arrayMerge(v1, 5, v2, 4);
// resultado {1, 2, 3, 4, 5, 6, 8, 9, 20};
*/

#include <iostream>
#include <string>
using namespace std;

int* arrayMerge(int* v1, int n1, int* v2, int n2);
void print_vet(int n, int* v);

int main(){
    int v1[5] = { 1, 2, 4, 6, 8 };
    int v2[4] = { 3, 5, 9, 20 };
    int* v3 = arrayMerge(v1, 5, v2, 4);
    print_vet(9, v3);

    return 0;
}

int* arrayMerge(int* v1, int n1, int* v2, int n2){
    int* new_array = new int[n1+n2];
    int k = 0;

    int i = 0;
    int j = 0;
    while (k < n1+n2){
        if (v1[i]<v2[j]){
            new_array[k] = v1[i];
            k++;
            i++;
        }
        else if (v1[i]>v2[j]){
            new_array[k] = v2[j];
            k++;
            j++;
        }
        else{
            new_array[k] = v1[i];
            k++;
            i++;
            j++;
        }
    }

    return new_array;
}

void print_vet(int n, int* v){
    for (int i=0; i<n; i++) printf("%d, ",v[i]);
    printf("\b\b \n");
}

//github.com/tiagodefendi
