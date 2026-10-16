//
// Created by yuri on 16/10/2026.
//

#ifndef POO_T2_VETOR_H
#define POO_T2_VETOR_H

class Vetor{
    public:
        int *v = nullptr;
        int tamanho = 0;
        Vetor(int n);
        ~Vetor();
        void aumentarVetor(int n);
};

#endif //POO_T2_VETOR_H
