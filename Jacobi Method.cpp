#include <bits/stdc++.h>

using namespace std;

double X[100], X_0[100], A[100][100], B[100], M[100][100];
int main()
{
    int c, n;
    cin>> c;
    cin>> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n+1;j++){
            if(j == n+1 ){
                cin>>B[i];
                B[i] = B[i];
            }
            else
                cin>> A[i][j];
        }
    for(int i = 1;i <= n;i++){
        B[i] = B[i] / A[i][i];
        X_0[i] = B[i];
        for(int j = 1;j <= n;j++){
            if(i == j)
                M[i][i] = 0;
            else
                M[i][j] = A[i][j] / A[i][i];
        }
    }

    int cant_itera = 0;
    while(cant_itera < c){
        cant_itera++;
        for(int i = 1;i <= n;i++){
            X[i] = B[i];
            for(int j = 1;j <= n;j++)
                    X[i] -= X_0[j] * M[i][j];
        }

        for(int i = 1;i <= n;i++)
            X_0[i] = X[i];
        system("pause");
    }

    for(int i = 1;i <= n;i++ ){
            cout<<X[i]<<" ";
        }
    cout<<endl;

    return 0;
}

