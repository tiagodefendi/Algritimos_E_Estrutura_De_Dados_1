/*
2) Escreva uma função que recebe um array de inteiros e devolve uma forward_list,
contendo os elementos do array na mesma ordem.

forward_list<int> vet_to_flist(int n, int v[]);
*/

#include <iostream>
#include <string>
using namespace std;
#include <forward_list>

forward_list<int> vet_to_flist(int n, int v[]){
    forward_list<int> flist ={};

    for(int i=n-1; i>=0; i--){
        flist.push_front(v[i]);
    }

    return flist;
}

int main(){
    int v[] = {1,2,3,4};
    forward_list<int> flist = vet_to_flist(4, v);

    for (int e: flist) {
        printf("%d\n", e);
    }

    return 0;
}

//github.com/tiagodefendi
