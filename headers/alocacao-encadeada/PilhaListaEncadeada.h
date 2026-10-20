//
// Created by samue on 15/10/2026.
//
#ifndef POO_T2_PILHALISTAENCADEADA_H

#define POO_T2_PILHALISTAENCADEADA_H

#include "../alocacao-encadeada/ListaSimplesmenteEncadeada.h"

// Pilha (LIFO)
// O topo é o início da lista:
//   empilhar    -> listaBase.inserirNoInicio(int valor)
//   desempilhar -> listaBase.removerInicio()
// com a lista duplamente encadeade circular podemos fazer ambas as operações em O(1)

class PilhaListaSimplesmenteEncadeada{
    private:
        ListaSimplesmenteEncadeada listaBase;


    public:
    
        void imprimirPilha();
        bool empilhar(int valor);
        bool desempilhar();
        bool topoPilha(int& valor) const;
        bool pilhaVazia() const;
};

#endif //POO_T2_PILHALISTAENCADEADA_H
