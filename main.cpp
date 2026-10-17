#include <iostream>
#include "headers/alocação-encadeada/ListaSimplesmenteEncadeada.h"
#include "headers/alocação-encadeada/ListaDuplamenteEncadeada.h"
#include "headers/alocação-encadeada/ListaDuplamenteEncadeadaCircular.h"
#include "headers/alocação-sequencial/Vetor.h"
#include "headers/arvore-binaria-busca/ArvoreBinariaBusca.h"

using namespace std;

int main(void) {

    ListaSimplesmenteEncadeada lista = ListaSimplesmenteEncadeada();
    ListaDuplamenteEncadeada listaDupla = ListaDuplamenteEncadeada();
    ListaDuplamenteEncadeadaCircular listaDuplaCircular = ListaDuplamenteEncadeadaCircular();

    cout << "Executando ambiente de teste da lista simplesmente encadeada...\n" << endl;
    lista.ambienteTeste();

    cout << "\nExecutando ambiente de teste da lista duplamente encadeada...\n" << endl;
    listaDupla.ambienteTeste();

    cout << "\nExecutando ambiente de teste da lista duplamente encadeada circular...\n" << endl;
    listaDuplaCircular.ambienteTeste();

    ArvoreBinariaBusca ABB = ArvoreBinariaBusca();
    ABB.inserir(5);
    ABB.inserir(3);
    ABB.inserir(4);
    ABB.inserir(2);
    ABB.inserir(7);
    ABB.inserir(6);
    ABB.inserir(8);

    ABB.preOrdem();
    std::cout << "\n================\n" << std::endl;

    ABB.removerPeloId(5);

    ABB.posOrdem();
    return 1;
}