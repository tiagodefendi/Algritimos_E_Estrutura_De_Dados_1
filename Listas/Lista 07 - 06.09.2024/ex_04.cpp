/*
4) Escreva uma função que recebe a referência de duas forward_list e
concatena seus conteúdos em um vector, a ser devolvido pelo função.

vector<int> list_concat(forward_list& list1, forward_list& list2);
Exemplo de uso:

forward_list<int> f1 = {1,2,3,4};
forward_list<int> f2 = {5,6};
vector<int> vec = list_concat(f1, f2); // vec = {1,2,3,4,5,6};

*/

#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <forward_list>

vector<int> list_concat(forward_list<int>& list1, forward_list<int>& list2) {
    vector<int> vec = {};

    for (int e: list1) {
        vec.push_back(e);
    }

    for (int e: list2) {
        vec.push_back(e);
    }

    return vec;
}

int main(){
    forward_list<int> f1 = {1,2,3,4};
    forward_list<int> f2 = {5,6};
    vector<int> vec = list_concat(f1, f2); // vec = {1,2,3,4,5,6};

    for (int e: vec) {
        printf("%d\n", e);
    }

    return 0;
}

//github.com/tiagodefendi
