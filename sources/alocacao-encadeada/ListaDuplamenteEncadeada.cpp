#include "../../headers/alocacao-encadeada/ListaDuplamenteEncadeada.h"
#include <iostream>

using namespace std;

// Construtor do No.
ListaDuplamenteEncadeada::No::No(int valor) {
    this->valor = valor;
    this->prox = nullptr;
    this->ant = nullptr;
}

// Construtor da Lista.
ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() {
    this->cabeca = new No(0);
    this->cabeca->prox = nullptr;
    this->cabeca->ant = nullptr;
}

// Complexidade: O(n) - impressao da lista.
void ListaDuplamenteEncadeada::imprimirLista(No* cabeca) {
    No* aux = cabeca->prox;

    while (aux != nullptr) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

void ListaDuplamenteEncadeada::imprimirLista() {
    imprimirLista(this->cabeca);
}

// Complexidade: O(1) - insercao no inicio da lista.
bool ListaDuplamenteEncadeada::inserirNoInicio(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

bool ListaDuplamenteEncadeada::inserirNoInicio(int valor) {
    return inserirNoInicio(this->cabeca, valor);
}

// Complexidade: O(n) - insercao no fim da lista.
bool ListaDuplamenteEncadeada::inserirNoFim(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

bool ListaDuplamenteEncadeada::inserirNoFim(int valor) {
    return inserirNoFim(this->cabeca, valor);
}

// Complexidade: O(n) - insercao na posicao ordenada da lista.
bool ListaDuplamenteEncadeada::inserirOrdenado(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

bool ListaDuplamenteEncadeada::inserirOrdenado(int valor) {
    return inserirOrdenado(this->cabeca, valor);
}

// Complexidade: O(1) - remocao no inicio da lista.
bool ListaDuplamenteEncadeada::removerInicio(No* cabeca) {
    if (cabeca->prox == nullptr) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
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

bool ListaDuplamenteEncadeada::removerInicio() {
    return removerInicio(this->cabeca);
}

// Complexidade: O(n) - remocao no fim da lista.
bool ListaDuplamenteEncadeada::removerFim(No* cabeca) {
    if (cabeca->prox == nullptr) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
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

bool ListaDuplamenteEncadeada::removerFim() {
    return removerFim(this->cabeca);
}

// Complexidade: O(n) - remocao atraves do ID.
bool ListaDuplamenteEncadeada::removerPeloId(No* cabeca, int Id) {
    if (cabeca->prox == nullptr) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
        return false;
    }

    No* aux = cabeca->prox;

    while (aux != nullptr && aux->valor != Id) {
        aux = aux->prox;
    }

    if (aux == nullptr) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return false;
    }

    aux->ant->prox = aux->prox;
    if (aux->prox != nullptr) {
        aux->prox->ant = aux->ant;
    }

    delete aux;
    return true;
}

bool ListaDuplamenteEncadeada::removerPeloId(int Id) {
    return removerPeloId(this->cabeca, Id);
}

// Complexidade: O(n) - busca exaustiva atraves do ID.
ListaDuplamenteEncadeada::No* ListaDuplamenteEncadeada::buscarPeloId(No* cabeca, int Id) {
    No* aux = cabeca->prox;

    while (aux != nullptr && aux->valor != Id) {
        aux = aux->prox;
    }

    if (aux == nullptr) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return nullptr;
    }

    return aux;
}

ListaDuplamenteEncadeada::No* ListaDuplamenteEncadeada::buscarPeloId(int Id) {
    return buscarPeloId(this->cabeca, Id);
}

// Complexidade: O(n) - alteracao atraves do ID.
bool ListaDuplamenteEncadeada::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);

    if (aux == nullptr) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return false;
    }

    aux->valor = novoValor;
    return true;
}

bool ListaDuplamenteEncadeada::alterarPeloId(int Id, int novoValor) {
    return alterarPeloId(this->cabeca, Id, novoValor);
}

// Complexidade: O(n) - liberacao da memoria da lista.
bool ListaDuplamenteEncadeada::destruirListaDuplamenteEncadeada(No* cabeca) {
    if (cabeca == nullptr) {
        return false;
    }

    No* aux = cabeca->prox;

    while (aux != nullptr) {
        No* prox = aux->prox;
        delete aux;
        aux = prox;
    }

    cabeca->prox = nullptr;
    cabeca->ant = nullptr;
    return true;
}

// Destrutor da lista.
ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    if (this->cabeca != nullptr) {
        destruirListaDuplamenteEncadeada(this->cabeca);
        delete this->cabeca;
        this->cabeca = nullptr;
    }
}