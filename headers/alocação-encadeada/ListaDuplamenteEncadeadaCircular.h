#ifndef LISTADUPLAMENTEENCADEADACIRCULAR_H
#define LISTADUPLAMENTEENCADEADACIRCULAR_H

class ListaDuplamenteEncadeadaCircular {
    private:
        // Criacao do No como uma classe privada.
        class No {
            public:
                No(int valor);
                
                int valor;
                No* prox;
                No* ant;
        };

        // Criacao do cabeca como privado para mais seguranca.
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

        // Metodos auxiliares para implementacao da fila.
        bool estaVazia(No* cabeca) const;
        int obterInicio(No* cabeca) const;
        int obterFim(No* cabeca) const;

        // Metodo para liberar memoria da lista.
        bool destruirListaDuplamenteEncadeadaCircular(No* cabeca);

    public:
        ListaDuplamenteEncadeadaCircular();
        ~ListaDuplamenteEncadeadaCircular();

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

        // Metodos publicos da fila.
        bool estaVazia() const;
        int obterInicio() const;
        int obterFim() const;
};

#endif // LISTADUPLAMENTEENCADEADACIRCULAR_H