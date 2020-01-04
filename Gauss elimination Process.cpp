/**
Algoritmo: Resolucion de Sistemas de Ecuaciones con el Método de Gauss
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
    /** Escalonamiento de la matriz
    Coeficiente de cada fila se transforma utilizando la expresion:
    (Aij) del k-esimo paso = Aij^(k-1) - (Aik^(k-1) * Akj^(k-1)) / Akk^(k-1)
    donde k es el paso en el que estamos
    **/
    for(int k = 1;k <= n - 1;k++){
        for(int i = k + 1; i <= n;i++){
            Mik = A[i][k] / A[k][k];///se calcula afuera una parte del segundo término de la resta ya que es el mismo para todos los j-esimos coeficientes
            for(int j = k + 1; j <= n;j++)
                A[i][j] = A[i][j] - Mik * A[k][j];
            B[i] = B[i] - Mik * B[k];///B[i] son los términos independientes
        }
    }/**fin del escalonamiento**/

    /**Reconstrucción de las soluciones a partir del Xn**/
    X[n] = B[n] / A[n][n];
    for(int i = n - 1;i >= 1; i--){
        double sum = 0;
        for(int j = i + 1; j <= n;j++)
            sum += A[i][j] * X[j];
        X[i] = (B[i] - sum) / A[i][i];
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
