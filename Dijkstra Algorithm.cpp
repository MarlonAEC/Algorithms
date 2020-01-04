#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

#define oo 1 << 20
#define MAX 100
#define F first
#define S second
using namespace std;

typedef pair<int,int> par;
vector< vector<par> > adlist(MAX);
priority_queue<par> Q;
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

    fill(A, A + v + 1, oo);
    A[nodini] = 0;
    Q.push( make_pair( 0,nodini ));

    while( !Q.empty() ){
        int x = Q.top().S;
        Q.pop();
        for(int i = 1;i <= v;i++)
            cout<< A[i]<<" ";

        cout<<endl;
        for(int i = 0; i < adlist[x].size();i++){
            int newn = adlist[x][i].F;
            int costo = A[x] + adlist[x][i].S;
            if( costo < A[newn]){
                A[newn] = costo;
                Q.push( make_pair(costo,newn) );
            }
        }
    }

    return 0;
}
/*
1
6 7
1 3 5
1 2 3
1 5 4
2 6 2
2 4 6
6 4 1
5 4 3
*/
