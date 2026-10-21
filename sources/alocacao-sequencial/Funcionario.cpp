#include "../../headers/alocacao-sequencial/Elemento.h"
#include "../../headers/alocacao-sequencial/Funcionario.h"
#include <string>
#include <iostream>

using namespace std;

// Guarda os dados recebidos para representar o funcionario.
Funcionario :: Funcionario(int ID, string nome, int idade, float salario, int cargaHoraria) : Elemento() {
    this->ID = ID;
    this->nome = nome;
    this->idade = idade;
    this->salario = salario;
    this->cargaHoraria = cargaHoraria;
}

// Exibe os dados do funcionario.
void Funcionario :: imprimirInfo() const {
    cout << "--- Tipo: Funcionario ---" << endl;
    cout << "ID: "<< getID() << endl;
    cout << "Nome: "<< this->nome << endl;
    cout << "Idade: "<< this->idade << endl;
    cout << "Salario: "<< this->salario << endl;
    cout << "Carga horaria: "<< this->cargaHoraria << endl;
}

// Metodos de consulta dos dados do funcionario.
string Funcionario :: getNome() {
    return this->nome;
}

int Funcionario :: getIdade() {
    return this->idade;
}

float Funcionario :: getSalario() {
    return this->salario;
}

int Funcionario :: getCargaHoraria() {
    return this->cargaHoraria;
}

// Informa a carga horaria trabalhada.
void Funcionario :: trabalhar(int cargaHoraria) {
    cout << "O funcionario " << this->nome << " trabalhou por " << cargaHoraria << " horas." << endl;
}