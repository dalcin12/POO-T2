#ifndef LISTADUPLAMENTEENCADEADA_H
#define LISTADUPLAMENTEENCADEADA_H

class ListaDuplamenteEncadeada {

    protected:

    private:
        // Criacao do No como uma classe privada.
        class No {
            public:
                No(int valor);
                int valor;
                No* prox;
                No* ant;
        };

        // Criacao do cabeca como um No privado para mais seguranca.
        No* cabeca;

        // Metodos da lista.
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
        bool destruirListaDuplamenteEncadeada(No* cabeca);
    
    public:
        ListaDuplamenteEncadeada();
        ~ListaDuplamenteEncadeada();

        // Metodos publicos da lista.
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


#endif // LISTADUPLAMENTEENCADEADA_H