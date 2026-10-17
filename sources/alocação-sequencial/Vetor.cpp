//
// Created by yuri on 16/10/2026.
//

#include "../../headers/alocação-sequencial/Vetor.h"

Vetor::Vetor(int n){
    this->v = new int[n];
    this->tamanho = n;
    for (int i = 0; i < n; i++){
        this->v[i] = 0;
    }
}

Vetor::~Vetor(){
    delete[] this->v;
}

void Vetor::aumentarVetor(int n){
    int *aux = new int[n];
    for(int i = 0; i < n; i++){
        if (i < this->tamanho){
            aux[i] = this->v[i];
        }else
        {
            this->v[i] = 0;
        }
    }
    delete [] this->v;
    this->v = aux;
    this->tamanho = n;
}
