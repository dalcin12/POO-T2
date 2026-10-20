#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Vetor.h"
class ListaOrdenada: public Vetor {
    public:
    ListaOrdenada(int capacidade) : Vetor(capacidade) {}
    virtual~ListaOrdenada() {}
    Elemento* BuscarPeloId(int id);
    Elemento* obterPrimeiro() const;
    Elemento* obterUltimo() const;
    bool Inserir(Elemento* elemento);
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    bool RemoverPeloId(int id);
    bool AlterarPeloId(int id, Elemento* novoElemento);
    void imprimirListaOrdenada() const;

};
    


#endif // LISTAORDENADA_H