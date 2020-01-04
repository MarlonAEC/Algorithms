/**
Marlon A. Espinosa Casta�eiras
28-02-2013
Estructura: �rbol de Busqueda Binaria
Descripci�n: Sirve para introducir valores y buscar elementos en un �rbol
en tiempo logaritmico, adem�s estan implementadas las
funciones m�ximo, m�nimo, sucesor, predecesor, borrar
elementos, buscar un elemento en el �rbol, recorrido
Entre-Orden en un �rbol y se expone como implementar los
dem�s recorridos, todo esto en tiempo O( log N ).
**/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef int TDato;

vector <int> V;
struct TNodo{
    TNodo* p;//Padre
	TDato dato;//Nodo
	TNodo* hi;//Hijo izquierdo
	TNodo* hd;//Hijo derecho
};

typedef TNodo* TArbol;//puntero a un nodo del Arbol

TArbol InsertDato(TArbol& A, TDato x){
	if (A == NULL){
		A = new TNodo;//se crea espacio en memoria;
		A -> dato = x;
		A -> p = NULL;//se setea los hijos de el root en NULL y tambi�n el padre
		A -> hi = NULL;
		A -> hd = NULL;
	}
	else{
	    // se busca si es menor que el nodo analizado y se inserta en el subarbol que representa el hijo izquierdo
		if (A -> dato >= x){
			A -> hi = InsertDato(A -> hi, x);
			A -> hi -> p = A;
        }
        //lo mismo pero buscando el mayor y se inserta en el subarbol derecho
		else{
			A -> hd = InsertDato(A -> hd, x);
			A -> hd -> p = A;
        }
	}
	return A;// se devuelve el �rbol generado luego de la inserci�n
}/**OK**/

/***
Nota: Para los dem�s recorridos solo se necesita cambiar
la posici�n en la que se imprime el nodo.
***/
void EntreOrden(TArbol A){
    /**** Recorriodo en Entre-Orden ****/
	if (A == NULL)
		return;
	if (A -> hi != NULL)
		EntreOrden(A -> hi);
	cout << A -> dato << " ";
	if (A -> hd != NULL)
		EntreOrden(A -> hd);
}/**OK**/

TArbol Buscar(TArbol A, TDato x)
{
	while (A != NULL && A -> dato != x){
/*si el buscado es menor que el nodo analizado busco en el subarbol izquierdo*/
		if (x < A -> dato)
			A = A -> hi;
/*si el buscado es mayor que el nodo analizado busco en el subarbol derecho*/
		else
			A = A -> hd;
	}
	if (A == NULL)
		return NULL;
	return A;

/** Implementaci�n Recursiva de la busqueda**/
/*  if(A == NULL)
		return NULL;
	if(A-> dato == x)
		return A;
	if(A -> dato > x)
		return Buscar(A -> hi, x);
	return Buscar(A -> hd, x);
	*/
}/**OK**/

TArbol Minimo(TArbol A){
//Buscar el m�nimo no es m�s que siempre cojer el nodo m�s
//a la izquierda mientras exista alguno
	while( A -> hi != NULL)
        A = A -> hi;
    return A;
}/**OK**/


TArbol Maximo(TArbol A){
//Lo mismo que el m�nimo pero buscando el m�s a la derecha
//minetras exista alguno
	while(A -> hd != NULL)
        A = A -> hd;
    return A;
}/**OK**/

TArbol Sucesor(TArbol AA)
{
/*Si tiene hijo derecho busco en el subarbol derecho
el m�nimo, ya que a la derecha del nodo est�n los mayores
que el me quedo con el m�nimo de ellos
 */
    if(AA -> hd != NULL)
        return Minimo(AA -> hd);
    TArbol y = AA -> p;
/*
Si no tiene hijo derecho voy intercambiando hijo con padre
y cuando el hijo no sea el hijo derecho del padre devuelvo el
padre y ese es el sucesor del nodo pedido.
*/
    while(y != NULL && AA == y -> hd){
        AA = y;
        y = y -> p;
    }
    return y;
}/**OK**/

