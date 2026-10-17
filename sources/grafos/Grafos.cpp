//
// Created by yuri on 16/10/2026.
//
#include "../../headers/grafos/Grafos.h"

Grafo::Vertice::Vertice(int _id, Vertice* _prox){
    this->id = _id;
    this->prox = _prox;
}

void Grafo::definirNumVertices(int _numVertices){
    this->numVertices = _numVertices;
}

void Grafo::criarGrafo(){
    this->listaAdj = new Vertice[this->numVertices];
    for (int i = 0; i < this->numVertices; i++){
        this->listaAdj[i].id = i;
        this->listaAdj[i].prox = nullptr;
    }
}

void Grafo::adicionarAdjacencia(int** _arestas, int numArestas){
    for (int i = 0; i < numArestas; i++){
        int u = _arestas[i][0];
        int v = _arestas[i][1];
        Vertice* aux = &this->listaAdj[u];
        //PARA INSERIR AO FINAL DA LISTA
        while (aux->prox != nullptr){
            aux = aux->prox;
        }
        aux->prox = new Vertice(v, nullptr);
    }
}