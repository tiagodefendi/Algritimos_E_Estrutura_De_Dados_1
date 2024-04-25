#include <istream>
#include <string>
#include "aluno.hpp"

using namespace std;

class Turma {
private:
    string codDisciplina;
    string codTurma;
    string semestre;

    Aluno** alunos;
    int tamVetor;
    int qtde;

public:
    Turma(string semestre, int tamVetor){
        this->semestre = semestre;
        this->codTurma = "";
        this->codDisciplina = "";

        this->alunos = new Aluno*[tamVetor];
        this->tamVetor = tamVetor;
        this->qtde = 0;
   }
   ~Turma(){
        delete[] this->alunos;
   }

    string getCodDisciplina() const { return this->codDisciplina; }
    string getCodTurma() const { return this->codTurma; }
    string getSemestre() const { return this->semestre; }
    Aluno** getAluno() const { return this->alunos; }

    bool matricula(Aluno* a){
        if (this->qtde < this->tamVetor){
            this->alunos[this->qtde] = a;
            this->qtde ++;
            return true;
        }
        else return false;
    }

    int cancelaMatricula(string ra) {
        for (int i = 0; i < this->qtde; i++) {
            if (this->alunos[i]->getRa() == ra) {
                for (int j = i; j < this->qtde - 1; j++) {
                    this->alunos[j] = this->alunos[j + 1];
                }
                this->qtde--;
                this->alunos[this->qtde] = nullptr;
                return i;
            }
        }
        return -1;
    }


    void imprime(){
        cout << "Código da Disciplina: " << this->codDisciplina << endl;
        cout << "Código da Turma: " << this->codTurma << endl;
        cout << "Semestre: " << this->semestre << endl;
        cout << "Alunos:" << endl;
        for (int i = 0; i < this->qtde; i++){
            cout << this->alunos[i]->getRa() << endl;
        }
    }
};
