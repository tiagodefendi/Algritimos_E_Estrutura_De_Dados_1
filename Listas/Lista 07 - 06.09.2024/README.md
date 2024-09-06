# STL - Lista 1

Implemente os exercícios em C++ (extensão cpp e compilador g++).

As bibliotecas necessárias são: **<iostream>**, **<vector>**, **<forward_list>**, **<stack>** e **<queue>**.

**1) Escreva uma função que recebe um array de inteiros e devolve um vector<int>, contendo os elementos do array na mesma ordem.**

```cpp
vector<int> vet_to_vector(int n, int* v);
```

**2) Escreva uma função que recebe um array de inteiros e devolve uma forward_list<int>, contendo os elementos do array na mesma ordem.**

```cpp
forward_list<int> vet_to_flist(int n, int v[]);
```

**3) Escreva uma função que recebe um array de inteiros e devolve uma stack<int>. O último elemento do array deve ficar na base da pilha e o primeiro elemento deve ficar no topo da pilha**

```cpp
stack<int> vet_to_stack(int n, int v[]);
```

**4) Escreva uma função que recebe a referência de duas forward_list<int> e concatena seus conteúdos em um vector<int>, a ser devolvido pelo função.**

```cpp
vector<int> list_concat(forward_list& list1, forward_list& list2);
```

Exemplo de uso:

```cpp
forward_list<int> f1 = {1,2,3,4};
forward_list<int> f2 = {5,6};
vector<int> vec = list_concat(f1, f2); // vec = {1,2,3,4,5,6};

```

**5) Escreva uma função que verifica a parentização de expressões string do tipo**

`[(x + 8) * (9-2)]`

Utilize uma pilha stack<char> para realizar o processo:

- percorrer a expressão de entrada
- ao encontrar um símbolo "abre", ( [ { , empilha
- ao encontrar um símbolo "fecha", ) ] }, retira o símbolo do tipo "abre" do topo e compara ambos
    - se o "abre" e o "fecha" correspondem, continua
    - se diferem, então a expressão está incorreta
    - se a pilha estiver vazia, a expressão está incorreta
- ao terminar de percorrer a expressão de entrada, a pilha deve estar vazia
    - se restou algum símbolo na pilha, então a expressão está incorreta