TArbol Predecessor(TArbol AA)
{
/*Si tiene hijo izquierdo busco en el subarbol derecho
el m�nimo, ya que a la izquierda del nodo est�n los mayores
que el me quedo con el m�ximo de ellos
 */
    if(AA -> hi != NULL)
        return Maximo(AA -> hi);
    TArbol y = AA -> p;
/*
Si no tiene hijo izquierdo voy intercambiando hijo con padre
y cuando el hijo no sea el hijo izquierdo del padre devuelvo
el padre y ese es el predecesor del nodo pedido.
*/
    while(y != NULL && AA == y -> hi){
        AA = y;
        y = y -> p;
    }
    return y;
}/**OK**/

TArbol Transplant(TArbol& u, TArbol& v)
{
/**Funci�n Auxiliar para el Delete**/
    if(u -> p == NULL){
        v -> hi = u -> hi;
        v -> hd = u -> hd;
        v -> p = NULL;
    }
    else if(u == u -> p -> hi)
        u -> p -> hi = v;
    else
        u -> p -> hd = v;
    if(v != NULL)
        v -> p = u -> p;
}/**OK**/

TArbol Delete(TArbol AA, TArbol z)
{
/*
Si no tiene hijo izquierdo sobrescribo el nodo con su hijo
derecho
*/
    if(z -> hi == NULL)
        Transplant(z, z -> hd);
/*
Si no tiene hijo derecho sobrescribo el nodo con su hijo
izquierdo
*/
    else if(z -> hd == NULL)
        Transplant(z, z -> hi);
/*
Si tiene los dos hijos  busco su sucesor que se encuentra
en su subarbol derecho y sobrescribo el nodo Y con su
subarbol derecho porque no tiene subarbol izquierdo, porque
si lo tuviera no fuera sucesor del nodo a borrar, luego
sobreescribo el nodo a borrar con el nodo Y y seteo los
respectivos hijos y padres
*/
    else{
        TArbol y = Minimo( z -> hd);
        if(y -> p != z){
            Transplant(y, y -> hd);
            y -> hd = z -> hd;
            y -> hd -> p = y;
        }
        Transplant(z, y);
        y -> hi = z -> hi;
        y -> hi -> p = y;
    }
}/**OK**/

bool Sucesor(TArbol A, TDato x, TDato& suc){
    /**Funci�n obtimizada para buscar el Sucesor*/
/*
Devuelve falso si el arbol esta bac�o o si el nodo al cual
se le busca el sucesor es el m�ximo nodo del arbol, y
devuelve verdadero si el nodo existe y con la llamada
por referencia se setea el valor de ese sucesor.
*/
    TArbol Nod = Buscar(A, x);
    if (A == NULL)
        return false;
    Nod = Sucesor(Nod);
    if (Nod == NULL)
        return false;
    suc = Nod -> dato;//seteo de valor por referencia
    return true;
}/**OK**/

TArbol ABB;

int main(){
	assert(ABB == NULL);//interumpe el programa si no se setea el �rbol a NULL

	for(int i = 0;i <= 10;i++){
        int x = rand() % 100;/*Se hacen inserciones aleatorias*/
        V.push_back(x);/*Para seber el orden y los nodos que se introdujeron al ABB*/
        InsertDato(ABB, x);
	}
	//sort(V.begin(),V.end());
	cout<< "Orden en que se introdujeron los nodos:"<<endl;
	for(int i = 0;i < V.size();i++)
        cout<< V[i]<<" ";
    cout<< "\n\n";

    cout<< "Nodo seleccionado: "<<V[0]<< "\n";
    cout<< "Predecessor: "<<Predecessor( Buscar( ABB,V[0] ) ) -> dato<<"\n";
    TDato sucesor;
    if (Sucesor(ABB, V[0], sucesor))
        cout << "Sucesor: "<<sucesor<<"\n";
    cout<<"Maximo en el Arbol de Busqueda Binaria: "<< Maximo(ABB) -> dato <<"\n";
    cout<<"Minimo en el Arbol de Busqueda Binaria: "<<Minimo(ABB) -> dato <<"\n\n";
    cout<< "Recorrido en Entre-Orden antes de un DELETE:"<<"\n";
    EntreOrden(ABB);
    cout<<"\n";
    cout<< "Recorrido en Entre-Orden despues de un DELETE:"<<"\n";
    Delete( ABB, Buscar(ABB, V[0]) );
    EntreOrden(ABB);
    cout<<"\n";
	return 0;
}
