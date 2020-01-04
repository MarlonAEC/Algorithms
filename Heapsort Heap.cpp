/***
Autor: Marlon A. Espinosa Castañeiras
Date: 18/04/2013
Data estructure: HEAP
Algorithm implemented: HEAPSORT
Description: Esta es una estructura de datos que se emplea en el algorithmo
Heapsort que sirve para ordenar un arreglo, no importa que tan grande sea
su tiempo de ejecución siempre será O(N*logN). En este código estan imple-
mentadas funciones para crear el Max_Heap, para mantener la propiedada
del Heap, para extraer el Máximo valor del Heap, entre otras. Como
referencia pueden consultar el texto "Introduction to Algorithms"(third edition).
***/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;
//declaraciones
int heap[1001];
int tam;
//funciones
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
///algorithmo para ordenar el arreglo
void Heapsort()
{
    int lengt = tam;
    Build_Max_Heap();
    for(int i = lengt;i > 1;i--){
        swap(heap[i],heap[1]);
        tam = tam - 1;
        MAX_HEAPIFY(1);
    }
}/**OK**/
///Esto es para extrar el máximo de un Max_Heap
int Heap_Extract_Max()
{
    if(tam < 1)printf("ERROR: heap underflow\n");
    else{
        int max2 = heap[1];
        heap[1] = heap[tam];
        tam = tam - 1;
        MAX_HEAPIFY(1);
        return max2;
    }
}/**OK**/
///Esto es para sustituir el valor de un elemento del arreglo por una clave mayor
void Heap_Increase_Key(int pos, int key)
{
    if( key < heap[pos])
        printf("ERROR: new key is smaller than current key\n");
    else{
        heap[pos] = key;
        int pad = padre(pos);
        while(pad > 0 && heap[pos] > heap[pad]){
            swap( heap[pos], heap[pad] );
            pos = pad;
            pad = padre(pos);
        }
    }
}/**OK**/

///Con esta función también se puede construir un Max_Heap solo que hay que insertar los elementos de uno en uno
void insertar(int v)
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
//funciones the end.

int main()
{
    int a;
    while(1){
        scanf("%d",&tam);
        if(tam == -1)break;
        int n = tam;
        for(int i = 1;i <= tam;i++){
            scanf("%d",&a);
            heap[i] = a;
        }
        Build_Max_Heap();
        ///pasos para extraer el máximo(esto es una priority queue o cola de prioridad)
        //Heap_Increase_Key(9,15);
        //int max2 = Heap_Extract_Max();
        //n--;
        //cout<<max2<<endl;
        ///fin de pasos para extraer el máximo
        ///pasos para insertar
        insertar(15);
        n++;
        ///fin de los pasos para insertar

        /** algorithmo Heapsort para ordenar un arreglo dado**/
        //Heapsort();
        for(int i = 1;i <= n;i++)
            cout<< heap[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
/***Ejemplo:
Input:
10
4 1 3 2 16 9 10 14 8 7
Output:
MAX_HEAP: 16 14 10 8 7 9 3 2 4 1
HEAPSORT: 1 2 3 4 7 8 9 10 14 16
***/
