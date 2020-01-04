#include <cstdio>
#include <iostream>

using namespace std;

int max_divisor(int m, int n)
{
    int nn;
     while(n != 0){
           nn = n;
           n = m % n;
           m = nn;
     }
     return m;
}

int main()
{
    int m, n, i, mm, nn, j;
    while( scanf("%d %d", &m, &n) != EOF){
         mm = m;
         nn = n;
         if(mm < nn){
              j = mm;
              mm = nn;
              nn = j;
         }
         i = max_divisor(mm,nn);
         printf("%d\n",i);
    }

    return 0;
}
