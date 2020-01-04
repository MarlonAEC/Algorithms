#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int C[505][505];
int main()
{
    string s, t;

    cin>> s >> t;
    int n = s.length();
    int m = t.length();
    for(int i = 0;i <= max(n,m);i++){
        C[i][0] = i;
        C[0][i] = i;
    }

    for(int i = 1;i <= n;i++){
         for(int j = 1;j <= m;j++){
              if(s[i - 1] == t[j - 1])
                  C[ i ][ j ] = C[i - 1][j - 1];
              else
                  C[ i ][ j ] = 1 + min( min(  C[ i ][j - 1], C[i - 1][j] ), C[i - 1][j - 1]);
         }
    }

    printf("%d\n",C[ n ][ m ]);
    return 0;
}
