#include "../../headers/alocacao-sequencial/Paciente.h"
#include "../../headers/alocacao-sequencial/Elemento.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

// Guarda os dados recebidos para representar o paciente.
Paciente :: Paciente(int ID, string nome, int idade, string planoDeSaude, data_de_nascimento dataDeNascimento) : Elemento(){
    this -> ID = ID;
    this -> nome = nome;
    this -> idade = idade;
    this -> planoDeSaude = planoDeSaude;
    this -> dataDeNascimento = dataDeNascimento;
}

// Exibe os dados do paciente.
void Paciente :: imprimirInfo() const {
    cout << "--- Tipo: Paciente ---" << endl;
    cout << "ID: "<< getID() << endl;
    cout << "Nome: "<< this->nome << endl;
    cout << "Idade: "<< this->idade << endl;
    cout << "Plano de saude: "<< this->planoDeSaude << endl;
    cout << "Data de nascimento: " << this->dataDeNascimento.dia << "/" << this->dataDeNascimento.mes << "/" << this->dataDeNascimento.ano << endl;
}

// Marca uma consulta somente para um dos dias disponiveis.
bool Paciente :: agendarConsulta(){
    int dia = 0;
    cout << "Dias disponiveis: 15, 16, 17 e 18." << endl;
    cout << "Digite o dia que deseja marcar a consulta: ";
    cin >> dia;

    if (dia >= 15 && dia <= 18) {
        this->diaDaConsulta = dia;
        cout << "Consulta marcada com sucesso no dia " << dia << "." << endl;
        return true;
    }
    
    cout << "Nao foi possivel marcar a consulta. Dia indisponivel." << endl;
    return false;
}

// Cancela a consulta apagando o dia marcado.
void Paciente :: cancelarConsulta() {
    this->diaDaConsulta = 0;
    cout << "Consulta cancelada com sucesso!" << endl;
}

// Retorna o dia marcado ou informa que nao ha consulta agendada.
int Paciente :: getDiaDaConsulta() {
    if (this->diaDaConsulta >= 15 && this->diaDaConsulta <= 18) {
        return this->diaDaConsulta;
    }
        
    cout << "Erro ao obter o dia da consulta. A consulta nao foi marcada." << endl;
    return -1;
}

// Metodos de consulta dos dados do paciente.
string Paciente :: getNome() {
    return this->nome;
}

int Paciente :: getIdade() {
    return this->idade;
}

string Paciente :: getPlanoDeSaude() {
    return this->planoDeSaude;
}

data_de_nascimento Paciente :: getDataDeNascimento() {
    data_de_nascimento data;
    data.dia = this->dataDeNascimento.dia;
    data.mes = this->dataDeNascimento.mes;
    data.ano = this->dataDeNascimento.ano;

    return data;
}

// Atualiza o plano de saude do paciente.
void Paciente :: setPlanoDeSaude(string novoPlanoDeSaude) {
    this->planoDeSaude = novoPlanoDeSaude;
}