/**
Marlon A. Espinosa Castañeiras
28-02-2013
Structure: Binary Search Tree
Description: Used to enter values and search for items in a tree
in logarithmic time, the
maximum, minimum, successor, predecessor, delete functions
elements, search for an element in-Order in a tree and explain how
to implement the other paths, all this in time O (log N).
**/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

typedef int TData;

vector <int> V;
struct TNode{
    TNode* p;//father
	TData dato;//Node
	TNode* lc;//left child
	TNode* rc;//rigth child
};

typedef TNode* TTree;//pointer to a tree

TTree InsertDato(TTree& A, TData x){
	if (A == NULL){
		A = new TNode;//reserving memory space;
		A -> dato = x;
		A -> p = NULL;//setting the root childs to NULL and also  the father of the root
		A -> lc = NULL;
		A -> rc = NULL;
	}
	else{
	    // it is searched if it is smaller than the analyzed node and inserted into the subtree representing the left child
		if (A -> dato >= x){
			A -> lc = InsertDato(A -> lc, x);
			A -> lc -> p = A;
        }
        //the same but looking for the major and inserted in the right subtree
		else{
			A -> rc = InsertDato(A -> rc, x);
			A -> rc -> p = A;
        }
	}
	return A;// the tree generated after insertion is returned
}

/***
Note:For the other routes you only need to change
the position in which the node is printed.
***/
void inOrder(TTree A){
    /**** in-Orden path ****/
	if (A == NULL)
		return;
	if (A -> lc != NULL)
		inOrder(A -> lc);
	cout << A -> dato << " ";
	if (A -> rc != NULL)
		inOrder(A -> rc);
}

TTree Search(TTree A, TData x)
{
	while (A != NULL && A -> dato != x){
/*If the search is smaller than the analyzed node, I look in the left subtree*/
		if (x < A -> dato)
			A = A -> lc;
/*If the search is greater than the analyzed node, I look in the right subtree*/
		else
			A = A -> rc;
	}
	if (A == NULL)
		return NULL;
	return A;

/** Recursive Search Implementation**/
/*  if(A == NULL)
		return NULL;
	if(A-> dato == x)
		return A;
	if(A -> dato > x)
		return Buscar(A -> lc, x);
	return Buscar(A -> rc, x);
	*/
}/**OK**/

TTree Minimum(TTree A){
//Finding the minimum is nothing more than always taking the
//leftmost node while there is one
	while( A -> lc != NULL)
        A = A -> lc;
    return A;
}


TTree Maximum(TTree A){
//The same as the minimum but looking for the rightmost while there is one
	while(A -> rc != NULL)
        A = A -> rc;
    return A;
}

TTree Succesor(TTree AA)
{
/*If you have a right child, look in the right subtree
to the minimum, since to the right of the node are the largest
that he kept the minimum of them
 */
    if(AA -> rc != NULL)
        return Minimum(AA -> rc);
/*
If you do not have a right child, I am exchanging a child with a father
and when the son is not the right son of the father I return the
father and that is the successor of the requested node.
*/
    TTree y = AA -> p;
    while(y != NULL && AA == y -> rc){
        AA = y;
        y = y -> p;
    }
    return y;
}

TTree Predecessor(TTree AA)
{
/*If you have a left child, I look in the right subtree
the minimum, since to the left of the node are the largest
that he stayed with the maximum of them
 */
    if(AA -> lc != NULL)
        return Maximum(AA -> lc);
    TTree y = AA -> p;
/*
If you don't have a left child, I'm exchanging a son with a father
and when the son is not the left son of the father I return
the father and that is the predecessor of the requested node.
*/
    while(y != NULL && AA == y -> lc){
        AA = y;
        y = y -> p;
    }
    return y;
}

TTree Transplant(TTree& u, TTree& v)
{
/**Auxiliary Function for Delete**/
    if(u -> p == NULL){
        v -> lc = u -> lc;
        v -> rc = u -> rc;
        v -> p = NULL;
    }
    else if(u == u -> p -> lc)
        u -> p -> lc = v;
    else
        u -> p -> rc = v;
    if(v != NULL)
        v -> p = u -> p;
}

TTree Delete(TTree AA, TTree z)
{
/*
If you don't have a left child, I overwrite the node with your child
right
*/
    if(z -> lc == NULL)
        Transplant(z, z -> rc);
/*
If you don't have a right child, I overwrite the node with your left child

*/
    else if(z -> rc == NULL)
        Transplant(z, z -> lc);
/*
If you have both children I look for your successor who is
in its right subtree and I overwrite the node with its
right subtree because it has no left subtree, because
if It had it wouldn´t a successor of the node to delete, then
I overwrite the node to delete with that node and set the
respective children and parents
*/
    else{
        TTree y = Minimum( z -> rc);
        if(y -> p != z){
            Transplant(y, y -> rc);
            y -> rc = z -> rc;
            y -> rc -> p = y;
        }
        Transplant(z, y);
        y -> lc = z -> lc;
        y -> lc -> p = y;
    }
}

bool Succesor(TTree A, TData x, TData& suc){
    /**Función obtimizada para buscar el Sucesor*/
/*
Returns false if the tree is empty or if the node to which
the successor is sought is the maximum node of the tree, and
returns true if the node exists and with the call
by reference the value of that successor is set.
*/
    TTree Nod = Search(A, x);
    if (A == NULL)
        return false;
    Nod = Succesor(Nod);
    if (Nod == NULL)
        return false;
    suc = Nod -> dato;//setting the value by reference
    return true;
}

TTree ABB;

int main(){
	assert(ABB == NULL);//Interrupt the program if the tree is not set to NULL

	for(int i = 0;i <= 10;i++){
        int x = rand() % 100;/*random insertions*/
        V.push_back(x);/*To know the order and the nodes that were inserted to the ABB*/
        InsertDato(ABB, x);
	}

	cout<< "Order of the nodes:"<<endl;
	for(int i = 0;i < V.size();i++)
        cout<< V[i]<<" ";
    cout<< "\n\n";

    cout<< "Selected node: "<<V[0]<< "\n";
    cout<< "Predecessor: "<<Predecessor( Search( ABB,V[0] ) ) -> dato<<"\n";
    TData succesor;
    if (Succesor(ABB, V[0], succesor))
        cout << "Succesor: "<<succesor<<"\n";
    cout<<"Maximum in the Binary Search Tree: "<< Maximum(ABB) -> dato <<"\n";
    cout<<"Minimum in the Binary Search Tree: "<<Minimum(ABB) -> dato <<"\n\n";
    cout<< "In-Order path before a DELETE:"<<"\n";
    inOrder(ABB);
    cout<<"\n";
    cout<< "Recorrido en Entre-Orden despues de un DELETE:"<<"\n";
    Delete( ABB, Search(ABB, V[0]) );
    inOrder(ABB);
    cout<<"\n";
	return 0;
}
