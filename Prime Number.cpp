#include <cstdio>

using namespace std;

bool prime(int n)
{
    if(n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;
    for(int i = 3;i * i <= n;i += 2)
        if(n % i == 0)
           return false;
    return true;
}

int main()
{
    int n,t;

    scanf("%d",&t);
    for(int i = 0;i < t ;i++){
        scanf("%d",&n);
        int nn,m;
        nn = n;
        m = n;
       while( !prime(nn)){
            nn--;
        }
        while(!prime(m)){
            m++;
        }
        printf("%d %d\n",nn,m);
    }
    return 0;
}
