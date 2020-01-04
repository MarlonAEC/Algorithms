#include <cstdio>
#include <iostream>
#include <cstdlib>

#define MAXD 1001
using namespace std;

struct bignum
{
  int lon;
  int d[MAXD];
};

void printf_bignum( bignum n )
{
   for(int i = n.lon - 1;i > -1;i--)
       printf("%d",n.d[i]);
}//imprimir_bignum

bignum  string_to_bignum(string s)
{
  bignum r;
  r.lon = 0;
    for(int i = s.length()-1;i > -1;i--)
            r.d[r.lon++] = s[i] - 48;
    return r;
}//conversion_hacia_bignum

bignum suma_de_bignum(bignum a,bignum b)
{
  bignum r;
  r.lon = 0;
  int carry = 0,m,x;
  m = a.lon < b.lon ? a.lon : b.lon;

    for(int i = 0;i < m;i++)
    {
       r.d[r.lon] = (x = (a.d[i] + b.d[i] + carry)) % 10;
       r.lon++;
    }
    if(x > 9)
       carry = 1;
    else
       carry = 0;
    if(a.lon < b.lon)
    {
       for(int i = m;i < b.lon;i++)
       {
         r.d[r.lon] = ( x =(b.d[i] + carry)) % 10;
         r.lon++;
       }
       if(x > 9)
         carry = 1;
       else
         carry = 0;
    }
    else
    {
        for(int i = m;i < a.lon;i++)
        {
          r.d[r.lon] = (x = (a.d[i] + carry)) % 10;
          r.lon++;
        }
        if(x > 9)
           carry = 1;
        else
           carry = 0;
    }
    if(carry == 1)
    {
      r.d[r.lon] = 1;
      r.lon++;
    }

   return r;
}//bignum_suma

bignum resta_de_bignum(bignum a,bignum b)
{
   bignum r;
   r.lon = 0;
   int carry = 0,m,x;
   m = a.lon < b.lon ? a.lon : b.lon;
   for(int i = 0;i < m;i++)
   {
      r.d[r.lon] = abs(x = a.d[i] - (b.d[i] + carry)) % 10;
      r.lon++;
   }
   if(a.lon < b.lon)
   {
      carry = 1;
      for(int i = m;i < b.lon;i++)
       {
         r.d[r.lon] = ( x =(b.d[i] - carry)) % 10;
         r.lon--;
       }
   }
   else
   {
      carry = 0;
      for(int i = m;i < a.lon;i++)
        {
          r.d[r.lon] = (x = (a.d[i] + carry)) % 10;
          r.lon++;
        }
   }
   return r;
}//bignum_resta

int main()
{
 string s1,s2;
    cin>>s1>>s2;

    bignum a = string_to_bignum(s1);
    bignum b = string_to_bignum(s2);

    bignum r = suma_de_bignum(a,b);
    bignum d = resta_de_bignum(a,b);
    printf_bignum( r );
    printf("\n");
    printf_bignum( d );
    printf("\n");

    //system("pause");
    return 0;
}
