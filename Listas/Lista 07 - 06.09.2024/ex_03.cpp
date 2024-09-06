/*
3) Escreva uma função que recebe um array de inteiros e devolve uma stack. O último elemento do array deve ficar na base da pilha e o primeiro elemento deve ficar no topo da pilha

stack<int> vet_to_stack(int n, int v[]);
*/

#include <iostream>
#include <string>
using namespace std;
#include <stack>

stack<int> vet_to_stack(int n, int v[]) {
    stack<int> stk = {};

    for (int i=n-1; i>=0; i--) {
        stk.push(v[i]);
    }

    return stk;
}

int main(){
    int v[] = {1,2,3,4};
    stack<int> stk = vet_to_stack(4, v);

    for (int i=0; i < 4; i++, stk.pop()) {
        printf("%d\n", stk.top());
    }

    return 0;
}

//github.com/tiagodefendi
