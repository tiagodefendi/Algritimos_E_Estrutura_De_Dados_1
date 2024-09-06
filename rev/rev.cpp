#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <stack>

class Caixa {
    private:
        int peso;
        string objeto;

    public:
        Caixa(string objeto, int peso){
            this->peso = peso;
            this->objeto = objeto;
        }

        int getPeso(){
            return this->peso;
        }
        string getObjeto(){
            return this->objeto;
        }
};

int guardar_caixa (vector<stack<Caixa>>& galpao, int n, Caixa* cx) {
    int idx = 0;
    for (stack<Caixa> stk: galpao) {
        if (stk.empty()) {
            stk.push(*cx);
            return idx;
        }

        if ((stk.size()<3) and (stk.top().getPeso() > cx->getPeso())){
            return idx;
        }
        idx ++;
    }

    return -1;
}

int main(){
    vector<stack<Caixa>> galpao = {};

    return 0;
}

//github.com/tiagodefendi
