#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <set>

#define MAXN 100;
#define F first
#define S second
using namespace std;

int P[1000], rank[1000];

typedef pair<int,pair<int, int> > arista;

int create_set(int x)
{
    P[x] = x;
    rank[x] = 0;
}

int find_set(int x)
{
    if( x != P[x] )P[x] = find_set( P[x] );
        return P[x];
}

int merge_set(int x, int y)
{
    int Px = find_set( x );
    int Py = find_set( y );

    if( rank[Px] > rank[Py] ) {
        P[Py] = Px;
        rank[Px] += rank[Py];
    }
    else{
        P[Px] = Py;
        rank[Py] += rank[Px];
    }
}

//bool mycomp(arista a, arista b)
//{
//    return a < b;
//}

priority_queue<arista, vector<arista> ,greater<arista>  > Q;
int main()
{
    int n, e, ini, fin, cost;

    cin>> n >> e;

    for(int i = 0; i < e;i++){
        cin>> ini>>fin>> cost;
        arista A = make_pair( cost, make_pair(ini, fin) );
        Q.push( A );
    }

    for(int i = 1;i <= n;i++){
        create_set(i);
    }

    int sol = 0;
    while(!Q.empty()){
        arista A = Q.top();
        Q.pop();
        cout<<A.S.F<<" "<<A.S.S<<endl;
        if( find_set(A.S.F) != find_set(A.S.S) ){
                merge_set( A.S.S, A.S.F);
                cout<< A.S.F<<" "<<A.S.S<<endl;
                system("pause");
                sol += A.F;
        }
    }

    cout<<"Costo del Arbol de costo minimo:"<<sol<<endl;

    return 0;
}
/***
5 10
1 2 2
2 5 3
2 3 5
3 4 3
4 6 2
5 6 6
5 3 7
1 3 1
1 4 6
3 6 4

***/

