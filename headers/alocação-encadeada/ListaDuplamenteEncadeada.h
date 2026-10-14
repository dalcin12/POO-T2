#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

class ListaDuplamenteEncadeada {

    protected:

    private:
        class No {
            public:
                No(int valor);
                int valor;
                No* prox;
                No* ant;
        };
    
    public:
        ListaDuplamenteEncadeada();

        void imprimirLista(No* cabeca);
        bool inserirNoInicio(No* cabeca, int valor);
        bool inserirNoFim(No* cabeca, int valor);
        bool inserirOrdenado(No* cabeca, int valor);
        bool removerInicio(No* cabeca);
        bool removerFim(No* cabeca);
        bool removerPeloId(No* cabeca, int Id);
        No* buscarPeloId(No* cabeca, int Id);
        bool alterarPeloId(No* cabeca, int Id, int novoValor);
        void ambienteTeste();
};


#endif // LISTADUPLAMENTEENCADEADA_H