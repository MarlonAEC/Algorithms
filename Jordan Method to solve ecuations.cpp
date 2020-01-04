/**
Algoritmo: Resolucion de Sistemas de Ecuaciones con el Método de Jordan
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

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n+1;j++){
            if(j == n+1 )
                cin>>B[i];
            else
                cin>> A[i][j];
        }
    /**
    **/
    for(int k = 1;k <= n ;k++){
        for(int i = 1; i <= n;i++){
            if(i != k){
                Mik = A[i][k] / A[k][k];
                for(int j = k; j <= n;j++)
                    A[i][j] = A[i][j] - Mik * A[k][j];
                B[i] = B[i] - Mik * B[k];///B[i] son los términos independientes
            }
        }
    }/**fin del escalonamiento**/

    for(int i = 1;i <= n; i++){
            X[i] = B[i] / A[i][i];
    }/**fin de la reconstrucción**/

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n+1;j++){
            if(j < i)
                cout<<"0 ";
            else
                printf("%.1lf ", A[i][j]);
        }
        cout<<endl;
    }


    for(int i = 1;i <= n;i++)
        printf("X%d = %.1lf\n",i, X[i]);


    return 0;
}
/**
4
1 -2 2 -1 0
2 -3 1 1 1
1 -1 2 3 5
2 1 1 -1 3
*/

