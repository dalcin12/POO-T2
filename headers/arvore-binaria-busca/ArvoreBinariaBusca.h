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
    public:
        ArvoreBinariaBusca();

        void inserir(int id);
        void buscarPeloId(int id);
        bool removerPeloId(int id);
};

#endif //POO_T2_ARVOREBINARIABUSCA_H
