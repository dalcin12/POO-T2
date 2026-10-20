#ifndef FILALISTASEQUENCIAL_H
#define FILALISTASEQUENCIAL_H

#include "ListaNaoOrdenada.h"

class FilaListaSequencial {
    private:
        ListaNaoOrdenada listaBase;

    public:
        FilaListaSequencial(int capacidade);
        ~FilaListaSequencial();
        bool enfileirar(Elemento* elemento);
        bool desenfileirar();
        Elemento* consultarInicio() const;
        bool filaCheia() const;
        bool filaVazia() const;
        void imprimirFila() const;
};

#endif // FILALISTASEQUENCIAL_H
