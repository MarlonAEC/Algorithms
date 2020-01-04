#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1000;

struct queue{
    int head;
    int tail;
    int datos[MAXN];
}Q;

void enqueue(int x)
{
    Q.datos[Q.tail] = x;
    if(Q.tail == Q.head)
        Q.tail = 1;
    else
        Q.tail++;
}

int dequeue()
{
    int x = Q.datos[Q.head];
    if(Q.head == Q.tail)
        Q.head = 1;
    else
        Q.head++;
    return x;
}
int main()
{
    for(int i = 2;i <= 100;i += i * i){
        cout<<i<<" ";
        enqueue(i);
    }
    cout<<endl;
    dequeue();

    for(int i = Q.head;i < Q.tail;i++)
        cout<< Q.datos[i]<<" ";
    cout<<endl;
    return 0;
}
