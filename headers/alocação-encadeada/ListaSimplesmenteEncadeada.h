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
        
        void imprimirLista(No* cabeca);
        bool inserirNoInicio(No* cabeca, int valor);
        bool inserirNoFim(No* cabeca, int valor);
        bool inserirOrdenado(No* cabeca, int valor);
        bool removerInicio(No* cabeca);
        bool removerFim(No* cabeca);
        bool removerPeloId(No* cabeca, int Id);
        No* buscarPeloId(No* cabeca, int Id);
        bool alterarPeloId(No* cabeca, int Id, int novoValor);
        void ambienteTeste(No* cabeca);
        bool estaVazia(No* cabeca) const;
        int obterInicio(No* cabeca) const;
        bool destruirListaSimplesmenteEncadeada(No* cabeca);
    public:
        ListaSimplesmenteEncadeada();
        ~ListaSimplesmenteEncadeada();

        void imprimirLista();
        bool inserirNoInicio(int valor);
        bool inserirNoFim(int valor);
        bool inserirOrdenado(int valor);
        bool removerInicio();
        bool removerFim();
        bool removerPeloId(int Id);
        No* buscarPeloId(int Id);
        bool alterarPeloId(int Id, int novoValor);
        bool estaVazia() const;
        int obterInicio() const;
        void ambienteTeste();
};

#endif // LISTASIMPLESMENTEENCADEADA_H