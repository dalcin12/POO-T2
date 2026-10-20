//
///crated by: Yan-Cods 18/10/2026
//
#include "../../headers/alocacao-sequencial/ListaNaoOrdenada.h"
#include <iostream>

bool ListaNaoOrdenada::InserirNoInicio(Elemento* elemento){
    if (this->estaCheia()){
        return false;
    }
    for (int i = this->quantidade; i > 0; i--){
        this->v[i] = this->v[i-1];
    }
    this->v[0] = elemento;
    this->quantidade++;
    return true;
}

bool ListaNaoOrdenada::InserirNoFinal(Elemento* elemento){
    if (this->estaCheia()){
        return false;
    }
    this->v[this->quantidade] = elemento;
    this->quantidade++;
    return true;
}

bool ListaNaoOrdenada::RemoverPrimeiro(){
    if (this->quantidade == 0){
        return false;
    }
    delete this->v[0];
    for (int i = 0; i < this->quantidade - 1; i++){
        this->v[i] = this->v[i+1];
    }
    this->v[this->quantidade - 1] = nullptr;
    this->quantidade--;
    return true;
}

bool ListaNaoOrdenada::RemoverUltimo(){
    if (this->estaVazia()){
        return false;
    }
    delete this->v[this->quantidade - 1];
    this->v[this->quantidade - 1] = nullptr;
    this->quantidade--;
    return true;
}


Elemento* ListaNaoOrdenada::BuscarPeloId(int id){
    int indice = Vetor::BuscarIndice(id);
    if (indice == -1){
        return nullptr;
    }
    return this->v[indice];
}

Elemento* ListaNaoOrdenada::obterPrimeiro() const{
    if (this->estaVazia()){
        return nullptr;
    }
    return this->v[0];
}

Elemento* ListaNaoOrdenada::obterUltimo() const{
    if (this->estaVazia()){
        return nullptr;
    }
    return this->v[this->quantidade - 1];
}

bool ListaNaoOrdenada::RemoverPeloId(int id){
    int indice = Vetor::BuscarIndice(id);
    if (indice == -1){
        return false;
    }
    delete this->v[indice];
    for (int i = indice; i < this->quantidade - 1; i++){
        this->v[i] = this->v[i+1];
    }
    this->v[this->quantidade - 1] = nullptr;
    this->quantidade--;
    return true;
}

bool ListaNaoOrdenada::AlterarPeloId(int id, Elemento* novoElemento){
    int indice = Vetor::BuscarIndice(id);
    if (indice == -1){
        return false;
    }
    delete this->v[indice];
    this->v[indice] = novoElemento;
    return true;
}

void ListaNaoOrdenada::imprimirListaNaoOrdenada() const{
    if (this->estaVazia()){
        std::cout << "Lista vazia" << std::endl;
        return;
    }
    this->imprimirVetor();
    return;
}