/* Make by MARLON ESPINOSA CASTAÑEIRAS
Algorithm: Depth First Search(DFS)
Fecha:24-12-2011
Descripción: The DFS algorithm is a recursive algorithm that uses the idea of backtracking.
It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.
*/
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 500

using namespace std;

int n,m;
int matrix[MAX][MAX],nf,nc;
const int df[] = {-1, 1 , 0, 0};//Const Matrix for the rows for check all the directions in the matrix
const int dc[] = {0, 0, 1, -1};//Const Matrix for the column for check all the directions in the matrix
//DFS By Backtrack
void DFS(int f,int c)
{
     matrix[f][c] = 1;//setting mark of visited node
     for(int i = 0;i < 4;i++){
         nf = f + df[i];
         nc = c + dc[i];
         if(matrix[nf][nc] != 2 && matrix[nf][nc] != 1){
         DFS( nf, nc);}
     }
}

int main()
{
    FILE *fi = fopen("entrada.in","r");//Reading File
    FILE *fo = fopen("entrada.out","w");//File for Writing

    fscanf(fi,"%d %d",&n,&m);    //reading matrix dimentions
    for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                    fscanf(fi,"%d",&matrix[i][j]);//reading the matrix
            }
    }
    for(int k = 0;k <= max( n,m);k++){//initialazing edges of matrix
            matrix[0][k] = 2;
            matrix[k][0] = 2;
            matrix[k][m + 1] = 2;
            matrix[n + 1][k] = 2;
            }

    matrix[1][1] = 1;
    DFS( 1, 1); // calling the algorithm in (1,1) position

    //printing the matrix solution
    for(int i = 0;i <= n+1;i++){//
            for(int j = 0;j <= m+1;j++){
                    fprintf(fo,"%d ",matrix[i][j]);
            }
            fprintf(fo,"\n");
    }

    for(int i = 1;i <= n;i++){//buscando los no visitados
            for(int j = 1;j <= m;j++){
            if(matrix[i][j] == 0)
            fprintf(fo,"%d;%d\n",i,j);
            }
    }
    fclose(fi);
    fclose(fo);

    return 0;
}
