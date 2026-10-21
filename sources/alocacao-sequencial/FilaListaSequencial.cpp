#include "../../headers/alocacao-sequencial/FilaListaSequencial.h"
#include <iostream>

// A fila usa uma lista sequencial com a capacidade informada.
FilaListaSequencial::FilaListaSequencial(int capacidade) : listaBase(capacidade) {
}

// A lista base cuida de liberar os elementos armazenados.
FilaListaSequencial::~FilaListaSequencial() {
   
}

// Adiciona um elemento ao fim da fila.
bool FilaListaSequencial::enfileirar(Elemento* elemento) {
    return this->listaBase.InserirNoFinal(elemento);
}

// Remove o elemento que esta no inicio da fila.
bool FilaListaSequencial::desenfileirar() {
    return this->listaBase.RemoverPrimeiro();
}

// Consulta o elemento no inicio sem remove-lo.
Elemento* FilaListaSequencial::consultarInicio() const {
    return this->listaBase.obterPrimeiro();
}

// Consulta se a fila esta cheia ou vazia.
bool FilaListaSequencial::filaCheia() const {
    return this->listaBase.estaCheia();
}

bool FilaListaSequencial::filaVazia() const {
    return this->listaBase.estaVazia();
}

// Imprime os elementos da fila do inicio ao fim.
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