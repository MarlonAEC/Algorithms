#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int C[50][50];
int main()
{
    char x[10], y[10];
    cin>> x>> y;
    for(int i = 0;i < strlen(x) ; i++){
        for(int j = 0;j < strlen(y);j++){
             if( x[i] == y[j] ){
                 C[i + 1][j + 1] = C[i][j] + 1;
             }
             else
                 C[i + 1][j+1] = max( C[ i ][ j + 1 ], C[ i + 1 ][j]);
             }
        }
    }

    cout<< C[strlen(x)-1][strlen(y) - 1]<<endl;
    return 0;
}
// VERDI vivaVittorioEmanueleReDiItalia
