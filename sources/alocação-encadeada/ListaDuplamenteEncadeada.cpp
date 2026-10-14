#include "../../headers/alocação-encadeada/ListaDuplamenteEncadeada.h"
#include <iostream>

using namespace std;

ListaDuplamenteEncadeada::No::No(int valor) {
    this->valor = valor;
    this->prox = nullptr;
    this->ant = nullptr;
}

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {}

void ListaDuplamenteEncadeada::imprimirLista(No* cabeca) {
    No* aux = cabeca->prox;

    while (aux != nullptr) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

bool ListaDuplamenteEncadeada::inserirNoInicio(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        return false;
    }

    novo->prox = cabeca->prox;
    novo->ant = cabeca;
    if (cabeca->prox != nullptr) {
        cabeca->prox->ant = novo;
    }
    cabeca->prox = novo;

    return true;
}

bool ListaDuplamenteEncadeada::inserirNoFim(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        return false;
    }

    No* aux = cabeca;

    while (aux->prox != nullptr) {
        aux = aux->prox;
    }

    novo->prox = nullptr;
    novo->ant = aux;
    aux->prox = novo;

    return true;
}

bool ListaDuplamenteEncadeada::inserirOrdenado(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        return false;
    }

    No* aux = cabeca;

    while (aux->prox != nullptr && aux->prox->valor < valor) {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    novo->ant = aux;
    if (aux->prox != nullptr) {
        aux->prox->ant = novo;
    }
    aux->prox = novo;

    return true;
}

bool ListaDuplamenteEncadeada::removerInicio(No* cabeca) {
    if (cabeca->prox == nullptr) {
        return false;
    }

    No* aux = cabeca->prox;
    cabeca->prox = aux->prox;
    if (aux->prox != nullptr) {
        aux->prox->ant = cabeca;
    }

    delete aux;
    return true;
}

bool ListaDuplamenteEncadeada::removerFim(No* cabeca) {
    if (cabeca->prox == nullptr) {
        return false;
    }

    No* aux = cabeca;

    while (aux->prox != nullptr) {
        aux = aux->prox;
    }

    aux->ant->prox = nullptr;
    delete aux;
    return true;
}

bool ListaDuplamenteEncadeada::removerPeloId(No* cabeca, int Id) {
    if (cabeca->prox == nullptr) {
        return false;
    }

    No* aux = cabeca->prox;

    while (aux != nullptr && aux->valor != Id) {
        aux = aux->prox;
    }

    if (aux == nullptr) {
        return false;
    }

    aux->ant->prox = aux->prox;
    if (aux->prox != nullptr) {
        aux->prox->ant = aux->ant;
    }

    delete aux;
    return true;
}

ListaDuplamenteEncadeada::No* ListaDuplamenteEncadeada::buscarPeloId(No* cabeca, int Id) {
    No* aux = cabeca->prox;

    while (aux != nullptr && aux->valor != Id) {
        aux = aux->prox;
    }

    return aux;
}

bool ListaDuplamenteEncadeada::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);

    if (aux == nullptr) {
        return false;
    }

    aux->valor = novoValor;
    return true;
}

void ListaDuplamenteEncadeada::ambienteTeste() {
    No* cabeca = new No(0); // Nó cabeça

    inserirNoInicio(cabeca, 10);
    inserirNoInicio(cabeca, 20);
    inserirNoFim(cabeca, 5);
    inserirOrdenado(cabeca, 15);

    cout << "Lista apos insercoes: ";
    imprimirLista(cabeca);

    removerInicio(cabeca);
    cout << "Lista apos remover do inicio: ";
    imprimirLista(cabeca);

    removerFim(cabeca);
    cout << "Lista apos remover do fim: ";
    imprimirLista(cabeca);

    removerPeloId(cabeca, 15);
    cout << "Lista apos remover pelo ID 15: ";
    imprimirLista(cabeca);

    alterarPeloId(cabeca, 10, 25);
    cout << "Lista apos alterar o valor do ID 10 para 25: ";
    imprimirLista(cabeca);

    delete cabeca; // free(cabeca)
}