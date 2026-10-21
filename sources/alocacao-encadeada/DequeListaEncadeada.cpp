#include "../../headers/alocacao-encadeada/DequeListaEncadeada.h"
#include <iostream>

using namespace std;

// Usa a impressao da lista circular para mostrar os valores do deque.
void DequeListaEncadeadaCircular::imprimirDeque() {
    listaBase.imprimirLista();
}

// Insere um valor em uma das extremidades do deque.
bool DequeListaEncadeadaCircular::inserirInicio(int valor) {
    if(!listaBase.inserirNoInicio(valor)) {
        return false;
    }
    return true;
}

bool DequeListaEncadeadaCircular::inserirFim(int valor) {
    if(!listaBase.inserirNoFim(valor)) {
        return false;
    }
    return true;
}

// Remove um valor do inicio ou do fim do deque.
bool DequeListaEncadeadaCircular::removerInicio() {
    if(!listaBase.removerInicio()) {
        return false;
    }
    return true;
}

bool DequeListaEncadeadaCircular::removerFim() {
    if(!listaBase.removerFim()) {
        return false;
    }
    return true;
}

// Consulta os valores das extremidades sem remove-los.
bool DequeListaEncadeadaCircular::consultarInicio(int &valor) const {
    if (listaBase.estaVazia()) {
        return false;
    }
    valor = listaBase.obterInicio();
    return true;
}

bool DequeListaEncadeadaCircular::consultarFim(int &valor) const {
    if (listaBase.estaVazia()) {
        return false;
    }
    valor = listaBase.obterFim();
    return true;
}