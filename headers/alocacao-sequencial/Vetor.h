//
// Created by yuri on 16/10/2026.
//

#ifndef POO_T2_VETOR_H
#define POO_T2_VETOR_H

#include "Elemento.h"

class Vetor{
    // antes, sem proteção dos dados, não sei se era de propósito, por isso não tirei. ~Yan
    /*public:
        int *v = nullptr;
        int tamanho = 0;
        Vetor(int n);
        ~Vetor();
        void aumentarVetor(int n);
        */ 
    protected:
        Elemento **v = nullptr;
        int tamanho = 0, quantidade = 0;

    public:
        Vetor(int n);
        ~Vetor();
        void aumentarVetor(int n);
        int BuscarIndice(int id);
    };

#endif //POO_T2_VETOR_H
