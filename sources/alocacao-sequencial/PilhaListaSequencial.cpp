#include "../../headers/alocacao-sequencial/PilhaListaSequencial.h"
#include <iostream>

PilhaListaSequencial::PilhaListaSequencial(int capacidade) : listaBase(capacidade) {
}

PilhaListaSequencial::~PilhaListaSequencial() {
    
}


bool PilhaListaSequencial::empilhar(Elemento* elemento) {
    return this->listaBase.InserirNoFinal(elemento);
}


bool PilhaListaSequencial::desempilhar() {
    return this->listaBase.RemoverUltimo();
}


Elemento* PilhaListaSequencial::consultarTopo() const {
    return this->listaBase.obterUltimo();
}


bool PilhaListaSequencial::pilhaCheia() const {
    return this->listaBase.estaCheia();
}


bool PilhaListaSequencial::pilhaVazia() const {
    return this->listaBase.estaVazia();
}

void PilhaListaSequencial::imprimirPilha() const {
    std::cout << "=== Pilha Sequencial (Topo -> Base) ===" << std::endl;
    if (pilhaVazia()) {
        std::cout << "[Pilha Vazia]" << std::endl;
        return;
    }
    for (int i = this->listaBase.getQuantidade() - 1; i >= 0; i--) {
        Elemento* elemento = this->listaBase.getElemento(i);
        if (elemento != nullptr) {
            std::cout << "Topo - " << (this->listaBase.getQuantidade() - 1 - i) << ": ";
            elemento->imprimirInfo();
        }
    }
}
