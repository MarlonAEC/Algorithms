#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n;
int R[10001][17];

int expont(int n)
{
    int i = 1,cont = 0;
    while( i <= n){
        i *= 2;
        cont++;
    }
    cont--;
    return cont;
}

int A[10001];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d", &A[i]);
    for(int i = 1;i <= n;i++)
        R[i][0] = A[i];

    //cout<<expont(n)<<endl;

		int L = expont(n);
    for(int e = 1;e <= L;e++)
        for(int i = 1;i <= n - (1 << e) + 1;i++)
            R[i][e] = min( R[i][e - 1], R[i + (1 << (e - 1))][e-1]);

    int q,a,b;
    scanf("%d",&q);
    for(int i = 0;i < q;i++){
        scanf("%d%d", &a, &b);
				if (a > b){
					swap(a, b);
				}
        int r = expont(b - a + 1);
        printf("%d\n",min( R[a][r], R[b - (1 << r) + 1][r] ));
    }
    return 0;
}
