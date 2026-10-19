#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Vetor.h"
class ListaOrdenada: public Vetor {
    public:
    ListaOrdenada(int capacidade) : Vetor(capacidade) {}
    ~ListaOrdenada() {}
    Elemento* BuscarPeloId(int id);
    bool Inserir(Elemento* elemento);
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    bool RemoverPeloId(int id);
    bool AlterarPeloId(int id, Elemento* novoElemento);
    
};
    


#endif // LISTAORDENADA_H