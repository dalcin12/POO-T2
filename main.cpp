#include <iostream>
#include "headers/alocacao-sequencial/Elemento.h"
#include "headers/alocacao-sequencial/Funcionario.h"
#include "headers/alocacao-sequencial/Paciente.h"
#include "headers/alocacao-sequencial/ListaNaoOrdenada.h"
#include "headers/alocacao-sequencial/ListaOrdenada.h"
#include "headers/alocacao-sequencial/PilhaListaSequencial.h"
#include "headers/alocacao-sequencial/FilaListaSequencial.h"
#include "headers/alocacao-sequencial/FilaSequencialCircular.h"

#include "headers/alocacao-encadeada/ListaSimplesmenteEncadeada.h"
#include "headers/alocacao-encadeada/ListaDuplamenteEncadeada.h"
#include "headers/alocacao-encadeada/ListaDuplamenteEncadeadaCircular.h"
#include "headers/alocacao-encadeada/PilhaListaEncadeada.h"
#include "headers/alocacao-encadeada/FilaListaEncadeada.h"
#include "headers/alocacao-encadeada/DequeListaEncadeada.h"

#include "headers/arvore-binaria-busca/ArvoreBinariaBusca.h"
#include "headers/grafos/Grafos.h"

using namespace std;

int main() {
    cout << "===================================================\n";
    cout << " PARTE I: ALOCACAO SEQUENCIAL E POLIMORFISMO\n";
    cout << "===================================================\n\n";

    // Criacao de objetos heterogeneos derivados de Elemento

    data_de_nascimento data1 = {15, 3, 1990};
    data_de_nascimento data2 = {22, 7, 1985};

    Elemento* f1 = new Funcionario(105, "Carlos Silva", 35, 4500.0f, 40);
    Elemento* p1 = new Paciente(102, "Ana Souza", 28, "Unimed", data1);
    Elemento* f2 = new Funcionario(108, "Mariana Lima", 29, 5200.0f, 44);
    Elemento* p2 = new Paciente(101, "Joao Mendes", 62, "Amil", data2);

    cout << "--- Teste de Polimorfismo na Lista Nao Ordenada ---\n";
    ListaNaoOrdenada listaSeq(5);
    listaSeq.InserirNoFinal(f1);
    listaSeq.InserirNoFinal(p1);
    listaSeq.InserirNoFinal(f2);
    listaSeq.InserirNoFinal(p2);

    // Percorrendo a lista e invocando imprimirInfo() polimorficamente
    cout << "\nInvocando imprimirInfo() para cada objeto da lista heterogenea:\n";
    for (int i = 0; i < listaSeq.getQuantidade(); i++) {
        cout << "\n[Elemento " << i + 1 << "]:\n";
        listaSeq.getElemento(i)->imprimirInfo();
    }

    cout << "\n--- Teste da Lista Ordenada Sequencial (Busca Binaria) ---\n";
    ListaOrdenada listaOrd(5);

    data_de_nascimento data3 = {5, 11, 1995};

    listaOrd.Inserir(new Funcionario(30, "Alice", 25, 3000.0f, 40));
    listaOrd.Inserir(new Paciente(10, "Bruno", 40, "Hapvida", data3));
    listaOrd.Inserir(new Funcionario(20, "Carla", 30, 3500.0f, 40));

    Elemento* enc = listaOrd.BuscarPeloId(20);
    if (enc != nullptr) {
        cout << "\nElemento com ID 20 encontrado na Lista Ordenada via Busca Binaria:\n";
        enc->imprimirInfo();
    }

    cout << "\n===================================================\n";
    cout << " PARTE II: ALOCACAO ENCADEADA, ARVORE E GRAFO\n";
    cout << "===================================================\n\n";

    cout << "--- Teste de Listas Encadeadas ---\n";
    ListaSimplesmenteEncadeada listaSimples;
    listaSimples.ambienteTeste();

    ListaDuplamenteEncadeada listaDupla;
    listaDupla.ambienteTeste();

    ListaDuplamenteEncadeadaCircular listaCircular;
    listaCircular.ambienteTeste();

    cout << "\n--- Teste da Pilha sobre Lista Simplesmente Encadeada (LIFO) ---\n";
    PilhaListaSimplesmenteEncadeada pilha;
    int topo = 0;

    cout << "Pilha vazia? " << (pilha.pilhaVazia() ? "sim" : "nao") << "\n";
    pilha.empilhar(7);
    pilha.empilhar(12);
    pilha.empilhar(23);
    cout << "Apos empilhar 7, 12 e 23 (topo a esquerda): ";
    pilha.imprimirPilha();

    if (pilha.topoPilha(topo)) {
        cout << "Topo da pilha: " << topo << "\n";
    }

    pilha.desempilhar();
    cout << "Apos desempilhar uma vez: ";
    pilha.imprimirPilha();

    pilha.desempilhar();
    pilha.desempilhar();
    cout << "Pilha vazia apos desempilhar tudo? " << (pilha.pilhaVazia() ? "sim" : "nao") << "\n";
    cout << "Tentando desempilhar com a pilha vazia:\n";
    bool desempilhou = pilha.desempilhar();
    cout << "Retorno: " << (desempilhou ? "true" : "false") << "\n";

    cout << "\n--- Teste da Fila sobre Lista Duplamente Encadeada Circular (FIFO) ---\n";
    FilaEncadeadaCircular fila;
    int inicioFila = 0;

    cout << "Fila vazia? " << (fila.filaVazia() ? "sim" : "nao") << "\n";
    fila.enfileirar(1);
    fila.enfileirar(2);
    fila.enfileirar(3);
    cout << "Apos enfileirar 1, 2 e 3 (inicio a esquerda): ";
    fila.imprimirFila();

    if (fila.consultarInicio(inicioFila)) {
        cout << "Inicio da fila: " << inicioFila << "\n";
    }

    fila.desenfileirar();
    cout << "Apos desenfileirar uma vez: ";
    fila.imprimirFila();

    fila.desenfileirar();
    fila.desenfileirar();
    cout << "Fila vazia apos desenfileirar tudo? " << (fila.filaVazia() ? "sim" : "nao") << "\n";
    cout << "Tentando desenfileirar com a fila vazia:\n";
    bool desenfileirou = fila.desenfileirar();
    cout << "Retorno: " << (desenfileirou ? "true" : "false") << "\n";

    cout << "\n--- Teste do Deque sobre Lista Duplamente Encadeada Circular ---\n";
    DequeListaEncadeadaCircular deque;
    int inicioDeque = 0, fimDeque = 0;

    deque.inserirFim(2);
    deque.inserirInicio(1);
    deque.inserirFim(3);
    deque.inserirInicio(0);
    cout << "Apos inserirFim(2), inserirInicio(1), inserirFim(3), inserirInicio(0): ";
    deque.imprimirDeque();

    if (deque.consultarInicio(inicioDeque) && deque.consultarFim(fimDeque)) {
        cout << "Inicio do deque: " << inicioDeque << " | Fim do deque: " << fimDeque << "\n";
    }

    deque.removerInicio();
    cout << "Apos removerInicio: ";
    deque.imprimirDeque();

    deque.removerFim();
    cout << "Apos removerFim: ";
    deque.imprimirDeque();

    cout << "\n--- Teste da Arvore Binaria de Busca (ABB) ---\n";
    ArvoreBinariaBusca abb;
    abb.inserir(5);
    abb.inserir(3);
    abb.inserir(4);
    abb.inserir(2);
    abb.inserir(7);
    abb.inserir(6);
    abb.inserir(8);

    cout << "Percurso Pre-Ordem:\n";
    abb.preOrdem();

    cout << "\nRemovendo ID 5 da ABB...\n";
    abb.removerPeloId(5);

    cout << "Percurso Pos-Ordem apos remocao:\n";
    abb.posOrdem();

    cout << "\n--- Teste de Grafos (Matriz + Lista de Adjacencia) ---\n";
    Grafo g(4, true);
    for (int i = 0; i < 4; i++) {
        g.adicionarVertice();
    }
    g.adicionarAresta(0, 3);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(0, 1);

    cout << "Busca em Profundidade (DFS) a partir do vertice 0:\n";
    g.buscaEmProfundidade(0);

    cout << "\nBusca em Largura (BFS) a partir do vertice 0:\n";
    g.buscaEmLargura(0);

    cout << "\n===================================================\n";
    cout << " TODOS OS TESTES CONCLUIDOS COM SUCESSO!\n";
    cout << "===================================================\n";

    return 0;
}