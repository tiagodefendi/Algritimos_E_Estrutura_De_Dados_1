/*
5) Escreva uma função que verifica a parentização de expressões string do tipo

[(x + 8) * (9-2)]

Utilize uma pilha stack para realizar o processo:

percorrer a expressão de entrada
ao encontrar um símbolo "abre", ( [ { , empilha
ao encontrar um símbolo "fecha", ) ] }, retira o símbolo do tipo "abre" do topo e compara ambos
se o "abre" e o "fecha" correspondem, continua
se diferem, então a expressão está incorreta
se a pilha estiver vazia, a expressão está incorreta
ao terminar de percorrer a expressão de entrada, a pilha deve estar vazia
se restou algum símbolo na pilha, então a expressão está incorreta

*/

#include <iostream>
#include <string>
using namespace std;
#include <stack>

bool verify_parent(string str) {
    stack<char> stk = {};

    for (char c : str){
        if (c=='(' or c=='[' or c=='{') {
            stk.push(c);
        }
        else if (c==')' or c==']' or c=='}') {
            if (stk.empty()){
                return false;
            }

            char p = stk.top();
            stk.pop();

            if ((p=='(')and(c=')')){
                continue;
            }
            else if ((p=='[') and (c=']')){
                continue;
            }
            else if ((p=='{') and (c='}')){
                continue;
            }
            else {
                return false;
            }
        }
    }

    if (stk.empty()) {
        return true;
    }

    return false;
}

int main(){
    printf("%d",verify_parent("teste{[0asda]}"));

    return 0;
}

//github.com/tiagodefendi
