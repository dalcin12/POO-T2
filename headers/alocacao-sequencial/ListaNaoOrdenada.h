#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Vetor.h"
class ListaNaoOrdenada: public Vetor {
    public:
    ListaNaoOrdenada(int capacidade) : Vetor(capacidade) {}
    ~ListaNaoOrdenada() {}

    bool InserirNoInicio(Elemento* elemento);
    bool InserirNoFinal(Elemento* elemento);
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    bool BuscarPeloId(int id);
    bool RemoverPeloId(int id);
    bool AlterarPeloId(int id, Elemento* novoElemento);
    
};
    


#endif // LISTANAOORDENADA_H