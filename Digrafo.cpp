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
    if(verticeValido(e.v1) && verticeValido(e.v2)){
        return;
    }

    if ((e.v1 != e.v2) && existeAresta(e))
    {
        matriz_[e.v1][e.v2] = 1;
    }
    
}
void Digrafo::removeAresta(Aresta e)
{
    matriz_[e.v1][e.v2] = 0;
}