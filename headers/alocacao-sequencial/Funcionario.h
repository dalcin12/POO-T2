#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "Elemento.h"

class Funcionario : public Elemento {
    private:
        string nome;
        int idade;
        float salario;
        int cargaHoraria;
    
    public:
        Funcionario(int ID, string nome, int idade, float salario, int cargaHoraria);
        
        void imprimirInfo() const;
        string getNome();
        int getIdade();
        float getSalario();
        int getCargaHoraria();

        void trabalhar(int cargaHoraria);

};

#endif // FUNCIONARIO_H