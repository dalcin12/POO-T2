#include <iostream>
#include "../../headers/alocacao-sequencial/Vetor.h"

// Cria o vetor com todas as posicoes vazias.
Vetor::Vetor(int n){
    this->v = new Elemento*[n];
    this->tamanho = n;
    this->quantidade = 0;
    for (int i = 0; i < n; i++){
        this->v[i] = nullptr;
    }
}

// Libera os elementos armazenados e o vetor de ponteiros.
Vetor::~Vetor(){ 
    for (int i = 0; i < this->tamanho; i++){
        delete this->v[i];
    }
    delete[] this->v;
}

// Retorna a capacidade atual e a quantidade de elementos.
int Vetor::getTamanho() const{
    return this->tamanho;
}

int Vetor::getQuantidade() const{
    return this->quantidade;
}

// Confere se ainda ha espaco ou se nao ha elementos armazenados.
bool Vetor::estaCheia() const{
    return this->quantidade == this->tamanho;
}

bool Vetor::estaVazia() const{
    return this->quantidade == 0;
}

// Aumenta a capacidade sem perder os elementos que ja estao no vetor.
void Vetor::aumentarVetor(int n){
    Elemento **aux = new Elemento*[n];
    for(int i = 0; i < n; i++){
        if (i < this->tamanho){
            aux[i] = this->v[i];
        } else {
            aux[i] = nullptr;
        }
    }
    delete [] this->v;
    this->v = aux;
    this->tamanho = n;
}

// Procura o indice do elemento com o ID informado.
int Vetor::BuscarIndice(int id) const{
    for (int i = 0; i < this->quantidade; i++){
        if (this->v[i]->getID() == id){
            return i;
        }
    }
    return -1;

}

// Retorna o elemento somente quando o indice esta ocupado.
Elemento* Vetor::getElemento(int indice) const{
    if (indice >= 0 && indice < this->quantidade){
        return this->v[indice];
    }
    return nullptr;
}

// Imprime os elementos armazenados na ordem atual.
void Vetor::imprimirVetor() const{
    for (int i = 0; i < this->quantidade; i++){
        if (this->v[i] != nullptr){
            this->v[i]->imprimirInfo();
        } else {
            std::cout << "vazio" << std::endl;
        }
    }
}
