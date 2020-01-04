/***
Marlon A. Espinosa Casta�eiras
Algorithmo: Floyd-Warshall
Descripci�n: Sirve para hallar el camino m�nimo entre todos
los pares de nodos de un grafo. Solo para grafos en los
cuales la cantidad de nodos sea relativamente peque�a
porque hace O(N^3) para responder  donde N es la cantidad de
v�rtices.
Fecha: 3/03/2013
Hora: 2:26 pm
***/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int M[100][100];
int main()
{
    int v, e, x, y;

    cin>> v>> e;
    memset( M, 0x3f, sizeof M);

    for(int i = 1;i <= e;i++){
        cin>> x>> y;
        cin>> M[x][y];
        M[y][x] = M[x][y];
    }

    for(int k = 1;k <= v;k++)
        for(int i = 1;i <= v;i++)
            for(int j = 1;j <= v;j++)
                M[i][j] = min( M[i][j],M[i][k] + M[k][j] );
    cin>> x >> y;
    cout<< M[x][y]<<endl;


    return 0;
}
