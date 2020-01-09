/**
Author: Marlon A. Espinosa Castañeiras
https://www.linkedin.com/in/marlonaec/
Algorithm: Cumulative Table
**/
#include <cstdio>

using namespace std;

#define MAX 100
int f, c, M[MAX][MAX];

int main(int argc, char *argv[])
{
    scanf("%d %d",&f, &c);
    for(int i = 1;i <= f;i++)
      for(int j = 1;j <= c;j++){
              scanf("%d", &M[i][j]);
              M[i][j] += M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
              }

    for(int i = 1;i <= f;i++){
      for(int j = 1;j < c;j++)
              printf("%d ",M[i][j]);
            printf("%d\n",M[i][c]);
              }

    return 0;
}
