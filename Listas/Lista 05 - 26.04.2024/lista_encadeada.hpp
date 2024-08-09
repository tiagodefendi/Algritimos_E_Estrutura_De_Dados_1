#include <iostream>
using namespace std;

#define LISTA_VAZIA -999999
#define POSICAO_INVALIDA -999998

class No {
    public:
    No* ant;
    int dado;
    No* prox;

    No() {}
    No(int dado) { this->dado = dado; }
    No(No* ant, int dado, No* prox) {
        this->ant = ant;
        this->dado = dado;
        this->prox = prox;
    }
};

class ListaEncadeada {
    private:
        No* primeiro;
        No* ultimo;
        int qtde;

    public:
        ListaEncadeada() {
            this->primeiro = nullptr;
            this->ultimo = nullptr;
            this->qtde = 0;
        }
        ~ListaEncadeada(){
            this -> clear(); // esvaziar espaços na memória
        }
    
    private:
        No* getEnderecoNo(int pos){
            if (pos < this->qtde / 2) { // verifica se está no intervalo da primeira metade do vetor
                No* tempNo = this->primeiro; // nó temporário recebe o endereço do primeiro elemento do vetor
                for (int i = 0; i < pos; i++) { // laço q anda do primeiro elemento até chegar no nó desejado
                    tempNo = tempNo->prox; // nó temporário recebe o endereço próximo nó
                }
                return tempNo;
            }
            else {
                No* tempNo = this->ultimo; // caso esteja na segunda metade o nó temporário recebe o endereço do último nó
                for (int i = this->qtde; i > pos; i--) { // anda do ultimo elemento até o nó desejado
                    tempNo = tempNo->ant; // nó temporário recebe o último elemento
                }
                return tempNo;
            }
        }

    public:
        // Insere o elemento e na última posição
        bool push_back(int e) {
            No* newNo = new No(nullptr, e, nullptr);

            if (this->empty()) { // verifica se o vetor está vazio
                this->primeiro = newNo; // se sim o adiciona como primeiro
            }
            else {
                this->ultimo->prox = newNo; // se não o último nó faz como q o seu proximo aponte para o novo nó
                newNo->ant = this->ultimo; // faz com que o elemento anterior do novo nó seja o antigo ultimo
            }

            this->ultimo = newNo; // faz com que o ultimo nó agora seja o novo
            this->qtde ++; // aumenta a quantidade

            return true;
        }
        // Insere o elemento e na primeira posição
        bool push_front(int e) {
            No* newNo = new No(nullptr, e, nullptr);

            if (this->empty()){ // verifica se o vetor está vazio
                this->ultimo = newNo; // se sim o ultimo elemento apontará para o novo nó
            }
            else {
                this->primeiro->ant = newNo; // se não o primeiro elemento começara apontar para o novo como o seu anterior
                newNo->prox = this->primeiro; // o próximo do novo nó apntará para o primeiro
            }
            this->primeiro = newNo; // novo nó se torna o primeiro
            this->qtde ++; // aumenta a quantidade

            return true;
        }
        // Insere o elemento e na posição pos
        bool insert(int pos, int e) {
            if (pos < 0) { // verifica se a posição é válida / se não é menor q zero
                return false;
            }
            if (pos > this->qtde) { // verifica se a posição é válida / se não é maior q qtde
                return false;
            }

            if (this->empty()) {
                return this->push_back(e); // caso esteja vazia apenas manda um push back
            }
            else if (pos == 0) {
                return this->push_front(e); // caso seja um insert na primeira posição
            }
            else if (pos == this->qtde) { // caso seja um insert na ultima posição
                return this->push_back(e);
            }

            else {
                No* newNo = new No(nullptr, e, nullptr);
                No* tempNo = getEnderecoNo(pos); // um nó temporário recebe o nó da posição pos

                newNo->ant = tempNo->ant; // novo nó passa a apontar com ant para o ant do nó temporário
                tempNo->ant = newNo; // agora o nó temporário passa a apontar para o novo como o anterior
                newNo->prox = tempNo; // o novo passa apontar para o temporário como prox

                this->qtde ++;
                return true;
            }
        }

