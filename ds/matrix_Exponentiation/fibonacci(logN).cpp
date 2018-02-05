#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int 

void multiply(ll F[2][2], ll M[2][2]);

void power(ll F[2][2], ll n);
ll k,coss1,coss2,first,second;
/* function that returns nth Fibonacci number */

void print(ll F[2][2])
{
    cout<<endl<<"MATRIX "<<endl;
    
    for(int i=0;i<2;i++)
     {for(int j=0;j<2;j++)
       cout<<F[i][j]<<" ";
       cout<<endl;
     }
 
}

ll fib(ll n)
{
ll F[2][2] = {{2,3},{1,0}};
if (n == 0)
	return 0;
	
power(F, n-1);
print(F);

return 5*F[0][0] + 7*F[0][1];

}

/* Optimized version of power() in method 4 */
void power(ll F[2][2], ll n)
{
if( n == 0 || n == 1)
	return;
 
 ll M[2][2] = {{2,3},{1,0}};
 
power(F, n/2);
multiply(F, F);

if (n%2 != 0)
	multiply(F, M);
	
}



void multiply(ll F[2][2], ll M[2][2])
{
    
ll x = ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
ll y = ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
ll z = ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
ll w = ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;


F[0][0] = x;
F[0][1] = y;
F[1][0] = z;
F[1][1] = w;

}

ll inverse(ll x, ll y,ll m)
{
    if (y == 0)
        return 1;
    ll p = inverse(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}
/* Driver program to test above function */
int main()
{
   ll n = 9,ans,t,l,d,inv;
  //cout<<fib(14)<<endl;
   //k = 500000004;
  for(int j=0;j<=100;j++)
        cout<<j<<" "<<fib(j)<<endl;

return 0;
}
