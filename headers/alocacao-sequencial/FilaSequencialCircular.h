#ifndef FILASEQUENCIALCIRCULAR_H
#define FILASEQUENCIALCIRCULAR_H

#include "Elemento.h"

class FilaSequencialCircular {
    private:
        Elemento** v;
        int capacidade;
        int quantidade;
        int inicio;
        int fim;

    public:
        FilaSequencialCircular(int capacidade);
        ~FilaSequencialCircular();
        bool enfileirar(Elemento* elemento);
        bool desenfileirar();
        Elemento* consultarInicio() const;
        bool filaCheia() const;
        bool filaVazia() const;
        int getQuantidade() const;
        int getCapacidade() const;
        void imprimirFila() const;
};

#endif // FILASEQUENCIALCIRCULAR_H