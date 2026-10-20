//
// Created by yuri on 16/10/2026.
//
#include <iostream>
#include "../../headers/alocacao-sequencial/Vetor.h"

Vetor::Vetor(int n){
    this->v = new Elemento*[n];
    this->tamanho = n;
    this->quantidade = 0;
    for (int i = 0; i < n; i++){
        this->v[i] = nullptr;
    }
}

Vetor::~Vetor(){ 
    //Isso n apenas apagaria os ponteiros?? Não apaguei pq posso estar errado, essa materia é muito confusa. ~Yan
    //delete[] this->v;
    for (int i = 0; i < this->tamanho; i++){
        delete this->v[i];
    }
    delete[] this->v;
}

int Vetor::getTamanho() const{
    return this->tamanho;
}

int Vetor::getQuantidade() const{
    return this->quantidade;
}

bool Vetor::estaCheia() const{
    return this->quantidade == this->tamanho;
}

bool Vetor::estaVazia() const{
    return this->quantidade == 0;
}

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

int Vetor::BuscarIndice(int id) const{
    for (int i = 0; i < this->quantidade; i++){
        if (this->v[i]->getID() == id){
            return i;
        }
    }
    return -1;

}

Elemento* Vetor::getElemento(int indice) const{
    if (indice >= 0 && indice < this->quantidade){
        return this->v[indice];
    }
    return nullptr;
}

void Vetor::imprimirVetor() const{
    for (int i = 0; i < this->quantidade; i++){
        if (this->v[i] != nullptr){
            this->v[i]->imprimirInfo();
        } else {
            std::cout << "vazio" << std::endl;
        }
    }
}
