#include "../../headers/grafos/Grafos.h"

// Cria as estruturas que guardam os vizinhos de cada vertice.
Grafo::Grafo(int capInicial, bool eDirecionado) {
    this->numVertices = 0;
    this->capacidade = capInicial;
    this->direcionado = eDirecionado;

    // Alocação da Lista de Adjacência
    this->listaAdj = new No*[this->capacidade];
    for (int i = 0; i < this->capacidade; i++) {
        this->listaAdj[i] = nullptr;
    }

    // Alocação da Matriz de Adjacência
    this->matrizAdj = new int*[this->capacidade];
    for (int i = 0; i < this->capacidade; i++) {
        this->matrizAdj[i] = new int[this->capacidade]();
    }
}

// Libera os nos das listas e as linhas da matriz.
Grafo::~Grafo() {
    // Liberta a Lista de Adjacência
    for (int i = 0; i < this->capacidade; i++) {
        No* atual = this->listaAdj[i];
        while (atual != nullptr) {
            No* temp = atual;
            atual = atual->prox;
            delete temp;
        }
    }
    delete[] this->listaAdj;

    // Liberta a Matriz de Adjacência
    for (int i = 0; i < this->capacidade; i++) {
        delete[] this->matrizAdj[i];
    }
    delete[] this->matrizAdj;
}

// Aumenta as duas estruturas sem perder os vertices e arestas existentes.
void Grafo::redimensionar(int novaCapacidade) {
    // Redimensionamento manual da Lista de Adjacência
    No** novaLista = new No*[novaCapacidade];
    for (int i = 0; i < novaCapacidade; i++) {
        novaLista[i] = (i < this->numVertices) ? this->listaAdj[i] : nullptr;
    }
    delete[] this->listaAdj;
    this->listaAdj = novaLista;

    // Redimensionamento manual da Matriz de Adjacência
    int** novaMatriz = new int*[novaCapacidade];
    for (int i = 0; i < novaCapacidade; i++) {
        novaMatriz[i] = new int[novaCapacidade]();
        for (int j = 0; j < novaCapacidade; j++) {
            if (i < this->numVertices && j < this->numVertices) {
                novaMatriz[i][j] = this->matrizAdj[i][j];
            }
        }
    }
    for (int i = 0; i < this->capacidade; i++) {
        delete[] this->matrizAdj[i];
    }
    delete[] this->matrizAdj;
    this->matrizAdj = novaMatriz;

    this->capacidade = novaCapacidade;
}

// Adiciona um vertice e aumenta a capacidade quando necessario.
void Grafo::adicionarVertice() {
    if (this->numVertices >= this->capacidade) {
        redimensionar(this->capacidade * 2);
    }
    this->numVertices++;
}

// Registra a aresta na matriz e na lista de adjacencia.
void Grafo::adicionarAresta(int u, int v) {
    if (u < 0 || u >= this->numVertices || v < 0 || v >= this->numVertices) {
        std::cout << "Erro: Vertice invalido!\n";
        return;
    }

    // Registra a aresta na matriz.
    this->matrizAdj[u][v] = 1;
    if (!this->direcionado) {
        this->matrizAdj[v][u] = 1;
    }

    // Registra o destino na lista do vertice de origem.
    this->listaAdj[u] = new No(v, this->listaAdj[u]);
    if (!this->direcionado) {
        this->listaAdj[v] = new No(u, this->listaAdj[v]);
    }
}

// Consulta a matriz para verificar se existe uma aresta entre os vertices.
bool Grafo::saoVizinhos(int u, int v) {
    if (u < 0 || u >= this->numVertices || v < 0 || v >= this->numVertices) {
        return false;
    }
    return this->matrizAdj[u][v] != 0;
}

// Conta os vizinhos registrados na lista do vertice.
int Grafo::obterGrau(int v) {
    if (v < 0 || v >= this->numVertices) return -1;

    int grau = 0;
    No* atual = this->listaAdj[v];
    while (atual != nullptr) {
        grau++;
        atual = atual->prox;
    }
    return grau;
}

// Visita primeiro os vizinhos mais proximos usando uma fila.
void Grafo::buscaEmLargura(int inicio) {
    if (inicio < 0 || inicio >= this->numVertices) return;

    bool* visitados = new bool[this->numVertices]();
    FilaAuxiliar fila(this->numVertices);

    visitados[inicio] = true;
    fila.enfileirar(inicio);

    std::cout << "BFS a partir do vertice " << inicio << ": ";

    while (!fila.estaVazia()) {
        int v = fila.desenfileirar();
        std::cout << v << " ";

        No* vizinho = this->listaAdj[v];
        while (vizinho != nullptr) {
            if (!visitados[vizinho->id]) {
                visitados[vizinho->id] = true;
                fila.enfileirar(vizinho->id);
            }
            vizinho = vizinho->prox;
        }
    }
    std::cout << std::endl;
    delete[] visitados;
}

// Visita um vertice e segue por cada vizinho ainda nao visitado.
void Grafo::dfsRecursivo(int v, bool* visitados) {
    visitados[v] = true;
    std::cout << v << " ";

    No* vizinho = this->listaAdj[v];
    while (vizinho != nullptr) {
        if (!visitados[vizinho->id]) {
            dfsRecursivo(vizinho->id, visitados);
        }
        vizinho = vizinho->prox;
    }
}

// Inicia a busca em profundidade no vertice informado.
void Grafo::buscaEmProfundidade(int inicio) {
    if (inicio < 0 || inicio >= this->numVertices) return;

    bool* visitados = new bool[this->numVertices]();

    std::cout << "DFS a partir do vertice " << inicio << ": ";
    dfsRecursivo(inicio, visitados);
    std::cout << std::endl;

    delete[] visitados;
}