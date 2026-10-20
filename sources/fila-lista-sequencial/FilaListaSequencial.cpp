#include "../../headers/fila-lista-sequencial/FilaListaSequencial.h"
#include <iostream>

FilaListaSequencial::FilaListaSequencial(int capacidade) : listaBase(capacidade) {
}

FilaListaSequencial::~FilaListaSequencial() {
   
}


bool FilaListaSequencial::enfileirar(Elemento* elemento) {
    return this->listaBase.InserirNoFinal(elemento);
}


bool FilaListaSequencial::desenfileirar() {
    return this->listaBase.RemoverPrimeiro();
}


Elemento* FilaListaSequencial::consultarInicio() const {
    return this->listaBase.obterPrimeiro();
}


bool FilaListaSequencial::filaCheia() const {
    return this->listaBase.ListaCheia();
}


bool FilaListaSequencial::filaVazia() const {
    return this->listaBase.ListaVazia();
}

void FilaListaSequencial::imprimirFila() const {
    std::cout << "=== Fila Sequencial Linear (Inicio -> Fim) ===" << std::endl;
    if (filaVazia()) {
        std::cout << "[Fila Vazia]" << std::endl;
        return;
    }
    for (int i = 0; i < this->listaBase.getQuantidade(); i++) {
        Elemento* elemento = this->listaBase.getElemento(i);
        if (elemento != nullptr) {
            std::cout << "Posicao [" << i << "]: ";
            elemento->imprimirInfo();
        }
    }
}