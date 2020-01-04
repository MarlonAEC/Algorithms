#include <bits/stdc++.h>

#define MAXN 1000
#define NEUTRO -1 << 30
using namespace std;

inline int LEFT(int n){return 2 * n;}
inline int RIGTH(int n){return 2*n + 1;}


int oper(int a, int b)
{
    return max(a, b);
}

void inicializar(int n, int ini, int fin, int*Segment_Tree, int* Array)
{
    if(ini == fin) Segment_Tree[n] = Array[ini];
    else{
        inicializar( LEFT(n), ini, (ini + fin) / 2 , Segment_Tree, Array);
        inicializar( RIGTH(n), ((ini + fin) / 2) + 1, fin , Segment_Tree, Array);
        Segment_Tree[n] = oper( Segment_Tree[LEFT(n)], Segment_Tree[RIGTH(n)] );
    }
}

void update(int n, int ini,int fin, int pos, int *Segment_Tree,int *Array)
{
    if(ini == fin)
        Segment_Tree[n] = ++Array[ini];
    else{
        if( pos <= (ini + fin) / 2)
            update(LEFT(n), ini, (ini + fin) / 2 , pos, Segment_Tree, Array);
        else
            update(RIGTH(n), ((ini + fin) / 2 + 1), fin, pos , Segment_Tree, Array);
        Segment_Tree[n] = oper( Segment_Tree[ LEFT(n) ], Segment_Tree[ RIGTH(n) ] );
    }
}

int query(int n, int ini, int fin, int a, int b, int* Segment_Tree)
{
    if( fin <= a || ini >= b) return NEUTRO;
    else if(ini >= a && fin <= b)return Segment_Tree[n];
    else{
        int l = query( LEFT(n), ini, (ini + fin) / 2, a, b , Segment_Tree);
        int r = query(RIGTH(n), ((ini + fin) / 2) + 1, fin, a, b , Segment_Tree);
        return oper( l , r);
    }
}

int Segment_Tree[MAXN], Array[MAXN];
int main()
{
    int n, a, b;

    cin>> n;

    inicializar(1, 1, n, Segment_Tree, Array);
    for(int i = 1;i <= n;i++){
        cin>> a>> b;
        for(int j = a;j <= b;j++)
            update(1, 1, n, j, Segment_Tree, Array);
    }

    for(int i = 1;i <= n;i++)
        cout<<Segment_Tree[i]<<" ";
    cout<<endl;

    cout<< query(1, 1, n, 1, n, Segment_Tree);
    return 0;
}
