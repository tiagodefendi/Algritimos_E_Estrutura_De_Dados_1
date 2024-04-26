#include <stdio.h>

class ListaContigua{
    private:
        int* array;
        int capacity;
        int size;

    public:
        ListaContigua(){
            this->size = 0;
            this->capacity = 1;
            this->array = new int[this->capacity];
        }
        ~ListaContigua(){
            delete array;
        }

        // Insere o elemento e na última posição
        bool push_back(int e){
            gerenciaCapacidade();

            this->array[size] = e;
            this->size++;

            return true;
        }
        // Insere o elemento e na primeira posição
        bool push_front(int e){
            gerenciaCapacidade();

            for (int i=this->size; i>0; i--){
                this->array[i+1] = this->array[i];
            }
            this->array[0] = e;
            this->size++;

            return true;
        }
        // Insere o elemento e na posição pos
        bool insert(int pos, int e){
            gerenciaCapacidade();

            for (int i=this->size; i>pos; i--){
                this->array[i+1] = this->array[i];
            }
            this->array[pos] = e;
            this->size++;

            return true;
        }

        // Remove o último elemento
        int pop_back(){
            this->size--;

            gerenciaCapacidade();

            return this->array[size-1];
        }
        // Remove o primeiro elemento
        int pop_front(){
            for (int i=0; i<this->size-1; i++){
                this->array[i] = this->array[i+1];
            }

            this->size--;

            gerenciaCapacidade();

            return this->array[0];
        }
        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos){
            int e = this->array[pos];

            for (int i=pos; i<this->size-1; i++){
                this->array[i] = this->array[i+1];
            }

            this->size--;

            gerenciaCapacidade();

            return e;
        }

        // Retorna o primeiro elemento
        int front(){
            return this->array[0];
        }
        // Retorna o último elemento
        int back(){
            return this->array[size-1];
        }
        // Retorna o elemento da posição pos
        int at(int pos){
            return this->array[pos];
        }

        // Torna a lista vazia
        void clear(){
            delete this->array;
            this->capacity = 1;
            this->array = new int[this->capacity];
            this->size=0;

            gerenciaCapacidade();
        }

        // Verifica se o ListaContigua está vazio
        bool empty(){
            if (size==0) return true;

            return false;
        }

        // Devolve a quantidade de elementos
        int getSize(){
            return this->size;
        }

        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e){
            if (pos<this->size){
                array[pos] = e;
                return true;
            }

            return false;
        }

        // Imprime todos os elementos no formato [1,2,3]
        void print(){
            printf("[");
            for (int i=0; i<this->size; i++){
                printf("%d.",this->array[i]);
            }
            if (size==0) printf(" ");
            printf("\b]\n");
        }

    private:
	    // Dobrar a capacidade quando não houver mais espaço
	    // Reduzir a capacidade pela metade quando for inferior a 25% de ocupação
        void gerenciaCapacidade(){
            if (size<capacity/4){
                int* temp = new int[capacity/2];

                for(int i=0; i<this->size; i++) temp[i] = this->array[i];
                delete this->array;
                this->array = temp;

                this->capacity /= 2;
            }
            else if (size==capacity){
                int* temp = new int[capacity*2];

                for(int i=0; i<this->size; i++) temp[i] = this->array[i];
                delete this->array;
                this->array = temp;

                this->capacity *= 2;
            }
        }
};
