#include <cstdio>
#include <cstdlib>
#include <iostream>


using namespace std;
int mat[102][102];
int sol = -99999, n, m;

int d(int i,int j)
{
    //cout<< i<<" "<< j<<" "<< "\n";
    //system("PAUSE");
    if(i == 1){
        return mat[1][j];
    }
    else{
        int max2 = d(i - 1,j), x;
        if(j > 1){
            x = d(i - 1, j - 1);
            if (x > max2)
                max2 = x;
        }
        if(j < m){
            x = d(i - 1, j + 1);
            if (x > max2)
                max2 = x;
        }
        return max2 + mat[i][j];
    }
}

int F[50];
bool calc[50];
int fib(int n)
{
    if (calc[n])
        return F[n];
    if(n < 2)
        F[n] = n;
    else
        F[n] = fib(n - 1) + fib(n - 2);
    calc[n] = true;
    return F[n];
}

int M[50];
bool cond[50];
int fac(int n)
{
    if(!cond[n])
    {
        M[n] = n * fac(n - 1);
        cond[n] = true;
    }
    return M[n];
}

int C(int n){
    if (n < 2)
        return 1;
    int s = 0;
    for (int i = 0 ; i <= n ; i++)
        s += C(i) * C(n - i);
    return s;
}

int main()
{
    for (int i = 0 ; i < 6 ; i++)
        cout << C(i) << ' ';

    M[0] = 1;
    cond[0] = true;
    cout<< fac(5);
    /*
    cin>> n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
           cin>> mat[i][j];

    for(int i = 1;i <= m;i++){
        int x = d( n, i );
        if( x > sol )
           sol = x;

        cout<< sol<<endl;
    }
    printf("%d\n",sol);*/
    return 0;
}

/*
3 3
100 100 1
-100 -100 100
-100 -100 10
*/
