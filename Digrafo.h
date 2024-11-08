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


class Digrafo {
    public:
        Digrafo(int num_vertices);

        bool existeAresta(Aresta e);
        void createAresta(Aresta e);
        void removeAresta(Aresta e);
        bool verticeValido(int v);
        void digrafoImprime();
        void Kosaraju(Digrafo &g);
        void DFS(Digrafo &g, int v, vector<bool> &visitado, stack<int> &pilha);
        void DFSUtil(Digrafo &g, int v, vector<bool> &visitado);

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_;
};

#endif /* DIGRAFO_H */