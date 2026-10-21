#include "../../headers/alocacao-encadeada/FilaListaEncadeada.h"
#include <iostream>
using namespace std;

// Usa a impressao da lista para mostrar os valores da fila.
void FilaEncadeadaCircular::imprimirFila() {
    listaBase.imprimirLista();
}

// Adiciona um valor ao fim da lista.
bool FilaEncadeadaCircular::enfileirar(int valor) {
    if (!listaBase.inserirNoFim(valor)) {
        return false;
    }
    return true;
}

// Remove o primeiro valor, que e o mais antigo da fila.
bool FilaEncadeadaCircular::desenfileirar() {
    if (!listaBase.removerInicio()) {
        return false;
    }
    return true;
}

// Consulta o primeiro valor sem remove-lo.
bool FilaEncadeadaCircular::consultarInicio(int& valor) const {
    if (listaBase.estaVazia()) {
        return false;
    }
    valor = listaBase.obterInicio();
    return true;
}

// A fila esta vazia quando a lista que a compoe esta vazia.
bool FilaEncadeadaCircular::filaVazia() const {
    return listaBase.estaVazia();
}
