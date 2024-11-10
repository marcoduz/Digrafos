#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <vector>
#include "Aresta.h"
#include <stack>

class Digrafo
{
public:
    Digrafo(int num_vertices);
    int get_num_vertices();
    std::vector<std::vector<int>> get_matriz();
    void setValorMatriz(int i, int j, int valor);
    bool verticeValido(int v);
    bool existeAresta(Aresta e);
    void createAresta(Aresta e);
    void removeAresta(Aresta e);
    void digrafoImprime();
    int Kosaraju(std::vector<int> &componente);
    void DFS(int v, std::vector<bool> &visitado, std::stack<int> &pilha);
    void DFSUtil(int v, std::vector<bool> &visitado, int qtdComponentes, std::vector<int> &componente);
    void criaGrafoCondensado(int numCFCs, Digrafo &condensado, Digrafo &g, std::vector<int> &componente);
    void mostraConexoesEntreCFCs(Digrafo &condensado);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_;
};

Digrafo getTransposto(Digrafo &g);

#endif // DIGRAFO_H
