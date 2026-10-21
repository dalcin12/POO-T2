#include "../../headers/alocacao-encadeada/PilhaListaEncadeada.h"
#include <iostream>

using namespace std;

// Usa a impressao da lista para mostrar os valores da pilha.
void PilhaListaSimplesmenteEncadeada::imprimirPilha() {
    listaBase.imprimirLista();
}

// O inicio da lista representa o topo da pilha.
bool PilhaListaSimplesmenteEncadeada::empilhar(int valor) {
    if (!listaBase.inserirNoInicio(valor)) {
        return false;
    }

    return true;
}

// Remove da lista o valor que esta no topo.
bool PilhaListaSimplesmenteEncadeada::desempilhar() {
    if (!listaBase.removerInicio()) {
        return false;
    }

    return true;
}

// Consulta o topo sem alterar a pilha.
bool PilhaListaSimplesmenteEncadeada::topoPilha(int& valor) const {
    if (listaBase.estaVazia()) {
        return false;
    }

    valor = listaBase.obterInicio();
    return true;
}

// A pilha esta vazia quando a lista que a compoe esta vazia.
bool PilhaListaSimplesmenteEncadeada::pilhaVazia() const {
    return listaBase.estaVazia();
}