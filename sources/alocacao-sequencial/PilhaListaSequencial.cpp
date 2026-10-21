#include "../../headers/alocacao-sequencial/PilhaListaSequencial.h"
#include <iostream>

// A pilha usa uma lista sequencial com a capacidade informada.
PilhaListaSequencial::PilhaListaSequencial(int capacidade) : listaBase(capacidade) {
}

// A lista base libera seus elementos ao ser destruida.
PilhaListaSequencial::~PilhaListaSequencial() {
    
}

// A lista guarda o topo no ultimo elemento inserido.
bool PilhaListaSequencial::empilhar(Elemento* elemento) {
    return this->listaBase.InserirNoFinal(elemento);
}

// Remove o elemento que esta no topo.
bool PilhaListaSequencial::desempilhar() {
    return this->listaBase.RemoverUltimo();
}

// Consulta o elemento do topo sem remove-lo.
Elemento* PilhaListaSequencial::consultarTopo() const {
    return this->listaBase.obterUltimo();
}

// Consulta se a pilha atingiu sua capacidade ou esta vazia.
bool PilhaListaSequencial::pilhaCheia() const {
    return this->listaBase.estaCheia();
}

bool PilhaListaSequencial::pilhaVazia() const {
    return this->listaBase.estaVazia();
}

// Imprime a lista do topo em direcao a base.
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
