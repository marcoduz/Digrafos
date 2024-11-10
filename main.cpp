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
using namespace std;

int main()
{
    int P, D;
    cin >> P >> D;
    Digrafo grafo(P);

    for (int i = 0; i < D; i++)
    {
        int X, Y, S;
        cin >> X >> Y >> S;

        if (S == 2)
        {
            grafo.createAresta(Aresta(X, Y));
            grafo.createAresta(Aresta(Y, X));
        }
        else if (S == 1)
        {
            grafo.createAresta(Aresta(X, Y));
        }
        else
        {
            cout << "Valor Inválido\n";
        }
    }

    Digrafo condensado(1);
    std::vector<int> componente(grafo.get_num_vertices(), 0);
    grafo.criaGrafoCondensado(grafo.Kosaraju(componente), condensado, grafo, componente);
    condensado.mostraConexoesEntreCFCs(condensado);

    // Encontrar o número de componentes fortemente conectadas
    // condensado.mostraConexoesEntreCFCs(condensado);
    //   int numCFCs, Digrafo &condensado, Digrafo &g, std::vector<int> &componente
    // cout << "Número de componentes fortemente conectadas: " << num_componentes << endl;

    return 0;
}