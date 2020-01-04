#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>

#define oo 1 << 20
#define F first
#define S second

using namespace std;

typedef pair<int, int> par;
vector<par> V;
int D[101], P[101], n, e;
int Mat_Cost[101][101];

void relax(int u, int v, int c)
{
    //cout<<v<<" "<<u<<endl;
    //system("pause");

}

bool bellman_ford(int s)
{
    //fill(costo, costo + n, oo);
    //fill(padre,padre + n, oo);
    D[s] = 0;
    cout<<n<<endl;
    //Q.push(s);
    for(int i = 1;i <= n - 1;i++){
        for(int u = 0;u < V.size();u++){
                //relax(V[u].F , V[u].S ,Mat_Cost[ V[u].F ][ V[u].S ]);
                if(D[ V[u].S ] > D[ V[u].F ] + Mat_Cost[ V[u].F ][ V[u].S ]){
                    //cout<<D[ V[u].F ]<<" "<<V[u].F<<" "<<V[u].S;
                    D[ V[u].S ] = D[ V[u].F ] + Mat_Cost[ V[u].F ][ V[u].S ];
                    //cout<<" cost:"<<D[ V[u].S ]<<endl;
                    P[ V[u].S ] = V[u].F;
                }
        }
//        for(int i = 1;i <= n;i++){
//            cout<< D[i]<<" ";
//        }
//        cout<<endl;
//        system("pause");

    }
    for(int u = 0;u < V.size();u++){
            if(D[ V[u].S ] > D[ V[u].F ] + Mat_Cost[ V[u].F ][ V[u].S ])
                return false;
    }
    return true;
}

int main()
{

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            Mat_Cost[i][j] = oo;

    int u, v, c;
    cin>>n>>e;

    fill(D, D + n+1, oo);
    fill(P, P + n+1, oo);

    for(int i = 0;i < e;i++){
        cin>> u>> v>> c;
        V.push_back( make_pair(u, v) );
        Mat_Cost[u][v] = c;
    }

    cout<<bellman_ford(1)<<endl;

    for(int i = 1;i <= n;i++){
        cout<< D[i]<<" ";
    }
    cout<<endl;
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
