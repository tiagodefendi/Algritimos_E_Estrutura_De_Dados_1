/*
# Exercício 03

Escreva uma função que verifica se um nome é válido, isto é, formado apenas por letras e espaços.
Utilize a função do exercício anterior para verificar se cada caractere da string é uma letra.
É permitido haver um único espaço entre cada palavra do nome (exceto no início e no final).

Assinatura: 		`bool checkName(string s)`

Exemplo de uso: 	`bool check = checkName(“Chuck Kick Norris”); // check = 1(true)`
*/

#include <iostream>
#include <string>
using namespace std;

bool checkName(string s);

int main(){
    bool check = checkName("Chuck Kick Norris");
    printf("%d", check);

    return 0;
}

bool checkName(string s){
    string letras = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    int check = 0;
    for (int i=0; i< letras.size(); i++){
        for (int j=0; j < s.size(); j++){
            if (letras[i] == s[j]) check ++;
        }
    }

    if (check == s.size()) return true;
    else return false;
}

//github.com/tiagodefendi
