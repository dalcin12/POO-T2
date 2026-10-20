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
    Elemento* f1 = new Funcionario(105, "Carlos Silva", 35, 4500.0f, 40);
    Elemento* p1 = new Paciente(102, "Ana Souza", 28, "Hipertensao", "Dra. Beatriz");
    Elemento* f2 = new Funcionario(108, "Mariana Lima", 29, 5200.0f, 44);
    Elemento* p2 = new Paciente(101, "Joao Mendes", 62, "Diabetes Tipo 2", "Dr. Roberto");

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
    listaOrd.InserirNoFinal(new Funcionario(30, "Alice", 25, 3000.0f, 40));
    listaOrd.InserirNoFinal(new Paciente(10, "Bruno", 40, "Gripe", "Dr. Clinico"));
    listaOrd.InserirNoFinal(new Funcionario(20, "Carla", 30, 3500.0f, 40));

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