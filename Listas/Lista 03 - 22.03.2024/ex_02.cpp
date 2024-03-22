/*
# Exercício 02

Escreva uma função que verifica se um caractere é uma letra. Ela deve retornar **true** para letra ou **false** caso contrário.

Assinatura:          `bool isLetter(char c);`

Exemplo de uso: `bool check = isLetter(‘a’); // check = 1 (true)`

**Sugestão de implementação:**

Dentro da função, declare uma variável local string contendo todas as letras do alfabeto:

`string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"`

O algoritmo deverá percorrer esta string, comparando o caractere fornecido

**c** com cada uma das posições da string. Caso **c** seja encontrado na string, então ele é uma letra (retorna **true**).
Se percorrer a string por completo e não o encontrar, devolve **false**.
*/

#include <iostream>
#include <string>
using namespace std;

bool isLetter(char c);

int main(){
    bool check = isLetter('a');
    cout << check;

    return 0;
}

bool isLetter(char c){
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int check = 0;
    for (int i=0; i< letras.size(); i++){
        if (letras[i] == c) check ++;
    }

    if (check == 1) return true;
    else return false;
}

//github.com/tiagodefendi
