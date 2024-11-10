#include "Digrafo.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <stack>
using namespace std;

Digrafo::Digrafo(int num_vertices)
{
    if (num_vertices <= 0)
    {
        throw(invalid_argument("O numero de vertices deve ser maior que 0"));
    }
    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    matriz_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++)
    {
        matriz_[i].resize(num_vertices, 0);
    }
}

int Digrafo::get_num_vertices()
{
    return num_vertices_;
}

std::vector<std::vector<int>> Digrafo::get_matriz()
{
    return matriz_;
}

void Digrafo::setValorMatriz(int i, int j, int valor)
{
    matriz_[i][j] = valor;
}

bool Digrafo::verticeValido(int v)
{
    return v >= 0 && v < num_vertices_;
}

bool Digrafo::existeAresta(Aresta e)
{
    return matriz_[e.v1][e.v2] == 1;
}

void Digrafo::createAresta(Aresta e)
{
    if (!verticeValido(e.v1) || !verticeValido(e.v2))
    {
        return;
    }

    if ((e.v1 != e.v2) && !existeAresta(e))
    {
        matriz_[e.v1][e.v2] = 1;
        num_arestas_++;
    }
}

void Digrafo::removeAresta(Aresta e)
{
    matriz_[e.v1][e.v2] = 0;
    num_arestas_--;
}

void Digrafo::digrafoImprime()
{
    for (int i = 0; i < num_vertices_; i++)
    {
        cout << "\n";
        for (int j = 0; j < num_vertices_; j++)
        {
            cout << matriz_[i][j];
        }
    }
}

void Digrafo::DFS(int v, vector<bool> &visitado, stack<int> &pilha)
{
    visitado[v] = true;
    for (int i = 0; i < get_num_vertices(); i++)
    {
        if (existeAresta({v, i}) && !visitado[i])
        {
            DFS(i, visitado, pilha);
        }
    }
    pilha.push(v);
}

void Digrafo::DFSUtil(int v, vector<bool> &visitado)
{
    visitado[v] = true;
    for (int i = 0; i < get_num_vertices(); i++)
    {
        if (matriz_[v][i] && !visitado[i])
        {
            DFSUtil(i, visitado);
        }
    }
}

Digrafo getTransposto(Digrafo &g)
{
    std::vector<std::vector<int>> matriz_ = g.get_matriz();
    Digrafo gT(g.get_num_vertices());

    for (int v = 0; v < g.get_num_vertices(); v++)
    {
        for (int i = 0; i < g.get_num_vertices(); i++)
        {
            if (matriz_[v][i])
            {
                gT.setValorMatriz(i, v, 1);
            }
        }
    }
    return gT;
}

int Digrafo::Kosaraju()
{
    stack<int> pilha;
    vector<bool> visitado(get_num_vertices(), false);
    int componentes = 0;

    // Passo 1: Preencher a pilha com a ordem de término dos vértices
    for (int i = 0; i < get_num_vertices(); i++)
    {
        if (!visitado[i])
        {
            DFS(i, visitado, pilha);
        }
    }

    // Passo 2: Obter o grafo transposto
    Digrafo gT = getTransposto(*this);
    fill(visitado.begin(), visitado.end(), false);

    // Passo 3: Processar os vértices na ordem definida pela pilha
    while (!pilha.empty())
    {
        int v = pilha.top();
        pilha.pop();

        if (!visitado[v])
        {
            gT.DFSUtil(v, visitado);
            componentes++;
        }
    }

    return componentes;
}