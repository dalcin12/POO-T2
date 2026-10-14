#include <iostream>
#include "headers/alocação-encadeada/ListaSimplesmenteEncadeada.h"
#include "headers/alocação-encadeada/ListaDuplamenteEncadeada.h"

using namespace std;

int main(void) {
    ListaSimplesmenteEncadeada lista;
    ListaDuplamenteEncadeada listaDupla;
    cout << "Executando ambiente de teste da lista simplesmente encadeada..." << endl;
    lista.ambienteTeste();

    cout << "Executando ambiente de teste da lista duplamente encadeada..." << endl;
    listaDupla.ambienteTeste();

    return 1;
}