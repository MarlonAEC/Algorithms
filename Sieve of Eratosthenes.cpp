#include <cstdio>
#include <cmath>
#include <iostream>

#define MAX 4000000
using namespace std;

int n;
bool flag[MAX];

void criba(int end)
{
   for(int i = 2;i <= end; i++)
        if(!flag[i])
           for(int j = i + i; j <= n ; j += i)
              flag[j] = true;
}

int main()
{
    scanf("%d",&n);

    criba((int) sqrt(n));

    for(int i = 2;i <= n;i++)
       if(!flag[i])
       printf("%d ",i);

    return 0;
}
