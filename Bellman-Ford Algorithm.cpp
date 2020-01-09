/**
Author: Marlon Alejandro Espinosa Castañeiras
Algorithm: Bellman-Ford
Given a graph and a source vertex src in graph, find shortest paths from src to all vertices
in the given graph. The graph may contain negative weight edges.
**/

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>

#define oo 1 << 20 //infinite
#define F first //node
#define S second //cost to visit that node

using namespace std;

typedef pair<int, int> par;
vector<par> V;
int D[101]; //cost for visit each node
int P[101]; //father of each node (i.e. from where I came to visit it)
int n, e;   //amount of nodes and edges
int Mat_Cost[101][101]; //Cost Matrix


bool bellman_ford(int s)
{

    D[s] = 0; //the cost for go from node S to himself is 0

    //Relaxing all the edges n - 1 times because that is the amount of possible path from source node
    //to all the others nodes
    for(int i = 1;i <= n - 1;i++){
        for(int u = 0;u < V.size();u++){
                if(D[ V[u].S ] > D[ V[u].F ] + Mat_Cost[ V[u].F ][ V[u].S ]){
                    D[ V[u].S ] = D[ V[u].F ] + Mat_Cost[ V[u].F ][ V[u].S ];
                    P[ V[u].S ] = V[u].F;
                }
        }


    }
    //chequing if exist a negative cycle
    for(int u = 0;u < V.size();u++){
            if(D[ V[u].S ] > D[ V[u].F ] + Mat_Cost[ V[u].F ][ V[u].S ])
                return false;
    }
    return true;
}

int main()
{

    int u, v, c;
    cout<<"Introduce the amount of nodes and edges (N E):"<<endl;
    cin>>n>>e;
    cout<<"Introduce the edges and the costs of each edge (NodeA NodeB Cost):"<<endl;

    fill(D, D + n+1, oo);//initializing the solution to infinite
    fill(P, P + n+1, oo);
    fill(*Mat_Cost,*Mat_Cost + (2*n + 1), oo);//filling th cost matrix whit infinite

    for(int i = 0;i < e;i++){
        cin>> u>> v>> c;
        V.push_back( make_pair(u, v) );
        Mat_Cost[u][v] = c;
    }

    if(bellman_ford(1)){
        cout<<"There is a Path and the cost are:\n";
        for(int i = 1;i <= n;i++){
            cout<<"Node "<<i<<": "<<D[i]<<"\n";
        }
        cout<<endl;
    }
    else
        cout<<"There is a negative cycle\n";


    return 0;
}

/***
5 10
1 2 7
2 3 9
1 4 6
3 1 2
2 5 -3
4 3 -4
4 5 5
5 4 -2
4 2 8
3 5 7
***/
