//
// Created by samue on 16/10/2026.
//

#ifndef POO_T2_DEQUELISTAENCADEADA_H
#define POO_T2_DEQUELISTAENCADEADA_H

#include "../alocação-encadeada/ListaDuplamenteEncadeadaCircular.h"

// Deque (double-ended queue) sobre lista duplamente encadeada circular
// Permite inserir e remover nas duas pontas:
//   inserirInicio -> listaBase.inserirNoInicio(valor)
//   inserirFim    -> listaBase.inserirNoFim(valor)
//   removerInicio -> listaBase.removerInicio()
//   removerFim    -> listaBase.removerFim()
//   inicioDeque   -> listaBase.obterInicio(valor)
//   fimDeque      -> listaBase.obterFim(valor)
// Com a lista duplamente encadeada circular, todas as operações são O(1)
// (o início é cabeca->prox e o fim é cabeca->ant).

class DequeListaEncadeadaCircular {
private:
    ListaDuplamenteEncadeadaCircular listaBase;
    int tamanho;

public:
    DequeListaEncadeadaCircular();

    void imprimirDeque();
    bool inserirInicio(int valor);
    bool inserirFim(int valor);
    bool removerInicio();
    bool removerFim();
    bool inicioDeque(int& valor) const;
    bool fimDeque(int& valor) const;
    bool vazia() const;
    int getTamanho() const;
};

#endif //POO_T2_DEQUELISTAENCADEADA_H
