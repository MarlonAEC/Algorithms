/**
@Autor: Marlon A. Espinosa Castañeiras
@Year: 2th of Computer Science(Cybernetic)
@Locate: Oriente University Santiago de Cuba
**/
#include <bits/stdc++.h>

#define oo 1 << 20 /// infinitum variable
#define F first ///define to use "first" variable on structures that uses this kind of variable
#define S second ///define to use "second" variable on structures that uses this kind of variable

using namespace std;

const int df[] = {-1, 0, 1,0,-1,-1, 1, 1};///constant array for search on graph matrix
const int dc[] = {0, 1, 0,-1,-1, 1, 1,-1};///constant array for search on graph matrix

int main()
{
    int a, b, t, r;
    char c;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        scanf("\n");
        scanf("%c",&c);
        scanf("\n");
        scanf("%d",&b);
        scanf("\n");
        scanf("%*c");
        scanf("\n");
        scanf("%d",&r);
        scanf("\n");

        if(c == '+'){
            if(a + b == r)
                printf("YES\n");
            else
                printf("NO\n");
        }
        if(c == '-'){
            if(a - b == r)
                printf("YES\n");
            else
                printf("NO\n");
        }
        if(c == '*'){
            if(a * b == r)
                printf("YES\n");
            else
                printf("NO\n");
        }
        if(c == '/'){
            if(a / b == r)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
