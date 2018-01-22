#include <iostream>
using namespace std;

#define M 1000000007
#define ll long long int 
ll fact[1000004];

bool checkExc(ll sum, ll a , ll b)
 {
     while(sum!=0)
     {   
         if(sum%10 != a && sum%10!=b)
           return false;
         
         sum/=10;
     }
     return true;
 }
// To compute x^y under modulo m
ll power(ll x, ll y,ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}

ll getC(ll n,ll r)
{
    ll num = fact[n];
    ll den = (fact[n-r] * fact[r])%M;
    ll inv = power(den , M-2 , M)%M;
    ll ans = (num*inv)%M;
    
    return ans;
}
int main() {
	
	
	ll ans=0,a,b,n,i,sum;
	cin>>a>>b>>n;
	fact[0] = 1;
	fact[1] = 1;
	
	for(i=2;i<=n;i++)
	  fact[i] = (fact[i-1]*i)%M;
	  
	for(i=0;i<=n;i++)
	{
	    sum = a*i + (n-i)*b;  
	    if(checkExc(sum,a,b))
	     {
	         //cout<<sum<<" "<<i<<" "<<n-i<<endl;
	         ans += getC(n,i);
	         ans%=M;
	     }
	    
	}
	cout<<ans%M<<endl;
	return 0;
}
