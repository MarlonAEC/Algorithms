#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 1000;

struct stack{
    int top;
    int pila[MAXN];
}Pila;
void push( int x){
    Pila.top++;
    Pila.pila[Pila.top] = x;
}
bool empty(stack S){
     if(S.top == 0)
        return true;
    return false;
}
int pop(){
    if( empty( Pila ) )
        printf("error: underflow\n");
    else{
        return Pila.pila[--Pila.top + 1];
    }
}

int main()
{
    push(4);
    cout<<Pila.pila[Pila.top]<<endl;
    return 0;
}
