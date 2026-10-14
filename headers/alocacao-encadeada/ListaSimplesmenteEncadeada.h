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

    public:
        ListaSimplesmenteEncadeada();
        
        bool inserirNoInicio(No* cabeca, int valor);
        bool inserirNoFim(No* cabeca, int valor);
        bool inserirOrdenado(No* cabeca, int valor);
        bool removerInicio(No* cabeca);
        bool removerFim(No* cabeca);
        bool removerPeloId(No* cabeca, int Id);
        No* buscarPeloId(No* cabeca, int Id);
        bool alterarPeloId(No* cabeca, int Id, int novoValor);

};

#endif // LISTASIMPLESMENTEENCADEADA_H