#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Vetor.h"
class ListaNaoOrdenada: public Vetor {
    public:
    ListaNaoOrdenada(int capacidade) : Vetor(capacidade) {}
    virtual ~ListaNaoOrdenada() {}

    bool InserirNoInicio(Elemento* elemento);
    bool InserirNoFinal(Elemento* elemento);
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    Elemento* BuscarPeloId(int id);
    Elemento* obterPrimeiro() const;
    Elemento* obterUltimo() const;
    bool RemoverPeloId(int id);
    bool AlterarPeloId(int id, Elemento* novoElemento);
    void imprimirListaNaoOrdenada() const;
    

    
};
    


#endif // LISTANAOORDENADA_H