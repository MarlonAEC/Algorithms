/**
Author: Lic. Marlon Alejandro Espinosa Castañeiras
Github source: https://github.com/MarlonAEC/Algorithms.git

Algotihm: eight queens puzzle backtraking solution
The eight queens puzzle is the problem of placing eight chess queens on an 8×8
chessboard so that no two queens threaten each other; thus, a solution requires
that no two queens share the same row, column, or diagonal. The eight queens
puzzle is an example of the more general n queens problem of placing N
non-attacking queens on an N×N chessboard, for which solutions exist for
all natural numbers n with the exception of N = 2 and N = 3.

Programming Languaje: C++
Date: 01/01/2020
**/

#include <cstdio>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

#define N 4 /*variable for define the size of the matrix*/
#define const_conv_grad 57.29578 /* constant to convert from radians to degrees*/
#define par pair<int, int>

using namespace std;

vector<par> queens_position;
map<par, bool> existen_queen;
int solutions = 0;

bool threat(vector<par> partial_sol,int x, int y)
{
    for(int i = 0;i < (int)partial_sol.size();i++){
		double m = ((double)(y-partial_sol[i].second)) / ((double)(x - partial_sol[i].first));
		double slope = atan(m) * const_conv_grad;
		//checking that the new queen that is going to be put it is not threatened with those that were already there diagona(45, 135 degrees) and row (0 degrees) and column(90 degrees)
		if( (abs((int)slope) == 45) || (abs((int)slope) == 90) || (abs((int)slope) == 0) || (abs((int)slope) == 135) )
			return true;
    }
    return false;
}

//recursive function that finds the solutions
void backtrack(vector<par> sol, int amount_queens)
{
	if(amount_queens == N+1){ // if you have already put the N queens
		solutions++;
		cout<<"solution # "<<solutions<<endl;
		for(int i = 0;i < N;i++){
			cout<<"reina: "<<i+1<<" "<<sol[i].first <<", "<<sol[i].second<<"\n";
		}
		cout<<endl;
		cout<<"presione para continuar\n";
		getchar();
	}
	else{
		for(int i = 1;i <= N;i++){
			if(!threat(sol,amount_queens, i)){
				sol.push_back(make_pair(amount_queens,i)); //adding possible solution
				backtrack(sol,amount_queens + 1);
				sol.pop_back(); //removing those paths that were not solution
			}
		}
	}
}

int main()
{
	vector<par> initial;
	for(int i = 1;i <= N;i++){
		initial.push_back(make_pair(1,6));
		backtrack(initial,2);
		initial.clear();
	}
    return 0;
}