        // Remove o último elemento
        int pop_back() {
            if (this->empty()){ // verifica se a lsta está vazia
                return LISTA_VAZIA;
            }

            No* tempNo = this->ultimo; // clona o penúltimo nó
            int dado_del = this->ultimo->dado; // clona o elemento dentro do ultimo nó
            this->ultimo = this->ultimo->ant;

            if (this->ultimo == nullptr) { // caso se a lista tinha apenas um elemento os ponteiros apontam para null
                this->primeiro = nullptr;

            }
            else {
                this->ultimo->prox = nullptr; // o proximo não apontara par nada
            }

            delete tempNo;
            this->qtde --;
            return dado_del;
        }
        // Remove o primeiro elemento
        int pop_front() {
            if (this->empty()){ // verifica se a lsta está vazia
                return LISTA_VAZIA;
            }

            No* tempNo = this->primeiro; // clona o segundo elemento
            int dado_del = this->primeiro->dado; // clona o elemento no primeiro
            this->primeiro = this->primeiro->prox;

            if (this->primeiro == nullptr) { // caso se a lista tinha apenas um elemento os ponteiros apontam para null
                this->ultimo = nullptr;
            }
            else {
                this->primeiro->ant = nullptr; // o ponteiro ant agora aponta para nada
            }

            delete tempNo; // deleta o ultimo nó
            this->qtde --;
            return dado_del;
        }
        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos) {
            if (this->empty()) { // verifica se a lista está vazia
                return LISTA_VAZIA;
            }
            if (pos < 0) { // verifica se a posição é menor q zero
                return POSICAO_INVALIDA;
            }
            if (pos > this->qtde-1) { // verifica se a posição é maior q quantidade de vetores
                return POSICAO_INVALIDA;
            }

            if (this->qtde == 1) { // verifica se é o único elemento
                return this->pop_back();
            }
            else if (pos == 0) { // verifica se é o primeiro elemento
                return this->pop_front();
            }
            else if (pos == this->qtde-1){ // verifica se é o ultimo elemento
                return this->pop_back();
            }

            No* tempNo = this->getEnderecoNo(pos);
            int dado_del = tempNo->dado;

            tempNo->ant->prox = tempNo->prox;
            tempNo->prox->ant = tempNo->ant;

            delete tempNo;
            this->qtde --;
            return dado_del;
        }


        // Retorna o primeiro elemento
        int front() {
            if (this->empty()) { // verifica se a lista está vazia
                return LISTA_VAZIA;
            }

            return this->primeiro->dado;
        }
        // Retorna o último elemento
        int back() {
            if (this->empty()) { // verifica se a lista está vazia
                return LISTA_VAZIA;
            }

            return this->ultimo->dado;
        }
        // Retorna o elemento da posição pos
        int at(int pos) {
            if (this->empty()) { // verifica se a lista está vazia
                return LISTA_VAZIA;
            }
            if (pos < 0) { // verifica se a posição é menor q zero
                return POSICAO_INVALIDA;
            }
            if (pos > this->qtde-1) { // verifica se a posição é maior q quantidade de vetores
                return POSICAO_INVALIDA;
            }

            return this->getEnderecoNo(pos)->dado;
        }

        // Torna a lista vazia
        void clear() {
            No* tempNo = this->primeiro;
            for (int i=0; i<this->qtde-1; i++){
                tempNo = tempNo->prox;
                delete this->primeiro;
                this->primeiro = tempNo;
            }

            this->primeiro = nullptr;
            this->ultimo = nullptr;
            this->qtde = 0;

            // while (!this->empty()) {
            //     this->pop_back();
            // }  
        }

        // Verifica se o vetor está vazio
        bool empty() {
            return this->qtde == 0; // caso quantidade == 0 return true, caso contrario return false
        }
        // Devolve a quantidade de elementos
        int size() {
            return this->qtde;
        }
        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e) {
            if (this->empty()) {
                return LISTA_VAZIA;
            }
            return true;
        }

        // Imprime todos os elementos no formato [1,2,3]
        // void print() {
        //     printf("[");

        //     No* tempNo = this->primeiro;
        //     for (int i=0; i<this->qtde-1; i++){
        //         printf("%d,", tempNo->dado);
        //         tempNo = tempNo->prox;
        //     }
        //     printf("%d,", tempNo->dado);

        //     if (this->empty()) {
        //         printf(" ");
        //     }

        //     printf("\b]\n");
        // }

        void print() {
            printf("[");

            for (No* aux = this->primeiro; aux != nullptr; aux = aux->prox) {
                printf("%d", aux->dado);
                if (aux != this->ultimo) printf(",");
            }

            printf("]\n");
        }

        // Imprime todos os elementos no formato [3,2,1]
        // void printInverso() {
        //     printf("[");

        //     No* tempNo = this->ultimo;
        //     for (int i=this->qtde-1; i>0; i++){
        //         printf("%d,", tempNo->dado);
        //         tempNo = tempNo->ant;
        //     }
        //     printf("%d,", tempNo->dado);
        //     if (this->empty()) {
        //         printf(" ");
        //     }

        //     printf("\b]\n");
        // }
        void printInverso() {
            printf("[");

            for (No* aux = this->ultimo; aux != nullptr; aux = aux->ant) {
                printf("%d", aux->dado);
                if (aux != this->primeiro) printf(",");
            }

            printf("]\n");
        }
};


// #include <string>

// #define LISTA_VAZIA -999999
// #define POSICAO_INVALIDA -999998

// class No {
//   public:
//    No* ant;
//    int dado;
//    No* prox;

//    No() {}
//    No(int dado) { this->dado = dado; }
//    No(No* ant, int dado, No* prox) {
//       this->ant = ant;
//       this->dado = dado;
//       this->prox = prox;
//    }
// };
