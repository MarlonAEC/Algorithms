/***
Marlon A. Espinosa Castañeiras
Estructura: Árbol Binario Indexado(ABI) o Fenwick Tree
Descripción: Sirve para hacer una tabla acumulativa y responder
preguntas a sumas en un rango [A,B] en tiempo logaritmico
y además actualiza la TA en una posición determinada
en tiempo logaritmico también.
Fecha: 3/03/ 2013
Hora: 2:55 pm
Refernecias: Problema 1850 del Cariben Online Judge(COJ).
y la otra version que tambien está en COJ.
***/

#include <cstdio>
#include <vector>
#include <iostream>

#define max 10005
using namespace std;

vector<int> create(int n){ return vector<int> (n,0);}
vector<int> tree;

int query( int a, int b)
{
    if(a == 0){
        int sum = 0;
        for(; b >= 0; b = (b & (b + 1)) - 1)
            sum += tree[b];
        return sum;
    }
    else{
        return query(0, b) - query(0, a - 1);
    }
}

void update( int k, int inc)
{
    for(;k < (int)tree.size();k |= k + 1)
        tree[k] += inc;
}

int main()
{
    int n, u, q, p, k;
    cin>> n;
    tree = create(max);
    cin>> u>> q;
    for(int i = 0;i < u;i++){
        cin>> p>> k;
        update(p + 1, k);
        update(p - 1, k);
        update(p, k + 1);
    }
    for(int i = 0;i < q;i++){
        cin>> p >> k;
        cout<< query(p, k)<<endl;
    }
    //for(;n < 100;n |= n + 1)
        //cout<< n<<" ";
    return 0;
}
