#include "../../headers/alocação-encadeada/ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

using namespace std;

ListaDuplamenteEncadeadaCircular::No::No(int valor) {
    this->valor = valor;
    this->prox = nullptr;
    this->ant = nullptr;
}

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() {
    this->cabeca = new No(0);
    this->cabeca->prox = this->cabeca;
    this->cabeca->ant = this->cabeca;
}

void ListaDuplamenteEncadeadaCircular::imprimirLista(No* cabeca) {
    No* aux = cabeca->prox;

    while (aux != cabeca) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }

    cout << endl;
}

void ListaDuplamenteEncadeadaCircular::imprimirLista() {
    imprimirLista(this->cabeca);
}

bool ListaDuplamenteEncadeadaCircular::inserirNoInicio(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memória para o novo nó." << endl;
        return false;
    }

    novo->prox = cabeca->prox;
    novo->ant = cabeca;
    cabeca->prox->ant = novo;
    cabeca->prox = novo;
    
    return true;
}

bool ListaDuplamenteEncadeadaCircular::inserirNoInicio(int valor) {
    return inserirNoInicio(this->cabeca, valor);
}

bool ListaDuplamenteEncadeadaCircular::inserirNoFim(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memória para o novo nó." << endl;
        return false;
    }

    novo->prox = cabeca;
    novo->ant = cabeca->ant;
    cabeca->ant->prox = novo;
    cabeca->ant = novo;

    return true;
}

bool ListaDuplamenteEncadeadaCircular::inserirNoFim(int valor) {
    return inserirNoFim(this->cabeca, valor);
}

bool ListaDuplamenteEncadeadaCircular::inserirOrdenado(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memória para o novo nó." << endl;
        return false;
    }

    No* aux = cabeca->prox;
    while (aux != cabeca && aux->valor < valor) {
        aux = aux->prox;
    }

    novo->prox = aux;
    novo->ant = aux->ant;
    aux->ant->prox = novo;
    aux->ant = novo;

    return true;
}

bool ListaDuplamenteEncadeadaCircular::inserirOrdenado(int valor) {
    return inserirOrdenado(this->cabeca, valor);
}

bool ListaDuplamenteEncadeadaCircular::removerInicio(No* cabeca) {
    if (cabeca->prox == cabeca) {
        cout << "Lista vazia. Não é possível remover o nó." << endl;
        return false;
    }

    No* aux = cabeca->prox;
    cabeca->prox = aux->prox;
    aux->prox->ant = cabeca;
    delete aux;
    
    return true;
}

bool ListaDuplamenteEncadeadaCircular::removerInicio() {
    return removerInicio(this->cabeca);
}

bool ListaDuplamenteEncadeadaCircular::removerFim(No* cabeca) {
    if (cabeca->prox == cabeca) {
        cout << "Lista vazia. Não é possível remover o nó." << endl;
        return false;
    }

    No* aux = cabeca->ant;
    cabeca->ant = aux->ant;
    aux->ant->prox = cabeca;
    delete aux;

    return true;
}

bool ListaDuplamenteEncadeadaCircular::removerFim() {
    return removerFim(this->cabeca);
}

bool ListaDuplamenteEncadeadaCircular::removerPeloId(No* cabeca, int Id) {
    if (cabeca->prox == cabeca) {
        cout << "Lista vazia. Não é possível remover o nó." << endl;
        return false;
    }

    No* aux = cabeca->prox;
    
    while (aux != cabeca && aux->valor != Id) {
        aux = aux->prox;
    }

    if (aux == cabeca) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return false;
    }
    
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    delete aux;

    return true;
}

bool ListaDuplamenteEncadeadaCircular::removerPeloId(int Id) {
    return removerPeloId(this->cabeca, Id);
}

ListaDuplamenteEncadeadaCircular::No* ListaDuplamenteEncadeadaCircular::buscarPeloId(No* cabeca, int Id) {
    No* aux = cabeca->prox;

    while (aux != cabeca && aux->valor != Id) {
        aux = aux->prox;
    }

    if (aux == cabeca) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return nullptr;
    }

    return aux;
}

ListaDuplamenteEncadeadaCircular::No* ListaDuplamenteEncadeadaCircular::buscarPeloId(int Id) {
    return buscarPeloId(this->cabeca, Id);
}

bool ListaDuplamenteEncadeadaCircular::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);

    if (aux == nullptr) {
        return false;
    }

    aux->valor = novoValor;
    return true;
}

bool ListaDuplamenteEncadeadaCircular::alterarPeloId(int Id, int novoValor) {
    return alterarPeloId(this->cabeca, Id, novoValor);
}

void ListaDuplamenteEncadeadaCircular::ambienteTeste(No* cabeca) {
    inserirNoInicio(cabeca, 10);
    inserirNoInicio(cabeca, 20);
    inserirNoFim(cabeca, 5);
    inserirOrdenado(cabeca, 15);

    cout << "Lista apos insercoes: ";
    imprimirLista(cabeca);

    removerInicio(cabeca);
    cout << "Lista apos remover o inicio: ";
    imprimirLista(cabeca);

    removerFim(cabeca);
    cout << "Lista apos remover o fim: ";
    imprimirLista(cabeca);

    removerPeloId(cabeca, 15);
    cout << "Lista apos remover o no com valor 15: ";
    imprimirLista(cabeca);

    alterarPeloId(cabeca, 10, 25);
    cout << "Lista apos alterar o no com valor 10 para 25: ";
    imprimirLista(cabeca);
}

void ListaDuplamenteEncadeadaCircular::ambienteTeste() {
    ambienteTeste(this->cabeca);
}

bool ListaDuplamenteEncadeadaCircular::destruirListaDuplamenteEncadeadaCircular(No* cabeca) {
    if (cabeca == nullptr) {
        return false;
    }

    No* aux = cabeca->prox;

    while (aux != cabeca) {
        No* prox = aux->prox;
        delete aux;
        aux = prox;
    }

    cabeca->prox = cabeca;
    cabeca->ant = cabeca;
    return true;
}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    if (this->cabeca != nullptr) {
        destruirListaDuplamenteEncadeadaCircular(this->cabeca);
        delete this->cabeca;
        this->cabeca = nullptr;
    }

}