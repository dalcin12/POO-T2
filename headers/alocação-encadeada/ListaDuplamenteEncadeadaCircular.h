#ifndef LISTADUPLAMENTEENCADEADACIRCULAR_H
#define LISTADUPLAMENTEENCADEADACIRCULAR_H

class ListaDuplamenteEncadeadaCircular {
    private:
        class No {
            public:
                No(int valor);
                
                int valor;
                No* prox;
                No* ant;
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
        bool destruirListaDuplamenteEncadeadaCircular(No* cabeca);
    public:
        ListaDuplamenteEncadeadaCircular();
        ~ListaDuplamenteEncadeadaCircular();

        void imprimirLista();
        bool inserirNoInicio(int valor);
        bool inserirNoFim(int valor);
        bool inserirOrdenado(int valor);
        bool removerInicio();
        bool removerFim();
        bool removerPeloId(int Id);
        No* buscarPeloId(int Id);
        bool alterarPeloId(int Id, int novoValor);
        void ambienteTeste();
};

#endif // LISTADUPLAMENTEENCADEADACIRCULAR_H