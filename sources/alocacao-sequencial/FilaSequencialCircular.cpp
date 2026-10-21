#include "../../headers/alocacao-sequencial/FilaSequencialCircular.h"
#include <iostream>

// Reserva o espaco inicial e prepara a fila sem elementos.
FilaSequencialCircular::FilaSequencialCircular(int capacidade) : v(new Elemento*[capacidade]), capacidade(capacidade), quantidade(0), inicio(0), fim(-1) {}

// Libera o vetor que guarda os ponteiros.
FilaSequencialCircular::~FilaSequencialCircular() {
    delete[] v;
}

// Avanca o fim circularmente e guarda o novo elemento.
bool FilaSequencialCircular::enfileirar(Elemento* elemento) {
    if (filaCheia()) {
        return false;
    }
    fim = (fim + 1) % capacidade;
    v[fim] = elemento;
    quantidade++;
    return true;
}

// Avanca o inicio circularmente e reduz a quantidade de elementos.
bool FilaSequencialCircular::desenfileirar() {
    if (filaVazia()) {
        return false;
    }
    inicio = (inicio + 1) % capacidade;
    quantidade--;
    return true;
}


// Retorna o primeiro elemento ou nullptr quando a fila esta vazia.
Elemento* FilaSequencialCircular::consultarInicio() const {
    if (filaVazia()) {
        return nullptr;
    }
    return v[inicio];
}

// Verifica a quantidade de elementos em relacao a capacidade.
bool FilaSequencialCircular::filaCheia() const {
    return quantidade == capacidade;
}

bool FilaSequencialCircular::filaVazia() const {
    return quantidade == 0;
}

// Percorre a fila a partir do inicio, considerando a posicao circular.
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
