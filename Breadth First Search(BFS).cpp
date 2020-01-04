/* Make by Marlon ESPINOSA CASTA�EIRAS 
Fecha: 22/12/2011
algorithm: Breadth First Search(BFS)
descripci�n: Sirve para buscar el minimo camino entre el v�rtice 1 y el v�rtice n,
*/

#include <cstdio>
#include <queue>
#include <vector>

#define MAX 100
#define X  first
#define Y second
using namespace std;

queue<int> Q;
int mat[MAX][MAX];
typedef pair<int,int> cord;
queue<cord> V;
int marca[MAX];

int main()
{
  int v,e,x,val;
  
  scanf("%d",&val);   // lee el vertice para el cual se busca el camino minimo
   scanf("%d %d",&v,&e); //lee la cantidad de v�rtices y aristas del grafo
     
    for(int j = 0;j < e; j++){
            cord F = make_pair(0,0);
            scanf("%d %d", &F.X,&F.Y);   //esto es para leer las aristas
            mat[F.X][F.Y] = 1;        //esto es para hacer la metriz booleana
            mat[F.Y][F.X] = 1;        //esto tambi�n es para la booleana
            }
                
     marca[1] = 1;
     Q.push(1);
     
    while(!Q.empty()){            //para hacer el camino y poner la marca a los v�rtices
     x = Q.front();
     Q.pop();          
       for(int y = 1; y <= v; y++){
             if(marca[y]== 0 && mat[x][y] == 1){
                Q.push(y);
                marca[y] = marca[x] + 1;
                }
             }
    }
    
    printf("%d end\n",marca[val]);
    
    return 0;
}
