/*
Exercício 01
Escreva uma função que recebe como parâmetros uma string e um caractere. A função deve então retornar a posição da primeira ocorrência do caractere na string. Para obter o tamanho de uma string C++ use:
string str = “texto de teste”;
int tam = str.size();
​
Assinatura:
int stringFindFirst(string s, char c);
Exemplo de uso:
int pos = stringFindFirst(“o rato roeu a roupa do rei de roma”, ‘r’);
// pos = 2
*/

#include <iostream>
#include <string>
using namespace std;

int stringFindFirst(string s, char c);

int main(){
    int pos = stringFindFirst("o rato roeu a roupa do rei de roma", 'r');

    printf("%d", pos);

    return 0;
}

int stringFindFirst(string s, char c){
    for (int i=0; i < s.size(); i++){
        if ( s[i] == c) return i;
    }

    return -1;
}

//github.com/tiagodefendi
