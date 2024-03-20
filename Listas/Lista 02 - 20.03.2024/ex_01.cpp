/*
Escreva um trecho de código que reprodza a ilustração B
COnsiderando a Ilustração B
Altere o valor do CÓDIGO do produto escreva uma linha de código para cada maneira possível
Altere o valor da DESCRIÇÃO do produto escreva uma linha de código para cada maneira possível
Altere o valor do PREÇO do produto escreva uma linha de código para cada maneira possível
*/

#include <iostream>
#include <string.h>

typedef struct produto {
    int codigo;
    char descricao[12];
    float preco;
} Produto;

int main(){
    Produto prod = {10,"Teclado",98.5f};
    Produto* p = &prod;
    int* pi = &prod.codigo;
    char* pc = prod.descricao;
    float* pf = &prod.preco;

    prod.codigo = 11;
    p->codigo = 12;
    (*p).codigo = 13;
    (&prod)->codigo = 14;

    strcpy(prod.descricao, "Telado Sem Fio");
    strcpy(p->descricao, "Teclado Gamer");
    strcpy((*p).descricao, "Teclado Mecânico");
    strcpy((&prod)->descricao, "Teclado Teclado");

    prod.preco = 120.f;
    p->preco = 333.33f;
    (*p).preco = 690.96f;
    (&prod)->preco = 1000.f;

    return 0;
}

//github.com/tiagodefendi

