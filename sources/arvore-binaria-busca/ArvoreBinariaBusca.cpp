#include "../../headers/arvore-binaria-busca/ArvoreBinariaBusca.h"
#include <iostream>

// Prepara um no sem filhos.
ArvoreBinariaBusca::No::No(int id){
    this->id = id;
    this->dir = nullptr;
    this->esq = nullptr;
}

// A arvore comeca sem raiz.
ArvoreBinariaBusca::ArvoreBinariaBusca(){
    this->raiz = nullptr;
}

// Insere cada ID no lado correspondente, sem repetir valores.
ArvoreBinariaBusca::No* ArvoreBinariaBusca::inserir(No* raiz, int id){
    if (raiz == nullptr) return new No(id);

    if (id == raiz->id) return raiz;

    if (id > raiz->id)
        raiz->dir = inserir(raiz->dir, id);
    else
        raiz->esq = inserir(raiz->esq, id);

    return raiz;
}

// Atualiza a raiz caso a arvore ainda esteja vazia.
void ArvoreBinariaBusca::inserir(int id){
    this->raiz = inserir(this->raiz, id);
}

// Procura o ID seguindo o lado indicado pela ordem dos valores.
bool ArvoreBinariaBusca::buscarPeloId(No* raiz, int id){
    if (raiz == nullptr) return false;
    if (id == raiz->id) return true;

    if (id > raiz->id)
        return buscarPeloId(raiz->dir, id);
    else
        return buscarPeloId(raiz->esq, id);
}

// Exibe se o ID foi encontrado.
void ArvoreBinariaBusca::buscarPeloId(int id){
    bool resultado = buscarPeloId(this->raiz, id);
    if (resultado)
        std::cout << "Encontrado!" << std::endl;
    else
        std::cout << "Não Encontrado!" << std::endl;
}

// Encontra o menor ID da subarvore a direita.
ArvoreBinariaBusca::No* ArvoreBinariaBusca::sucessor(No* atual){
    atual = atual->dir;
    while (atual != nullptr && atual->esq != nullptr)
        atual = atual->esq;
    return atual;
}

// Remove o ID e reorganiza os filhos quando necessario.
ArvoreBinariaBusca::No* ArvoreBinariaBusca::removerPeloId(No* raiz, int id){
    if (raiz == nullptr)
        return raiz;

    if (id > raiz->id)
        raiz->dir = removerPeloId(raiz->dir, id);
    else if (id < raiz->id)
        raiz->esq = removerPeloId(raiz->esq, id);
    else{
        if (raiz->esq == nullptr){
            No* tmp = raiz->dir;
            delete raiz;
            return tmp;
        }
        else if (raiz->dir == nullptr){
            No* tmp = raiz->esq;
            delete raiz;
            return tmp;
        }

        No* tmp = sucessor(raiz);
        raiz->id = tmp->id;
        raiz->dir = removerPeloId(raiz->dir, tmp->id);
    }
    return raiz;
}

// Atualiza a raiz depois da remocao.
void ArvoreBinariaBusca::removerPeloId(int id){
    this->raiz = removerPeloId(this->raiz, id);
}

// Escolhe entre os percursos em ordem, pre-ordem e pos-ordem.
void ArvoreBinariaBusca::imprimir(No* raiz, int escolha){
    switch (escolha)
    {
        case 1:
            if (raiz != nullptr){
                imprimir(raiz->esq, 1);
                std::cout << raiz->id << std::endl;
                imprimir(raiz->dir, 1);
            }
            break;
        case 2:
            if (raiz != nullptr){
                std::cout << raiz->id << std::endl;
                imprimir(raiz->esq, 2);
                imprimir(raiz->dir, 2);
            }
            break;
        case 3:
            if (raiz != nullptr){
                imprimir(raiz->esq, 3);
                imprimir(raiz->dir, 3);
                std::cout << raiz->id << std::endl;
            }
    }
}

// Inicia cada percurso a partir da raiz.
void ArvoreBinariaBusca::emOrdem(){
    imprimir(this->raiz, 1);
}
void ArvoreBinariaBusca::preOrdem(){
    imprimir(this->raiz, 2);
}
void ArvoreBinariaBusca::posOrdem(){
    imprimir(this->raiz, 3);
}

// Libera os nos depois de destruir suas subarvores.
void ArvoreBinariaBusca::destruirArvoreBinaria(No* no){
    if (no == nullptr) return;

    destruirArvoreBinaria(no->esq);
    destruirArvoreBinaria(no->dir);

    delete no;
}

// Libera toda a memoria ocupada pela arvore.
ArvoreBinariaBusca::~ArvoreBinariaBusca(){
    destruirArvoreBinaria(this->raiz);
    this->raiz = nullptr;
}