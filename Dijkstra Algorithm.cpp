/**
Author: Marlon Alejandro Espinosa Castañeiras
https://www.linkedin.com/in/marlonaec/
Algorithm: Dijkstra's algorithm (or Dijkstra's Shortest Path First algorithm, SPF algorithm)
is an algorithm for finding the shortest paths between nodes in a graph, which may represent,
for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956
and published three years later.
**/

#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

//defining some useful variables
#define oo 1 << 20 //infinite
#define MAX 100
#define F first
#define S second

using namespace std;

typedef pair<int,int> par;
vector< vector<par> > adlist(MAX); // adjacency list
priority_queue<par> Q; //priority queue for the algorithm
int A[MAX];

int main()
{int v, e, x, y, p, nodini;

    scanf("%d",&nodini);
    scanf("%d %d",&v,&e);

    for(int i = 1;i <= e;i++){
            scanf("%d %d %d",&x,&y,&p);
            adlist[x].push_back( make_pair( y , p ) );
            adlist[y].push_back( make_pair( x , p ) );
    }

    fill(A, A + v + 1, oo); //
    A[nodini] = 0; //setting the cost to arrive to the initial node to 0
    Q.push( make_pair( 0,nodini )); //starting the algorithm whit the initial node

    while( !Q.empty() ){//algorithm
        int x = Q.top().S;
        Q.pop();
        for(int i = 1;i <= v;i++)//printing the updates made by the algorithm
            cout<< A[i]<<" ";

        cout<<endl;
        for(int i = 0; i < adlist[x].size();i++){
            int newn = adlist[x][i].F;
            int cost = A[x] + adlist[x][i].S; //cost for the edge x <-> i
            if( cost < A[newn]){//if is better than the cost we already had then update
                A[newn] = cost;
                Q.push( make_pair(cost,newn) );//and also put the new node reached
            }
        }
    }

    return 0;
}
/*
Sample input:
1           :initial node
6 7         :amount of nodes and edges
1 3 5       :edges in the format (initial_node end_node cost).
1 2 3
1 5 4
2 6 2
2 4 6
6 4 1
5 4 3
*/
