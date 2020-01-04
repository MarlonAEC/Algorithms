/***
Marlon A. Espinosa Castañeiras
Estructura: Lista Simple Ordenada(Ordered Linked List)
Descripción: Esta escructura de datos permite mantener
siempre un conjunto de numeros de manera ordenada, estan
implementadas las funciones Insertar, Delete, Buscar, imprimir
y tamaño de la lista (esta responde en tiempo O(1) ).
Fecha: 3/03/2013
Hora: 2:04 pm
***/

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

typedef int Dato;

Dato SIZE_LIST;
struct Nodo{
    Dato dato;
    Nodo* next;
};

typedef Nodo* Linked_List;

Linked_List CreateNodo(Dato d)
{
    Linked_List Nod = new Nodo;
    Nod -> dato = d;
    Nod -> next = NULL;
    return Nod;
}

void Insertar(Linked_List& A, Dato x)
{
    SIZE_LIST++;
    Linked_List Lista = CreateNodo(x);
    Linked_List X = A;
    if( A == NULL )
        A = Lista;
    else{
        if(X -> dato > x){
            Linked_List N = CreateNodo(x);
            N -> next = X;
            A = N;
        }
        else{
            while( X -> next != NULL && X ->next -> dato < x )
                X = X -> next;

            Linked_List NEW = CreateNodo(x);
            NEW -> next = X -> next;
            X -> next = NEW;
        }
    }
}

Linked_List Buscar(Linked_List A, Dato x)
{
    Linked_List X = A;
    while(X -> next != NULL && X -> next -> dato < x)
        X = X -> next;

    if(X -> next -> dato != x)
        return NULL;
    return X;
}

void Delete(Linked_List& A, Dato x)
{
    if(A -> dato == x){
        SIZE_LIST--;
        A = A -> next;
    }
    else{
        Linked_List X = Buscar(A, x);
        if(X != NULL){
            SIZE_LIST--;
            if(X -> next -> next == NULL)
                X -> next = NULL;
            else
                X -> next = X -> next -> next;
        }
    }
}

void Imprimir(Linked_List A)
{
    Linked_List x = A;
    while(x != NULL){
        cout<< x -> dato<<" ";
        x = x -> next;
    }
    cout<<"\n";
}

Linked_List L;
vector<int> V;
int main()
{
    for(int i = 0;i <= 10;i++){
        int x = rand() % 100;
        Insertar(L,x);
        V.push_back(x);
    }
    Insertar(L, 12);
    Insertar(L,3);
    Imprimir(L);
    cout<<"SIZE: "<<SIZE_LIST<<endl;
    Delete( L, 41 );
    Imprimir(L);
    cout<<"SIZE: "<<SIZE_LIST<<endl;

    return 0;
}
