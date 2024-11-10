/*
 * Tarefa 02 - Alteracoes de Transito
 *
 * GEN254 - Grafos - 2024/2
 *
 * Nome:      Marco Antonio Duz
 * Matricula: 2311100006
 *
 * Nome:      Wendell Luis Neris
 * Matricula: 2311100035
 */

#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <vector>
#include "Aresta.h"
#include <stack>

class Digrafo
{
public:
    // funções principais do grafo
    Digrafo(int num_vertices);
    bool verticeValido(int v);
    bool existeAresta(Aresta e);
    void createAresta(Aresta e);
    void removeAresta(Aresta e);
    void digrafoImprime();

    // get and set
    int get_num_vertices();
    std::vector<std::vector<int>> get_matriz();
    void setValorMatriz(int i, int j, int valor);
    void setTamanhoMatriz(int tam);

    // função kosaraju e sesus auxiliares, que encontra as componentes fortemente conexas
    int Kosaraju(std::vector<int> &componente);
    void DFS(int v, std::vector<bool> &visitado, std::stack<int> &pilha);
    void DFSUtil(int v, std::vector<bool> &visitado, int qtdComponentes, std::vector<int> &componente);

    // função que cria um grafo que representa as componentes fortemente conexas
    void criaGrafoCondensado(int numCFCs, Digrafo &condensado, Digrafo &g, std::vector<int> &componente);
    void mostraConexoesEntreCFCs(Digrafo &condensado);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_;
};

Digrafo getTransposto(Digrafo &g);

#endif // DIGRAFO_H
