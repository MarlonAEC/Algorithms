#include <cstdio>
#include <iostream>

using namespace std;
int n=0;
void hanoi(char A,char B,char C, int n)
{
     if(n == 1){
       printf("%c -> %c\n", A, C);}
     else{
       hanoi('A','C','B',n - 1);
       hanoi('A','B','C',1);
       hanoi('B','A','C',n - 1);}
}

int pot = 1,sum;
int main()
{
scanf("%d",&n);
  hanoi('A','B','C', n);  
  
return 0;
}
