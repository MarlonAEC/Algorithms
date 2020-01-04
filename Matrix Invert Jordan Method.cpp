/**
Algoritmo: Invertir matrices Método de Jordan
Make by: Marlon A. Espinosa Castañeiras
Universida de Oriente, Santiago de Cuba
21/11/2015
**/

#include <bits/stdc++.h>

using namespace std;

double A[100][100], B[100], X[100], Mik;
int main()
{
    int n;
    cout<<"Introduzca la cantidad de variables: ";
    cin>> n;
    cout<<"Introduzca los coeficientes:\n";

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++)
                cin>> A[i][j];
        A[i][n + i] = 1;///anexando la matriz identidad
    }

    /**escalonando ambas matrices a la vez**/
    for(int k = 1;k <= n;k++){
        for(int i = 1; i <= n;i++){
            if(i != k){
                Mik = A[i][k] / A[k][k];
                for(int j = k; j <= 2*n;j++)
                    A[i][j] = A[i][j] - Mik * A[k][j];
            }
        }
        system("pause");
        cout<<"PASO "<<k<<":\n";
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 2 * n;j++)
                printf("%.1lf ", A[i][j]);
            cout<<endl;
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 2*n;j++){
            A[i][j] = A[i][j] / A[i][i];/// dividiendo todas las filas por su respectivo pivote (A[i][i])
        }
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 2 * n;j++)
                printf("%.1lf ", A[i][j]);
        cout<<endl;
    }

    return 0;
}
/**
4
1 -2 2 -1 0
2 -3 1 1 1
1 -1 2 3 5
2 1 1 -1 3
*/
