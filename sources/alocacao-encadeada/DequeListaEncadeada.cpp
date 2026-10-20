//
// Created by samue on 18/10/2026.
//
#include "../../headers/deque-lista-encadeada/DequeListaEncadeada.h"
#include <iostream>

using namespace std;

void DequeListaEncadeadaCircular::imprimirDeque() {
    listaBase.imprimirLista();
}

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