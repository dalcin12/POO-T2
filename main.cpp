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
    // Os primeiros testes usam listas sequenciais e objetos derivados de Elemento.
    cout << "===================================================\n";
    cout << " PARTE I: ALOCACAO SEQUENCIAL E POLIMORFISMO\n";
    cout << "===================================================\n\n";

    // Cada classe imprime seus dados pelo mesmo ponteiro da classe base.
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

    // A chamada varia conforme o tipo real de cada elemento.
    cout << "\nInvocando imprimirInfo() para cada objeto da lista heterogenea:\n";
    for (int i = 0; i < listaSeq.getQuantidade(); i++) {
        cout << "\nElemento na posicao " << i << ":\n";
        listaSeq.getElemento(i)->imprimirInfo();
    }

    cout << "\n--- Teste da Lista Ordenada Sequencial (Busca Binaria) ---\n";
    ListaOrdenada listaOrd(5);

    // Os elementos sao inseridos fora de ordem; a lista os organiza pelo ID.
    data_de_nascimento data3 = {5, 11, 1995};

    listaOrd.Inserir(new Funcionario(30, "Alice", 25, 3000.0f, 40));
    listaOrd.Inserir(new Paciente(10, "Bruno", 40, "Hapvida", data3));
    listaOrd.Inserir(new Funcionario(20, "Carla", 30, 3500.0f, 40));

    // Confere a busca binaria por um elemento que esta no meio da lista.
    Elemento* enc = listaOrd.BuscarPeloId(20);
    if (enc != nullptr) {
        cout << "\nElemento com ID 20 encontrado na Lista Ordenada via Busca Binaria:\n";
        enc->imprimirInfo();
    }

    // A segunda parte percorre estruturas encadeadas, arvore e grafo.
    cout << "\n===================================================\n";
    cout << " PARTE II: ALOCACAO ENCADEADA, ARVORE E GRAFO\n";
    cout << "===================================================\n\n";

    cout << "--- Teste de Listas Encadeadas ---\n";
    ListaSimplesmenteEncadeada listaSimples;
    // A sequencia mostra insercoes nas tres posicoes disponiveis.
    listaSimples.inserirNoInicio(10);
    listaSimples.inserirNoFim(20);
    listaSimples.inserirOrdenado(15);
    cout << "\nLista simplesmente encadeada apos insercoes: ";
    listaSimples.imprimirLista();

    // Remove pelos extremos e, em seguida, por valor.
    listaSimples.removerInicio();
    cout << "Apos remover do inicio: ";
    listaSimples.imprimirLista();

    listaSimples.removerFim();
    cout << "Apos remover do fim: ";
    listaSimples.imprimirLista();

    listaSimples.removerPeloId(15);
    cout << "Apos remover pelo ID 15: ";
    listaSimples.imprimirLista();

    // O valor inserido no inicio e alterado pela busca do seu valor atual.
    listaSimples.inserirNoInicio(30);
    listaSimples.alterarPeloId(30, 35);
    cout << "Apos alterar o valor do ID 30 para 35: ";
    listaSimples.imprimirLista();

    ListaDuplamenteEncadeada listaDupla;
    listaDupla.inserirNoInicio(10);
    listaDupla.inserirNoFim(20);
    listaDupla.inserirOrdenado(15);
    cout << "\nLista duplamente encadeada apos insercoes: ";
    listaDupla.imprimirLista();

    // Repete as operacoes para conferir a conexao nos dois sentidos.
    listaDupla.removerInicio();
    cout << "Apos remover do inicio: ";
    listaDupla.imprimirLista();

    listaDupla.removerFim();
    cout << "Apos remover do fim: ";
    listaDupla.imprimirLista();

    listaDupla.removerPeloId(15);
    cout << "Apos remover pelo ID 15: ";
    listaDupla.imprimirLista();

    listaDupla.inserirNoInicio(30);
    listaDupla.alterarPeloId(30, 35);
    cout << "Apos alterar o valor do ID 30 para 35: ";
    listaDupla.imprimirLista();

    ListaDuplamenteEncadeadaCircular listaCircular;
    listaCircular.inserirNoInicio(10);
    listaCircular.inserirNoFim(20);
    listaCircular.inserirOrdenado(15);
    cout << "\nLista duplamente encadeada circular apos insercoes: ";
    listaCircular.imprimirLista();

    // Na lista circular, as remocoes tambem precisam manter as conexoes circulares.
    listaCircular.removerInicio();
    cout << "Apos remover do inicio: ";
    listaCircular.imprimirLista();

    listaCircular.removerFim();
    cout << "Apos remover do fim: ";
    listaCircular.imprimirLista();

    listaCircular.removerPeloId(15);
    cout << "Apos remover pelo ID 15: ";
    listaCircular.imprimirLista();

    listaCircular.inserirNoInicio(30);
    listaCircular.alterarPeloId(30, 35);
    cout << "Apos alterar o valor do ID 30 para 35: ";
    listaCircular.imprimirLista();

    cout << "\n--- Teste da Pilha sobre Lista Simplesmente Encadeada (LIFO) ---\n";
    PilhaListaSimplesmenteEncadeada pilha;
    int topo = 0;

    // Empilhar adiciona no topo; desempilhar retira sempre o ultimo valor inserido.
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
    // A ultima tentativa verifica o retorno quando nao ha mais elementos.
    cout << "Pilha vazia apos desempilhar tudo? " << (pilha.pilhaVazia() ? "sim" : "nao") << "\n";
    cout << "Tentando desempilhar com a pilha vazia:\n";
    bool desempilhou = pilha.desempilhar();
    cout << "Retorno: " << (desempilhou ? "true" : "false") << "\n";

    cout << "\n--- Teste da Fila sobre Lista Duplamente Encadeada Circular (FIFO) ---\n";
    FilaEncadeadaCircular fila;
    int inicioFila = 0;

    // Os valores saem na mesma ordem em que foram enfileirados.
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
    // Tambem confere a resposta ao tentar remover de uma fila vazia.
    cout << "Fila vazia apos desenfileirar tudo? " << (fila.filaVazia() ? "sim" : "nao") << "\n";
    cout << "Tentando desenfileirar com a fila vazia:\n";
    bool desenfileirou = fila.desenfileirar();
    cout << "Retorno: " << (desenfileirou ? "true" : "false") << "\n";

    cout << "\n--- Teste do Deque sobre Lista Duplamente Encadeada Circular ---\n";
    DequeListaEncadeadaCircular deque;
    int inicioDeque = 0, fimDeque = 0;

    // O deque permite inserir e remover tanto no inicio quanto no fim.
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
    // A arvore recebe valores em ambos os lados da raiz para os percursos.
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

    // O percurso pos-ordem permite observar a arvore depois da remocao.
    cout << "Percurso Pos-Ordem apos remocao:\n";
    abb.posOrdem();

    cout << "\n--- Teste de Grafos (Matriz + Lista de Adjacencia) ---\n";
    Grafo g(4, true);
    // Cria quatro vertices e liga o vertice 0 aos outros tres.
    for (int i = 0; i < 4; i++) {
        g.adicionarVertice();
    }
    g.adicionarAresta(0, 3);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(0, 1);

    // As duas buscas partem do mesmo vertice para comparar os percursos.
    cout << "Busca em Profundidade (DFS) a partir do vertice 0:\n";
    g.buscaEmProfundidade(0);

    cout << "\nBusca em Largura (BFS) a partir do vertice 0:\n";
    g.buscaEmLargura(0);

    cout << "\n===================================================\n";
    cout << " TODOS OS TESTES CONCLUIDOS COM SUCESSO!\n";
    cout << "===================================================\n";

    return 0;
}