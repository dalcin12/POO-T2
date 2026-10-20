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
        std :: string nome;
        int idade;
        std :: string planoDeSaude;
        data_de_nascimento dataDeNascimento;
        int diaDaConsulta;

    public:
        Paciente(int ID, std :: string nome, int idade, std :: string planoDeSaude, data_de_nascimento dataDeNascimento);
        
        void imprimirInfo() const;
        void ambiente_teste();
        bool agendarConsulta();
        void cancelarConsulta();
        int getDiaDaConsulta();
        std :: string getNome();
        int getIdade();
        std :: string getPlanoDeSaude();
        void setPlanoDeSaude(std :: string novoPlanoDeSaude);
        data_de_nascimento getDataDeNascimento();

};

#endif // PACIENTE_H