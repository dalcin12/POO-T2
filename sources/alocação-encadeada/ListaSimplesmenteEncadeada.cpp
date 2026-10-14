#include "../../headers/alocação-encadeada/ListaSimplesmenteEncadeada.h"
#include <iostream>

using namespace std;

ListaSimplesmenteEncadeada::No::No(int valor) {
    this->valor = valor;
    this->prox = nullptr;
}

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() {}

void ListaSimplesmenteEncadeada::imprimirLista(No *cabeca) {
    No* aux = cabeca->prox;
    while (aux != nullptr) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

bool ListaSimplesmenteEncadeada::inserirNoInicio(No *cabeca, int valor) {
    No* novo = new No(valor);
    
    if (novo == nullptr) {
        return false;
    }

    novo->prox = cabeca->prox;
    cabeca->prox = novo;
    return true;
}

bool ListaSimplesmenteEncadeada::inserirNoFim(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        return false;
    }

    No* aux = cabeca;
    
    while (aux->prox != nullptr) {
        aux = aux->prox;
    }

    novo->prox = nullptr;
    aux->prox = novo;

    return true;
}

bool ListaSimplesmenteEncadeada::inserirOrdenado(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        return false;
    }

    No* aux = cabeca->prox;
    No* ant = cabeca;

    while (aux != nullptr && aux->valor < valor) {
        ant = aux;
        aux = aux->prox;
    }

    novo->prox = aux;
    ant->prox = novo;

    return true;
}

bool ListaSimplesmenteEncadeada::removerInicio(No* cabeca) {
    No* aux = cabeca->prox;
    if (aux == nullptr) {
        return false;
    }

    cabeca->prox = aux->prox;
    delete aux; // free(aux);
    return true;
}

bool ListaSimplesmenteEncadeada::removerFim(No* cabeca) {
    if (cabeca->prox == nullptr) {
        return false;
    }

    No* aux = cabeca;
    No* ant = nullptr;
    
    while (aux->prox != nullptr) {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = nullptr;
    delete aux; // free(aux);

    return true;
}

bool ListaSimplesmenteEncadeada::removerPeloId(No* cabeca, int Id) {
    No* aux = cabeca->prox;
    No* ant = cabeca;

    while (aux != nullptr && aux->valor != Id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == nullptr) {
        return false;
    }

    ant->prox = aux->prox;
    delete aux; // free(aux);
    return true;
}

ListaSimplesmenteEncadeada::No* ListaSimplesmenteEncadeada::buscarPeloId(No* cabeca, int Id) {
    No* aux = cabeca->prox;
    
    while (aux != nullptr && aux->valor != Id) {
        aux = aux->prox;
    }

    return aux;
}

bool ListaSimplesmenteEncadeada::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);
    if (aux == nullptr) {
        return false;
    }

    aux->valor = novoValor;
    return true;
}

void ListaSimplesmenteEncadeada::ambienteTeste() {
    No* cabeca = new No(0); // Cabeça da lista

    // Inserir elementos
    inserirNoInicio(cabeca, 10);
    inserirNoFim(cabeca, 20);
    inserirOrdenado(cabeca, 15);

    // Imprimir lista
    cout << "Lista apos insercoes: ";
    imprimirLista(cabeca);

    // Remover elementos
    removerInicio(cabeca);
    removerFim(cabeca);
    removerPeloId(cabeca, 15);

    // Imprimir lista após remoções
    cout << "Lista apos remocoes: ";
    imprimirLista(cabeca);

    // Alterar elemento
    inserirNoInicio(cabeca, 30);
    alterarPeloId(cabeca, 30, 35);

    // Imprimir lista após alteração
    cout << "Lista apos alteracao: ";
    imprimirLista(cabeca);

    // Limpar memória
    while (cabeca->prox != nullptr) {
        removerInicio(cabeca);
    }
    
    delete cabeca; // free(cabeca);
}