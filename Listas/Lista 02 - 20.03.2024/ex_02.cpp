/*
Altere o valor do CÓDIGO do produto para 100. A alteração deve ocorrer por meio do vetor
Altere o valor da DESCRIÇÃO do produto para "Mouse sem fio". A alteração deve ocorrer por meio do vetor
Crie uma nova variável de produto, preencha todos os seus dados e atribua a posição 3 do vetor
*/

#include <iostream>
#include <string.h>

typedef struct produto {
    int codigo;
    char descricao[12];
    float preco;
} Produto;

int main(){
    Produto prodA = {1,"Teclado",98.5f};
    Produto prodB = {2,"Mouse",65.f};
    Produto prodC = {3,"Webcam",130.f};
    Produto vet[4];
    vet[0] = prodA;
    vet[1] = prodB;
    vet[2] = prodC;

    vet[2].codigo = 100;

    strcpy(vet[2].descricao, "Mouse sem fio");

    Produto prodD = {4, "Casa", 11};
    vet[3] = prodD;


    return 0;
}

//github.com/tiagodefendi
