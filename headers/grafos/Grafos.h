//
// Created by yuri on 16/10/2026.
//

#ifndef POO_T2_GRAFOS_H
#define POO_T2_GRAFOS_H

#include "../../headers/alocação-sequencial/Vetor.h"
#include "../../headers/alocação-encadeada/ListaSimplesmenteEncadeada.h"

class Grafo{
    private:
        int numVertices;
        int numArestas;

        class Vertice{
            public:
                int id;
                Vertice* prox;
                Vertice(): id(-1), prox(nullptr){}
                Vertice(int _id, Vertice* _prox);
        };
        Vertice* listaAdj = nullptr;
    public:
        void definirNumVertices(int _numVertices);
        void criarGrafo();
        void adicionarAdjacencia(int** _arestas);
};

#endif //POO_T2_GRAFOS_H
