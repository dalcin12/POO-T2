#include "../../headers/alocacao-sequencial/ListaOrdenada.h"
#include <iostream>

// Procura o ID por busca binaria, aproveitando a ordem da lista.
Elemento* ListaOrdenada::BuscarPeloId(int id){
    if (this->estaVazia()){
        return nullptr;
    }
    int fim = this -> quantidade - 1, inicio = 0;
    while (inicio <= fim){
        int meio = (fim+inicio)/2;
        if (this -> v[meio] -> getID() == id){
            return this -> v[meio];
        }
        else if (this -> v[meio] -> getID() > id){
            fim = meio - 1;
            
        }
        else{
            inicio = meio + 1;
        }
    }
    return nullptr;
}

// Retorna o primeiro ou o ultimo elemento, se houver algum.
Elemento* ListaOrdenada::obterPrimeiro() const{
    if (this-> estaVazia()){
        return nullptr;
    }
    return this->v[0];
}

Elemento* ListaOrdenada::obterUltimo() const{
    if (this->estaVazia()){
        return nullptr;
    }
    return this->v[this->quantidade - 1];
}

// Insere pelo ID, mantendo a lista ordenada e evitando IDs repetidos.
bool ListaOrdenada::Inserir(Elemento* elemento){
    if (BuscarPeloId(elemento -> getID()) != nullptr){
        return false;
    }
    if (this->estaCheia()){
        return false;
    }
    int inicio = 0, fim = this -> quantidade - 1;
    while (inicio <= fim){
        int meio = (fim+inicio)/2;
        if (this -> v[meio] -> getID() > elemento -> getID()){ 
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        } //inicio é a posição onde o elemento deve ser inserido
    }
    for (int i = this->quantidade; i > inicio; i--){
        this->v[i] = this->v[i-1];
    }
    this->v[inicio] = elemento;
    this->quantidade++;
    return true;
}

// Remove o elemento do inicio ou do fim e ajusta as posicoes restantes.
bool ListaOrdenada::RemoverPrimeiro(){
    if (this->estaVazia()){
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

bool ListaOrdenada::RemoverUltimo(){
    if (this->estaVazia()){
        return false;
    }
    delete this->v[this->quantidade - 1];
    this->v[this->quantidade - 1] = nullptr;
    this->quantidade--;
    return true;
}

// Busca o ID por busca binaria e remove o elemento correspondente.
bool ListaOrdenada::RemoverPeloId(int id){
    if (this->estaVazia()){
        return false;
    }

    int inicio = 0, fim = this->quantidade - 1;
    int indice = -1;
    
    while (inicio <= fim) {
        int meio = (fim + inicio) / 2;
        
        if (this->v[meio]->getID() == id) {
            indice = meio;
            break;
        }
        else if (this->v[meio]->getID() > id) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
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

// Substitui o elemento e o reinsere para manter a ordem pelo ID.
bool ListaOrdenada::AlterarPeloId(int id, Elemento* novoElemento){
    if (BuscarPeloId(id) == nullptr){
        return false;
    }
    if (id != novoElemento -> getID() && BuscarPeloId(novoElemento -> getID()) != nullptr){
        return false;
    }
    RemoverPeloId(id);
    Inserir(novoElemento);
    return true;
}

// Imprime os elementos na ordem crescente de ID.
void ListaOrdenada::imprimirListaOrdenada() const{
    if (this->estaVazia()){
        std::cout << "Lista vazia" << std::endl;
        return;
    }
    this->imprimirVetor();
    return;
}