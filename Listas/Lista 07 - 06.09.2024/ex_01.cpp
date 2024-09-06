/*
1) Escreva uma função que recebe um array de inteiros e devolve um vector<int>,
contendo os elementos do array na mesma ordem.

vector<int> vet_to_vector(int n, int* v);
*/

#include <iostream>
using namespace std;
#include <vector>

vector<int> vet_to_vector(int n, int* v) {
    vector<int> vec = {};
    
    for(int i=0; i<n; i++){
        vec.push_back(v[i]);
    }

    return vec;
}

int main() {
    int v[] = {1,2,3,4};
    vector<int> vec = vet_to_vector(4, v);

    for (int e: vec) {
        printf("%d\n", e);
    }

    return 0;
}
