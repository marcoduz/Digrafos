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
#include "Aresta.h" 
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

        if(S == 2){
            grafo.createAresta(Aresta(X,Y));
            grafo.createAresta(Aresta(Y,X));
        }else if(S == 1){
            grafo.createAresta(Aresta(X,Y));
        }else{
            cout << "Valor Inválido\n";
        }
    }
    grafo.digrafoImprime();
    return 0;
}