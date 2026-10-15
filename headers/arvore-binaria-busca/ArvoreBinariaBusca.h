//
// Created by yuri on 15/10/2026.
//

#ifndef POO_T2_ARVOREBINARIABUSCA_H
#define POO_T2_ARVOREBINARIABUSCA_H

class ArvoreBinariaBusca {
    private:
        class No{
            public:
                int id;
                No *dir, *esq;
                No(int id);
        };
        No* raiz;

        No* inserir(No* raiz, int id);
        bool buscarPeloId(No* raiz, int id);
        No* removerPeloId(No* raiz, int id);
        No* sucessor(No* atual);
        void imprimir(No* raiz, int escolha);
    public:
        ArvoreBinariaBusca();

        void inserir(int id);
        void buscarPeloId(int id);
        void removerPeloId(int id);
        void emOrdem();
        void preOrdem();
        void posOrdem();
};

#endif //POO_T2_ARVOREBINARIABUSCA_H
