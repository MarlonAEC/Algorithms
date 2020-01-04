/* Make by MARLON ESPINOSA CASTAÑEIRAS
Provincia: Las Tunas 
Algorithm: BUSQUEDA EN PROFUNDIDAD(DFS)
Fecha:24-12-2011
Descripción: Sirve para encontrar los lugares imposibles de vistar por alguien 
que se encuentre en la casilla (1;1) de la matrix
*/
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX 500

using namespace std;

int n,m;
int matrix[MAX][MAX],nf,nc;
const int df[] = {-1, 1 , 0, 0};//matriz constante de las filas para revisar en todas las direcciones
const int dc[] = {0, 0, 1, -1};//matriz constante para las columnas para revisar en todas las direcciones

//DFS Algorithmo recursivo
void DFS(int f,int c)
{
     matrix[f][c] = 1;
     for(int i = 0;i < 4;i++){
         nf = f + df[i];
         nc = c + dc[i];         
         if(matrix[nf][nc] != 2 && matrix[nf][nc] != 1){
         DFS( nf, nc);}
     }
}

int main()
{
    FILE *fi = fopen("entrada.in","r");
    FILE *fo = fopen("entrada.out","w");
    
    fscanf(fi,"%d %d",&n,&m);    //leyendo las dimenciones da la matrix
    for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                    fscanf(fi,"%d",&matrix[i][j]);
            }
    }
    for(int k = 0;k <= max( n,m);k++){//inicializando la matrix para que no se salga de esta
            matrix[0][k] = 2;
            matrix[k][0] = 2;
            matrix[k][m + 1] = 2;
            matrix[n + 1][k] = 2;
            }
    
    matrix[1][1] = 1;
    DFS( 1, 1); // marcando los caminos posibles a visitar 
    
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
