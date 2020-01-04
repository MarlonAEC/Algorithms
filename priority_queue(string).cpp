#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

class priority_queue{
private:
    via heap[1001];
    int tam;
public:
    inline int hijo_izquierdo(int i){return 2 * i;}

    inline int hijo_derecho(int i){return 2 * i + 1;}

    inline int padre(int i){return ceil( i / 2 );}

    ///Algorithmo recursivo para mantener la propiedad del Heap
    void MAX_HEAPIFY(int n)
    {
        int largest;
        int l = hijo_izquierdo(n);
        int r = hijo_derecho(n);
        if( l <= tam && heap[l] > heap[n])
            largest = l;
        else
            largest = n;
        if(r <= tam && heap[r] > heap[largest])
            largest = r;
        if(largest != n ){
            swap(heap[n], heap[largest]);
            MAX_HEAPIFY(largest);
        }
    }/**OK**/
    ///esto es para crear el Max_Heap
    void Build_Max_Heap()
    {
        for(int i = ceil(tam / 2); i > 0;i--)
            MAX_HEAPIFY(i);
    }/**OK**/

    via top()
    {
        return heap[1];
    }
    ///Esto es para extrar el máximo de un Max_Heap
    void pop()
    {
        if(tam < 1)printf("ERROR: heap underflow\n");
        else{
            heap[1] = heap[tam];
            tam = tam - 1;
            MAX_HEAPIFY(1);
        }
    }/**OK**/

    ///Con esta función también se puede construir un Max_Heap solo que hay que insertar los elementos de uno en uno
    void push(via v)
    {
        if(tam == 0)
            heap[1] = v;
        else{
            int pos = tam + 1 , pad;
            heap[ pos ] = v;
            pad = padre(pos);
            while(pad > 1 && heap[pos] > heap[pad]){
                swap( heap[pos], heap[pad]);
                pos = pad;
                pad = padre(pos);
            }
        }
        tam++;
    }
};


int main()
{
    priority_queue Q<string>;

    Q.push("marlon");
    Q.push("anabanana");
    Q.push("marica");
    cout<<Q.top();
    Q.pop();
    cout<<Q.top();
    Q.pop();

    return 0;
}
