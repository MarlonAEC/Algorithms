/* Make by Marlon ESPINOSA CASTAÑEIRAS
Fecha: 22/12/2011
algorithm: Breadth First Search(BFS)
descripción: find the minimum path between vertex 1 and vertex n
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

  scanf("%d",&val);   //read the vertex for wich you are looking the path
   scanf("%d %d",&v,&e); //Read the amount of vertex and the amount of graph edges

    for(int j = 0;j < e; j++){
            cord F = make_pair(0,0);
            scanf("%d %d", &F.X,&F.Y);   //reading edges
            mat[F.X][F.Y] = 1;        //Building the boolean Matrix of connections between nodes
            mat[F.Y][F.X] = 1;
            }

     marca[1] = 1;
     Q.push(1);

    while(!Q.empty()){            //building the path and marking the visited nodes
     x = Q.front();
     Q.pop();
       for(int y = 1; y <= v; y++){
             if(marca[y]== 0 && mat[x][y] == 1){// if it is not visited and there is a edge between nodes mark it and add the node to solution
                Q.push(y);
                marca[y] = marca[x] + 1;
                }
             }
    }

    printf("%d end\n",marca[val]);

    return 0;
}
