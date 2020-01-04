#include <bits/stdc++.h>

using namespace std;

double U[100][100], A[100][100], L[100][100], B[100], Y[100], X[100];
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

    for(int j = 1; j <= n;j++){
        U[1][j] = A[1][j];
        L[j][j] = 1;
    }

    for(int i = 2;i <= n;i++){
        L[i][1] = A[i][1] / U[1][1];
        for(int j = 2;j <= i - 1;j++){
            int sum = 0;
            for(int k = 1; k <= j-1;k++){
                sum += L[i][k] * U[k][j];
            }
            L[i][j] = (A[i][j] - sum) / U[j][j];
        }
        for(int j = i;j <= n;j++){
            int sum = 0;
            for(int k = 1;k <= i - 1;k++ ){
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - sum;
        }
    }

    Y[1] = B[1];
    for(int i = 2; i <= n;i++){
        int sum = 0;
        for(int j = 1;j <= i-1; j++){
            sum += L[i][j] * Y[j];
        }
        Y[i] = B[i] - sum;
    }

    X[n] = Y[n] / U[n][n];

    for(int i = n - 1; i >= 1;i--){
        int sum = 0;
        for(int j = i + 1;j <= n;j++){
            sum += U[i][j] * X[j];
        }
        X[i] = (Y[i] - sum) / U[i][i];
    }

    for(int i = 1; i <= n;i++){
        printf("Y%d = %.1lf ", i, Y[i]);
        //printf("X%d = %.1lf ", i, X[i]);
    }
    cout<<endl;
    for(int i = 1; i <= n;i++){
//        printf("X%d = %.1lf ", i, Y[i]);
        printf("X%d = %.1lf ", i, X[i]);
    }
    return 0;
}

