//
// Created by yuri on 16/10/2026.
//

#include "../../headers/alocação-sequencial/Vetor.h"

Vetor::Vetor(int n){
    this->v = new Elemento*[n];
    this->tamanho = n;
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

void Vetor::aumentarVetor(int n){
    Elemento **aux = new Elemento*[n];
    for(int i = 0; i < n; i++){
        if (i < this->tamanho){
            aux[i] = this->v[i];
        }else
        {
            aux[i] = nullptr;
        }
    }
    delete [] this->v;
    this->v = aux;
    this->tamanho = n;
}
