#include "../../headers/fila-lista-sequencial/FilaSequencialCircular.h"
#include <iostream>

FilaSequencialCircular::FilaSequencialCircular(int capacidade) : v(new Elemento*[capacidade]), capacidade(capacidade), quantidade(0), inicio(0), fim(-1) {}

FilaSequencialCircular::~FilaSequencialCircular() {
    delete[] v;
}

bool FilaSequencialCircular::enfileirar(Elemento* elemento) {
    if (filaCheia()) {
        return false;
    }
    fim = (fim + 1) % capacidade;
    v[fim] = elemento;
    quantidade++;
    return true;
}

bool FilaSequencialCircular::desenfileirar() {
    if (filaVazia()) {
        return false;
    }
    inicio = (inicio + 1) % capacidade;
    quantidade--;
    return true;
}


Elemento* FilaSequencialCircular::consultarInicio() const {
    if (filaVazia()) {
        return nullptr;
    }
    return v[inicio];
}


bool FilaSequencialCircular::filaCheia() const {
    return quantidade == capacidade;
}

bool FilaSequencialCircular::filaVazia() const {
    return quantidade == 0;
}

void FilaSequencialCircular::imprimirFila() const {
    std::cout << "=== Fila Sequencial Circular (Inicio -> Fim) ===" << std::endl;
    if (filaVazia()) {
        std::cout << "[Fila Vazia]" << std::endl;
        return;
    }
    for (int i = 0; i < this->quantidade; i++) {
        Elemento* elemento = this->v[(this->inicio + i) % this->capacidade];
        if (elemento != nullptr) {
            std::cout << "Posicao [" << i << "]: ";
            elemento->imprimirInfo();
        }
    }
}
