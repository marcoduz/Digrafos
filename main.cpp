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
#include <iostream>
#include <vector>
// #include "Digrafo.h"
#include "Digrafo.cpp"
#include "Aresta.cpp"
using namespace std;

int main()
{
    int P, D;
    cin >> P >> D;
    Digrafo(P);

    for (int i = 0; i < D; i++)
    { 
        int X, Y, S;

        cin >> X >> Y >> S;

        if(S == 2){
            createAresta(Aresta(X,Y));
            createAresta(Aresta(Y,X));
        }else if(S == 1){
            createAresta(Aresta(X,Y));
        }else{
            cout << "Valor Inválido\n";
        }
    }

    for (int i=0; i < P; i++){
        cout << "\n";
        for(int j = 0; j < P; j++){
            cout << matriz_[i][j];
        }
    }
    return 0;
}