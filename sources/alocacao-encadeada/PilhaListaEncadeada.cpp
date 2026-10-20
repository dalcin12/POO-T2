//
// Created by samue on 16/10/2026.
//
#include "../../headers/alocacao-encadeada/PilhaListaEncadeada.h"
#include <iostream>

using namespace std;

void PilhaListaSimplesmenteEncadeada::imprimirPilha() {
    listaBase.imprimirLista();
}

bool PilhaListaSimplesmenteEncadeada::empilhar(int valor) {
    if (!listaBase.inserirNoInicio(valor)) {
        return false;
    }

    return true;
}

bool PilhaListaSimplesmenteEncadeada::desempilhar() {
    if (!listaBase.removerInicio()) {
        return false;
    }

    return true;
}

bool PilhaListaSimplesmenteEncadeada::topoPilha(int& valor) const {
    if (listaBase.estaVazia()) {
        return false;
    }

    valor = listaBase.obterInicio();
    return true;
}

bool PilhaListaSimplesmenteEncadeada::pilhaVazia() const {
    return listaBase.estaVazia();
}