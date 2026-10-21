#include "../../headers/alocacao-encadeada/ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

using namespace std;

// Construtor do No.
ListaDuplamenteEncadeadaCircular::No::No(int valor) {
    this->valor = valor;
    this->prox = nullptr;
    this->ant = nullptr;
}

// Construtor da lista.
ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() {
    this->cabeca = new No(0);
    this->cabeca->prox = this->cabeca;
    this->cabeca->ant = this->cabeca;
}

// Complexidade: O(n) - impressao da lista.
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

// Complexidade: O(1) - insercao no inicio da lista.
bool ListaDuplamenteEncadeadaCircular::inserirNoInicio(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

// Complexidade: O(1) - insercao no fim da lista.
bool ListaDuplamenteEncadeadaCircular::inserirNoFim(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

// Complexidade: O(n) - insercao na posicao ordenada da lista.
bool ListaDuplamenteEncadeadaCircular::inserirOrdenado(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

// Complexidade: O(1) - remocao no inicio da lista.
bool ListaDuplamenteEncadeadaCircular::removerInicio(No* cabeca) {
    if (cabeca->prox == cabeca) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
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

// Complexidade: O(1) - remocao no fim da lista.
bool ListaDuplamenteEncadeadaCircular::removerFim(No* cabeca) {
    if (cabeca->prox == cabeca) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
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

// Complexidade: O(n) - remocao atraves do ID.
bool ListaDuplamenteEncadeadaCircular::removerPeloId(No* cabeca, int Id) {
    if (cabeca->prox == cabeca) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
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

// Complexidade: O(n) - busca exaustiva atraves do ID.
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

// Complexidade: O(n) - alteracao atraves do ID.
bool ListaDuplamenteEncadeadaCircular::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);

    if (aux == nullptr) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return false;
    }

    aux->valor = novoValor;
    return true;
}

bool ListaDuplamenteEncadeadaCircular::alterarPeloId(int Id, int novoValor) {
    return alterarPeloId(this->cabeca, Id, novoValor);
}

// Complexidade: O(1) - retorna se a fila esta vazia.
bool ListaDuplamenteEncadeadaCircular::estaVazia(No* cabeca) const {
    return cabeca->prox == cabeca;
}

bool ListaDuplamenteEncadeadaCircular::estaVazia() const {
    return estaVazia(this->cabeca);
}

// Complexidade: O(1) - obtem o valor do inicio da lista.
int ListaDuplamenteEncadeadaCircular::obterInicio(No* cabeca) const {
    if (estaVazia(cabeca) == false) {
        return cabeca->prox->valor;
    }
    return -1;
}

int ListaDuplamenteEncadeadaCircular::obterInicio() const {
    return obterInicio(this->cabeca);
}

// Complexidade: O(1) - obtem o valor do fim da lista.
int ListaDuplamenteEncadeadaCircular::obterFim(No* cabeca) const {
    if (estaVazia(cabeca) == false) {
        return cabeca->ant->valor;
    }
    return -1;
}

int ListaDuplamenteEncadeadaCircular::obterFim() const {
    return obterFim(this->cabeca);
}

// Complexidade: O(n) - libera a memoria da lista.
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

// Destrutor da lista.
ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    if (this->cabeca != nullptr) {
        destruirListaDuplamenteEncadeadaCircular(this->cabeca);
        delete this->cabeca;
        this->cabeca = nullptr;
    }
}