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

#include "Digrafo.h"
#include "Aresta.cpp"
#include <iostream>
#include <vector>
using namespace std;

Digrafo::Digrafo(int num_vertices)
{
    if (num_vertices <= 0)
    {
        throw(invalid_argument("O numero de vertices deve ser maior que 0"));
    }
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_.resize(num_vertices); // define a quantidade de linhas
    for (int i = 0; i < num_vertices; i++)
    {
        matriz_[i].resize(num_vertices, 0); // define a quantidade de colunas, e o valor a ser inserido
    }
}
bool Digrafo::verticeValido(int v)
{
    if (v < 0 || v >= num_vertices_)
    {
        return false;
    }
    return true;
}

    bool Digrafo::existeAresta(Aresta e)
{
    if (matriz_[e.v1][e.v2] == 1)
    {
        return true;
    }
        return false;
}
void Digrafo::createAresta(Aresta e)
{
    if(!verticeValido(e.v1) && !verticeValido(e.v2)){
        
        return;
    }

    if ((e.v1 != e.v2) && !existeAresta(e))
    {
        matriz_[e.v1][e.v2] = 1;
    }
    
}
void Digrafo::removeAresta(Aresta e)
{
    matriz_[e.v1][e.v2] = 0;
}

void Digrafo::digrafoImprime(){
    for (int i=0; i < num_vertices_; i++){
    cout << "\n";
        for(int j = 0; j < num_vertices_; j++){
            cout << matriz_[i][j];
        }
    }
}

// Função de DFS
void DFS(Digrafo &g, int v, vector<bool> &visitado, stack<int> &pilha) {
    visitado[v] = true;
    for (int i = 0; i < g.num_vertices_; i++) {
        if (g.matriz_[v][i] && !visitado[i]) {
            DFS(g, i, visitado, pilha);
        }
    }
    pilha.push(v);
}

// Função de DFS reverso para o transposto
void DFSUtil(Digrafo &g, int v, vector<bool> &visitado) {
    visitado[v] = true;
    cout << v << " ";
    for (int i = 0; i < g.num_vertices_; i++) {
        if (g.matriz_[i][v] && !visitado[i]) {
            DFSUtil(g, i, visitado);
        }
    }
}

// Função para obter o grafo transposto
Digrafo getTransposto(Digrafo &g) {
    Digrafo gT(g.num_vertices_);
    for (int v = 0; v < g.num_vertices_; v++) {
        for (int i = 0; i < g.num_vertices_; i++) {
            if (g.matriz_[v][i]) {
                gT.matriz_[i][v] = 1;
            }
        }
    }
    return gT;
}

// Função principal para encontrar componentes fortemente conexos
void Kosaraju(Digrafo &g) {
    stack<int> pilha;
    vector<bool> visitado(g.num_vertices_, false);

    // Passo 1: Preencher a pilha com a ordem de término dos vértices
    for (int i = 0; i < g.num_vertices_; i++) {
        if (!visitado[i]) {
            DFS(g, i, visitado, pilha);
        }
    }

    // Passo 2: Obter o grafo transposto
    Digrafo gT = getTransposto(g);
    fill(visitado.begin(), visitado.end(), false);

    // Passo 3: Processar os vértices na ordem definida pela pilha
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();

        if (!visitado[v]) {
            DFSUtil(gT, v, visitado);
            cout << "\n";
        }
    }
}