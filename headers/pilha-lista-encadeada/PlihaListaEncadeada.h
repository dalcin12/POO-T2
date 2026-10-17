//
// Created by samue on 15/10/2026.
//
#ifndef POO_T2_PLIHALISTAENCADEADA_H

#define POO_T2_PLIHALISTAENCADEADA_H

#include "../headers/alocação-encadeada/ListaDuplamenteEncadeadaCircular.h"

// Pilha (LIFO)
// O topo é o início da lista:
//   empilhar    -> listaBase.inserirNoInicio(int valor)
//   desempilhar -> listaBase.removerInicio()
// com a lista duplamente encadeade circular podemos fazer ambas as operações em O(1)

class PilhaListaEncadeadaCircular {
    private:
        ListaDuplamenteEncadeadaCircular listaBase;
        int tamanho;

    public:
        PilhaListaEncadeadaCircular();

        void imprimirPilha();
        bool empilhar(int valor);
        bool desempilhar();
        bool topoPilha(int& valor) const;
        bool pilhaVazia() const;
        int getTamanho() const;
        bool estaVazia() const;
};

#endif //POO_T2_PLIHALISTAENCADEADA_H
