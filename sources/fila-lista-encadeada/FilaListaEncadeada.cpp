//
// Created by samue on 16/10/2026.
//
#include "../../headers/fila-lista-encadeada/FilaListaEncadeada.h"
#include <iostream>
using namespace std;

void FilaEncadeadaCircular::imprimirFila() {
    listaBase.imprimirLista();
}

bool FilaEncadeadaCircular::enfileirar(int valor) {
    if (!listaBase.inserirNoFim(valor)) {
        return false;
    }
    return true;
}

bool FilaEncadeadaCircular::desenfileirar() {
    if (!listaBase.removerInicio()) {
        return false;
    }
    return true;
}

bool FilaEncadeadaCircular::consultarInicio(int& valor) const {
    if (listaBase.estaVazia()) {
        return false;
    }
    valor = listaBase.obterInicio();
    return true;
}
bool FilaEncadeadaCircular::filaVazia() const {
    return listaBase.estaVazia();
}

