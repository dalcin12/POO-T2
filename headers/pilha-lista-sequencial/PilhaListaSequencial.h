#ifndef PILHASEQUENCIAL_H
#define PILHASEQUENCIAL_H

#include "ListaNaoOrdenada.h"

class PilhaListaSequencial {
    private:

        ListaNaoOrdenada listaBase;

    public:

        PilhaListaSequencial(int capacidade);
        ~PilhaListaSequencial();
        bool empilhar(Elemento* elemento);
        bool desempilhar();
        Elemento* consultarTopo() const;
        bool pilhaCheia() const;
        bool pilhaVazia() const;
        void imprimirPilha() const;
};

#endif // PILHASEQUENCIAL_H