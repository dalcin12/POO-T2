#include <iostream>
#include "headers/alocação-encadeada/ListaSimplesmenteEncadeada.h"
#include "headers/alocação-encadeada/ListaDuplamenteEncadeada.h"
#include "headers/arvore-binaria-busca/ArvoreBinariaBusca.h"


using namespace std;

int main(void) {

    ListaSimplesmenteEncadeada lista;
    ListaDuplamenteEncadeada listaDupla;
    cout << "Executando ambiente de teste da lista simplesmente encadeada..." << endl;
    lista.ambienteTeste();

    cout << "Executando ambiente de teste da lista duplamente encadeada..." << endl;
    listaDupla.ambienteTeste();


    ArvoreBinariaBusca ABB = ArvoreBinariaBusca();
    ABB.inserir(5);
    ABB.inserir(3);
    ABB.inserir(4);
    ABB.inserir(2);
    ABB.inserir(7);
    ABB.inserir(6);
    ABB.inserir(8);

    ABB.preOrdem();
    std::cout << "================" << std::endl;

    ABB.removerPeloId(4);

    ABB.emOrdem();
    return 1;
}