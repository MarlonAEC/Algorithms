/***
Marlon A. Espinosa Castañeiras
Estructura de Datos: Lista Simple Enlazada(Linked List)
Descripción: Estructura de datos que sirve para almacenar
variables(en esta implementación se ha hecho con INT, pero
se puede cambiar el tipo de dato a almacenar modificando
el primer TYPEDEF).
Implementación: Se implementó con punteros
Fecha: 3/03/2013
Hora: 11:50 am
***/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

typedef int Dato;

struct Nodo{
    Nodo* next;
    //Nodo* prev;
    Dato dato;
};

typedef Nodo* Linked_List;

Linked_List Buscar(Linked_List A, Dato k)
{
    Linked_List x = A;
    while(x != NULL && x -> dato !=k)
        x = x -> next;
    return x;
}

Linked_List CreateNodo(Dato d){
    Linked_List Nod = new Nodo;
    Nod -> dato = d;
    Nod -> next = NULL;
    return Nod;
}

void Insertar(Linked_List& L, Dato x)
{
    Linked_List NewInicio = CreateNodo(x);
    if(L == NULL)
        L = NewInicio;
    else{
        NewInicio -> next = L;
        L = NewInicio;
    }
}

void Imprimir(Linked_List A)
{
    Linked_List x = A;
    while (x != NULL){
        cout << x -> dato << " -> ";
        x = x -> next;
    }
    cout<<"\n";
}

Linked_List L;
Linked_List A;
int main()
{
    assert(A == NULL);
    Insertar(A, 3);
    Insertar(A , 4);
    Insertar(A, 5);
    Imprimir(A);
    cout << Buscar(A, 4) << endl;
    return 0;
}
