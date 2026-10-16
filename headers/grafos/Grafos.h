//
// Created by yuri on 16/10/2026.
//

#ifndef POO_T2_GRAFOS_H
#define POO_T2_GRAFOS_H

#include <vector>
#include "../../headers/alocação-encadeada/ListaSimplesmenteEncadeada.h"

class Grafo{
    private:
        int numVertices;
        class Vertice{
            public:
                int id;
                ListaSimplesmenteEncadeada arestas;
                Vertice(int id, std::vector<int> _arestas);
        };
        std::vector<Vertice> listaAdj;
    public:
        void definirNumVertices(int _numVertices);
        void criarGrafo(std::vector<std::vector<int>> _arestas);
};

#endif //POO_T2_GRAFOS_H
