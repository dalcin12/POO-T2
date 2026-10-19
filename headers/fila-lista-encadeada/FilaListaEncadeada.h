//
// Created by samue on 15/10/2026.
//

#ifndef POO_T2_FILALISTAENCADEADA_H
#define POO_T2_FILALISTAENCADEADA_H

#include "../../headers/alocação-encadeada/ListaDuplamenteEncadeadaCircular.h"

// Fila (FIFO)
// A frente da fila é o início da lista, e o final da fila é o final da lista.
//  enfileirar -> listaBase.inserirNoFim(int valor)
//  desenfileirar -> listaBase.removerInicio()
// com a lista duplamente encadeade circular podemos fazer ambas as operações em O(1)

class FilaEncadeadaCircular {
    private:
        ListaDuplamenteEncadeadaCircular listaBase;
    public:

        void imprimirFila();
        bool enfileirar(int valor);
        bool desenfileirar();
        bool consultarInicio(int& valor) const;
        bool filaVazia() const;
};


#endif //POO_T2_FILALISTAENCADEADA_H
