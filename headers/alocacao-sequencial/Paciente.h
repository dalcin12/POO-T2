#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include "Elemento.h"

typedef struct{
    int dia;
    int mes;
    int ano;
} data_de_nascimento;

class Paciente : public Elemento{
    private:
        string nome;
        int idade;
        string planoDeSaude;
        data_de_nascimento dataDeNascimento;
        int diaDaConsulta;

    public:
        Paciente(int ID, string nome, int idade, string planoDeSaude, data_de_nascimento dataDeNascimento);
        
        void imprimirInfo() const;
        void ambiente_teste();
        bool agendarConsulta();
        void cancelarConsulta();
        int getDiaDaConsulta();
        string getNome();
        int getIdade();
        string getPlanoDeSaude();
        void setPlanoDeSaude(string novoPlanoDeSaude);
        data_de_nascimento getDataDeNascimento();

};

#endif // PACIENTE_H