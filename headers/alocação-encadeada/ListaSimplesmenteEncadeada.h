#ifndef LISTASIMPLESMENTEENCADEADA_H
#define LISTASIMPLESMENTEENCADEADA_H

class ListaSimplesmenteEncadeada {

    protected:

    private:
        class No {
            public:
                No(int valor);
                int valor;
                No* prox;
        };

        No* cabeca;
        
    public:
        ListaSimplesmenteEncadeada();
        
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

#endif // LISTASIMPLESMENTEENCADEADA_H