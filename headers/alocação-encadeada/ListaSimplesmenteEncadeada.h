#ifndef LISTASIMPLESMENTEENCADEADA_H
#define LISTASIMPLESMENTEENCADEADA_H

class ListaSimplesmenteEncadeada {

    private:
        // Criacao do no da lista como classe privada.
        class No {
            public:
                No(int valor);
                int valor;
                No* prox;
        };
        
        // No cabeca criado como privado para mais seguranca.
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

        // Metodos auxiliares para implementacao da pilha.
        bool estaVazia(No* cabeca) const;
        int obterInicio(No* cabeca) const;

        // Metodo para liberar memoria.
        bool destruirListaSimplesmenteEncadeada(No* cabeca);

    public:
        ListaSimplesmenteEncadeada();
        ~ListaSimplesmenteEncadeada();

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

        // Metodos publicos da pilha
        bool estaVazia() const;
        int obterInicio() const;
        void ambienteTeste();
};

#endif // LISTASIMPLESMENTEENCADEADA_H