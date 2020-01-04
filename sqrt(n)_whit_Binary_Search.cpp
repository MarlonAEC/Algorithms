#include <cstdio>
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

double mi_sqrt(double n)
{
    double ini = 0,fin = n,mitad;
    while( fin - ini > 0.000001){
        mitad = (fin + ini) / 2;
        if( mitad * mitad <= n ){
            ini = mitad;
        }
        else{
            fin = mitad;
        }
    }
    return ini;
}

int main()
{
    double n;

    scanf("%lf",&n);
    double sol = mi_sqrt(n);
    printf("%lf %lf",sol, sqrt(n));
    return 0;
}
