//
// Created by yuri on 16/10/2026.
//

#ifndef POO_T2_GRAFOS_H
#define POO_T2_GRAFOS_H

#include <iostream>

class Grafo {
private:
    int numVertices;
    int capacidade;
    bool direcionado;

    // 1. Nó para a Lista de Adjacência
    class No {
    public:
        int id;
        No* prox;
        No(int _id, No* _prox = nullptr) : id(_id), prox(_prox) {}
    };

    No** listaAdj;

    // 2. Matriz de Adjacência
    int** matrizAdj;

    // Fila estática/dinâmica manual para a Busca em Largura (sem <queue>)
    class FilaAuxiliar {
    private:
        int* dados;
        int inicio;
        int fim;
    public:
        FilaAuxiliar(int cap) : inicio(0), fim(0) {
            dados = new int[cap];
        }
        ~FilaAuxiliar() {
            delete[] dados;
        }
        void enfileirar(int v) { dados[fim++] = v; }
        int desenfileirar() { return dados[inicio++]; }
        bool estaVazia() const { return inicio == fim; }
    };

    void redimensionar(int novaCapacidade);
    void dfsRecursivo(int v, bool* visitados);

public:
    Grafo(int capInicial = 5, bool eDirecionado = false);
    ~Grafo();

    void adicionarVertice();
    void adicionarAresta(int u, int v);
    bool saoVizinhos(int u, int v);
    int obterGrau(int v);

    void buscaEmLargura(int inicio);      // BFS
    void buscaEmProfundidade(int inicio); // DFS
};

#endif //POO_T2_GRAFOS_H
