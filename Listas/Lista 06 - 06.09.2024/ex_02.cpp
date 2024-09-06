/*
Exercício 02. Escreva uma função que busque um elemento em um array de forma sequencial

bool buscaSequencial(int elemento, int* v, int tam);
*/

#include <iostream>

bool buscaSequencial(int elemento, int* v, int tam){
    if (tam==0) { // se o tamanho for 0 o valor não foi encontrado na lista
        return false;
    }
    else if (elemento == v[tam-1]) { // caso o elemento seja o procurado retorna true
        return true;
    }

    return buscaSequencial(elemento, v, tam-1); // se não andar um para trás na busca

}

int main() {
    int v[4] = {1,2,3,4};

    printf("%d", buscaSequencial(4, v, 4));

    return 0;
}
