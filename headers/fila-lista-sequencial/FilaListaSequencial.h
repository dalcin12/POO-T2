#ifndef FILASEQUENCIAL_H
#define FILASEQUENCIAL_H

#include "ListaNaoOrdenada.h"

class FilaSequencial {
    private:
        ListaNaoOrdenada listaBase;

    public:
        FilaSequencial(int capacidade);
        ~FilaSequencial();
        bool enfileirar(Elemento* elemento);
        bool desenfileirar();
        Elemento* consultarInicio() const;
        bool filaCheia() const;
        bool filaVazia() const;
        void imprimirFila() const;
};

#endif // FILASEQUENCIAL_H
