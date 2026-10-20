#include "../../headers/alocacao-encadeada/ListaSimplesmenteEncadeada.h"
#include <iostream>

using namespace std;

// Construtor do No.
ListaSimplesmenteEncadeada::No::No(int valor) { 
    this->valor = valor;
    this->prox = nullptr;
}

// Construtor da LSE.
ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() {
    this->cabeca = new No(0);
    this->cabeca->prox = nullptr;
}

// Complexidade: O(n) - impressao da lista.
void ListaSimplesmenteEncadeada::imprimirLista(No *cabeca) {
    No* aux = cabeca->prox;
    while (aux != nullptr) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }
    cout << endl;
}

void ListaSimplesmenteEncadeada::imprimirLista() {
    imprimirLista(this->cabeca);
}

// Complexidade: O(1) - insercao no inicio da lista.
bool ListaSimplesmenteEncadeada::inserirNoInicio(No *cabeca, int valor) {
    No* novo = new No(valor);
    
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
        return false;
    }

    novo->prox = cabeca->prox;
    cabeca->prox = novo;
    return true;
}

bool ListaSimplesmenteEncadeada::inserirNoInicio(int valor) {
    return inserirNoInicio(this->cabeca, valor);
}

// Complexidade: O(n) - insercao no fim da lista.
bool ListaSimplesmenteEncadeada::inserirNoFim(No* cabeca, int valor) {
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
    aux->prox = novo;

    return true;
}

bool ListaSimplesmenteEncadeada::inserirNoFim(int valor) {
    return inserirNoFim(this->cabeca, valor);
}

// Complexidade: O(n) - insercao na posicao ordenada da lista.
bool ListaSimplesmenteEncadeada::inserirOrdenado(No* cabeca, int valor) {
    No* novo = new No(valor);
    if (novo == nullptr) {
        cout << "Erro ao alocar memoria para o novo no." << endl;
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

bool ListaSimplesmenteEncadeada::inserirOrdenado(int valor) {
    return inserirOrdenado(this->cabeca, valor);
}

// Complexidade: O(1) - remocao do inicio da lista.
bool ListaSimplesmenteEncadeada::removerInicio(No* cabeca) {
    No* aux = cabeca->prox;
    if (aux == nullptr) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
        return false;
    }

    cabeca->prox = aux->prox;
    delete aux; // free(aux);
    return true;
}

bool ListaSimplesmenteEncadeada::removerInicio() {
    return removerInicio(this->cabeca);
}

// Complexidade: O(n) - remocao do fim da lista.
bool ListaSimplesmenteEncadeada::removerFim(No* cabeca) {
    if (cabeca->prox == nullptr) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
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

bool ListaSimplesmenteEncadeada::removerFim() {
    return removerFim(this->cabeca);
}

// Complexidade: O(n) - remocao atraves do ID.
bool ListaSimplesmenteEncadeada::removerPeloId(No* cabeca, int Id) {
    if (cabeca->prox == nullptr) {
        cout << "Lista vazia. Nao e possível remover o no." << endl;
        return false;
    }

    No* aux = cabeca->prox;
    No* ant = cabeca;

    while (aux != nullptr && aux->valor != Id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == nullptr) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return false;
    }

    ant->prox = aux->prox;
    delete aux; // free(aux);
    return true;
}

bool ListaSimplesmenteEncadeada::removerPeloId(int Id) {
    return removerPeloId(this->cabeca, Id);
}

// Complexidade: O(n) - busca exaustiva atraves do ID.
ListaSimplesmenteEncadeada::No* ListaSimplesmenteEncadeada::buscarPeloId(No* cabeca, int Id) {
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

ListaSimplesmenteEncadeada::No* ListaSimplesmenteEncadeada::buscarPeloId(int Id) {
    return buscarPeloId(this->cabeca, Id);
}

// Complexidade: O(n) - altera um valor atraves do ID.
bool ListaSimplesmenteEncadeada::alterarPeloId(No* cabeca, int Id, int novoValor) {
    No* aux = buscarPeloId(cabeca, Id);
    
    if (aux == nullptr) {
        cout << "No com o valor " << Id << " nao encontrado." << endl;
        return false;
    }

    aux->valor = novoValor;
    return true;
}

bool ListaSimplesmenteEncadeada::alterarPeloId(int Id, int novoValor) {
    return alterarPeloId(this->cabeca, Id, novoValor);
}

void ListaSimplesmenteEncadeada::ambienteTeste(No* cabeca) {

    // Inserir elementos
    inserirNoInicio(cabeca, 10);
    inserirNoFim(cabeca, 20);
    inserirOrdenado(cabeca, 15);

    // Imprimir lista
    cout << "Lista apos insercoes: ";
    imprimirLista();

    // Remover elementos
    removerInicio(cabeca);
    removerFim(cabeca);
    removerPeloId(cabeca, 15);

    // Imprimir lista após remoções
    cout << "Lista apos remocoes: ";
    imprimirLista();

    // Alterar elemento
    inserirNoInicio(cabeca, 30);
    alterarPeloId(cabeca, 30, 35);

    // Imprimir lista após alteração
    cout << "Lista apos alteracao: ";
    imprimirLista();
}

void ListaSimplesmenteEncadeada::ambienteTeste() {
    ambienteTeste(this->cabeca);
}

// Complexidade: O(1) - checa se a lista esta vazia. 
bool ListaSimplesmenteEncadeada::estaVazia(No* cabeca) const {
    return cabeca->prox == nullptr;
}

bool ListaSimplesmenteEncadeada::estaVazia() const {
    return estaVazia(this->cabeca);
}

// Complexidade: O(1) - obtem o valor inicial da lista.
int ListaSimplesmenteEncadeada::obterInicio(No* cabeca) const {
    if (estaVazia()) {
        return -1;
    }
    return cabeca->prox->valor;
}

int ListaSimplesmenteEncadeada::obterInicio() const {
    return obterInicio(this->cabeca);
}

// Complexidade: O(n) - libera a memoria da lista.
bool ListaSimplesmenteEncadeada::destruirListaSimplesmenteEncadeada(No* cabeca) {
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
    return true;
}

// Destrutor da lista.
ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    if (this->cabeca != nullptr) {
        destruirListaSimplesmenteEncadeada(this->cabeca);
        delete this->cabeca;
        this->cabeca = nullptr;
    }
}