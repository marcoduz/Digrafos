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