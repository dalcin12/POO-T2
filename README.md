# Trabalho 2 - Algoritmos e Estruturas de Dados (POO em C++)
**Universidade do Estado do Rio de Janeiro (UERJ) - Instituto Politécnico (IPRJ)**  
**Curso:** Engenharia da Computação  
**Professor:** Rodrigo Mafort  

---

## 👥 Integrantes do grupo
* Eduarda Pecles Novais
* Gabriel Dalcin da Cunha
* Samuel de Freitas Pinagé
* Yuri Bom Ribeiro
* Yan Bernardo Codesso

---

## 🛠️ Decisões de design e arquitetura do sistema

### 1. Orientação a Objetos e Polimorfismo (Parte I)
* **Classe abstrata `Elemento`:** Definida com o atributo protegido `ID` e o método virtual puro `imprimirInfo() const = 0`. As classes concretas `Funcionario` e `Paciente` herdam de `Elemento`, permitindo que contêineres sequenciais armazenem ponteiros `Elemento*` e executem chamadas polimórficas.
* **Gerenciamento de memória sequencial:** O destrutor da classe base `Vetor` e das listas sequenciais garante a liberação contínua de memória para evitar vazamentos (*memory leaks*).

### 2. Composição para pilhas, filas e deques
* **Pilha e fila sequenciais:** Implementadas utilizando **composição** sobre a `ListaNaoOrdenada`. As operações do ADT (`empilhar`, `desempilhar`, `enfileirar`, `desenfileirar`) reusam a lógica validada da lista subjacente.
* **Fila sequencial circular:** Criada para sanar o gargalo da fila sequencial simples (cuja remoção exige deslocamento O(n)), reduzindo a remoção para O(1) através do uso de ponteiros circulares de início e fim.
* **Pilhas, filas e deques encadeados:** Utilizam composição sobre `ListaSimplesmenteEncadeada` e `ListaDuplamenteEncadeadaCircular`.

### 3. Encapsulamento dos nós (parte II)
* **Encapsulamento restrito:** Nas classes encadeadas, na `ArvoreBinariaBusca` e no `Grafo`, a estrutura do nó (`struct No` / `class No`) foi declarada como **membro privado** das próprias classes contêineres, ocultando totalmente os detalhes de ponteiros do usuário da classe.

### 4. Grafos de representação dupla
* A classe `Grafo` mantém **simultaneamente** a Matriz de Adjacência (`int** matrizAdj`) e a Lista de Adjacência (`No** listaAdj`), combinando a checagem rápida de vizinhança em O(1) com a eficiência de espaço da lista.

---

## 📊 Tabela de complexidade computacional das operações

### Alocação sequencial
| Estrutura | Inserir Início | Inserir Fim | Remover Início | Remover Fim | Buscar por ID | Alterar por ID |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Lista Não Ordenada** | $O(n)$ | $O(1)$ | $O(n)$ | $O(1)$ | $O(n)$ | $O(n)$ |
| **Lista Ordenada** | $O(n)$ | $O(n)$ | $O(n)$ | $O(n)$ | $O(\log_2 n)$ | $O(n)$ |
| **Pilha Sequencial** | - | $O(1)$ | - | $O(1)$ | - | - |
| **Fila Sequencial Simples** | - | $O(1)$ | $O(n)$ | - | - | - |
| **Fila Sequencial Circular** | - | $O(1)$ | $O(1)$ | - | - | - |

### Alocação encadeada e árvores
| Estrutura | Inserir Início | Inserir Fim | Remover Início | Remover Fim | Buscar por ID | Percursos |
| :--- | :---: | :---: | :---: | :---: | :---: | :---: |
| **Lista Simplesmente Encadeada** | $O(1)$ | $O(n)$ | $O(1)$ | $O(n)$ | $O(n)$ | - |
| **Lista Duplamente Encadeada** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ | - |
| **Lista Dupla Circular** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ | $O(n)$ | - |
| **Pilha Encadeada** | $O(1)$ | - | $O(1)$ | - | - | - |
| **Fila Encadeada Circular** | - | $O(1)$ | $O(1)$ | - | - | - |
| **Deque Encadeado Circular** | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$ | - | - |
| **Árvore Binária de Busca (ABB)** | $O(h)$ | - | $O(h)$ | - | $O(h)$ | $O(n)$ |

*Nota: $h$ representa a altura da árvore ($O(\log n)$ no melhor caso/equilibrada e $O(n)$ no pior caso).*

### Grafos
| Operação / Algoritmo | Complexidade de Tempo | Complexidade de Espaço |
| :--- | :---: | :---: |
| **Adicionar Vértice** | $O(V)$ | $O(V^2)$ |
| **Adicionar Aresta** | $O(1)$ | $O(1)$ |
| **Verificar Vizinhos** | $O(1)$ *(via Matriz)* | $O(V^2)$ |
| **Obter Grau** | $O(V)$ | $O(1)$ |
| **Busca em Largura (BFS)** | $O(V + E)$ | $O(V)$ |
| **Busca em Profundidade (DFS)** | $O(V + E)$ | $O(V)$ |

---

## 🚀 Como compilar e executar

Utilizando o compilador `g++`:
```bash
g++ main.cpp sources/alocacao-sequencial/*.cpp sources/alocacao-encadeada/*.cpp sources/arvore-binaria-busca/*.cpp sources/grafos/*.cpp -o programa
./programa