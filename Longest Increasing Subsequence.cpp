#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1005];
int b[1005];
int C[1005][1005];

int main()
{
    int n, t;

    cin>> t;
    for(int k = 1; k <= t ; k++){
        cin>> n;
        for(int i = 1;i <= n;i++){
             cin>> a[i];
             b[i] = a[i];
        }
        sort(b,b + n);

        for(int i = 1;i <= n;i++){
             for(int j = 1;j <= n;j++){
                 if(a[i] == b[j])
                    C[ i ][ j ] = C[i - 1][j - 1] + 1;
                 else
                    C[ i ][ j ] = max( C[i - 1][ j ], C[ i ][j - 1]);
             }
        }

        cout<< C[ n ][ n ]<<endl;
    }

    return 0;
}
