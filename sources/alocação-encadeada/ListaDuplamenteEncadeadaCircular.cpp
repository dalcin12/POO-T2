#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

using namespace std;

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() {
    this->cabeca = new No(0);
}

void ListaDuplamenteEncadeadaCircular::imprimirLista(No* cabeca) {
    No* aux = cabeca->prox;

    while (aux != cabeca) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }

    cout << endl;
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
        cout << "Nó com o valor " << Id << " não encontrado." << endl;
        return false;
    }
    
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    delete aux;

    return true;
}

ListaDuplamenteEncadeadaCircular::No* ListaDuplamenteEncadeadaCircular::buscarPeloId(No* cabeca, int Id) {
    No* aux = cabeca->prox;

    while (aux != cabeca && aux->valor != Id) {
        aux = aux->prox;
    }

    if (aux == cabeca) {
        cout << "Nó com o valor " << Id << " não encontrado." << endl;
        return nullptr;
    }

    return aux;
}

bool ListaDuplamenteEncadeadaCircular::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);

    if (aux == nullptr) {
        return false;
    }

    aux->valor = novoValor;
    return true;
}

void ListaDuplamenteEncadeadaCircular::ambienteTeste() {
    cout << "Executando ambiente de teste da lista duplamente encadeada circular..." << endl;

    inserirNoInicio(cabeca, 10);
    inserirNoInicio(cabeca, 20);
    inserirNoFim(cabeca, 30);
    inserirOrdenado(cabeca, 25);

    cout << "Lista após inserções: ";
    imprimirLista(cabeca);

    removerInicio(cabeca);
    cout << "Lista após remover o início: ";
    imprimirLista(cabeca);

    removerFim(cabeca);
    cout << "Lista após remover o fim: ";
    imprimirLista(cabeca);

    removerPeloId(cabeca, 25);
    cout << "Lista após remover o nó com valor 25: ";
    imprimirLista(cabeca);

    alterarPeloId(cabeca, 10, 15);
    cout << "Lista após alterar o nó com valor 10 para 15: ";
    imprimirLista(cabeca);
}