//
// Created by yuri on 15/10/2026.
//
#include "../../headers/arvore-binaria-busca/ArvoreBinariaBusca.h"
#include <iostream>

ArvoreBinariaBusca::No::No(int id){
    this->id = id;
    this->dir = nullptr;
    this->esq = nullptr;
}

ArvoreBinariaBusca::ArvoreBinariaBusca(){
    this->raiz = nullptr;
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::inserir(No* raiz, int id){
    if (raiz == nullptr) return new No(id);

    if (id == raiz->id) return raiz;

    if (id > raiz->id)
        raiz->dir = inserir(raiz->dir, id);
    else
        raiz->esq = inserir(raiz->esq, id);

    return raiz;
}

void ArvoreBinariaBusca::inserir(int id){
    this->raiz = inserir(this->raiz, id);
}

bool ArvoreBinariaBusca::buscarPeloId(No* raiz, int id){
    if (raiz == nullptr) return false;
    if (id == raiz->id) return true;

    if (id > raiz->id)
        return buscarPeloId(raiz->dir, id);
    else
        return buscarPeloId(raiz->esq, id);
}

void ArvoreBinariaBusca::buscarPeloId(int id){
    bool resultado = buscarPeloId(this->raiz, id);
    if (resultado)
        std::cout << "Encontrado!" << std::endl;
    else
        std::cout << "Não Encontrado!" << std::endl;
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::sucessor(No* atual){
    atual = atual->dir;
    while (atual != nullptr && atual->esq != nullptr)
        atual = atual->esq;
    return atual;
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::removerPeloId(No* raiz, int id){
    if (raiz == nullptr)
        return raiz;

    if (id > raiz->id)
        raiz->dir = removerPeloId(raiz->dir, id);
    else if (id < raiz->id)
        raiz->esq = removerPeloId(raiz->esq, id);
    else{
        if (raiz->esq != nullptr){
            No* tmp = raiz->dir;
            delete raiz;
            return tmp;
        }else if (raiz->dir != nullptr){
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

void ArvoreBinariaBusca::removerPeloId(int id){
    this->raiz = removerPeloId(this->raiz, id);
}