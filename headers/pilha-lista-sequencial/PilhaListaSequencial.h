#ifndef PILHASEQUENCIAL_H
#define PILHASEQUENCIAL_H

#include "ListaNaoOrdenada.h"

class PilhaSequencial {
    private:

        ListaNaoOrdenada listaBase;

    public:

        PilhaSequencial(int capacidade);
        ~PilhaSequencial();
        bool empilhar(Elemento* elemento);
        bool desempilhar();
        Elemento* consultarTopo() const;
        bool pilhaCheia() const;
        bool pilhaVazia() const;
        void imprimirPilha() const;
};

#endif // PILHASEQUENCIAL_H