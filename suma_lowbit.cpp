#include <cstdio>
#include <iostream>

using namespace std;

int next_pot(int n)
{
    while(n % 2 != 0){
            n++;}
            return n;
}

int main(int argc, char *argv[])
{
 int a,b,sumA = 0,sumB = 0,i = 1, k = 1;
    
  scanf("%d %d",&a,&b);
  int r = next_pot(a);
  int l = next_pot(b);
   for(int j = 2;j <= r;j *= 2){
           sumA += ( a / j ) * i;
            //printf("%dj %di",j,i);
           i *= 2;
           }
           printf("%d\n",sumA);
          
   for(int j = 2;j <= l; j *= 2){
           sumB += ( b / j ) * k;           
           printf("%d \n",b/j);
           k *= 2;
           }
           printf("%d ",sumB);
           printf("%d\n",sumB - sumA);
    system("PAUSE");
    return 0;
}
