#include <iostream>
using namespace std;
#define ll long long 

ll maxXOR(ll l,ll r)
{
    ll p,c=0,ans;
    p = l ^ r;
    while(p)
    {
        p/=2;
        c++;
    }
    
    ans = (1ll<<c);
    ans--;
    return ans;
}
int main() {
	
	ll l,r;
	cin>>l>>r;
	cout<<maxXOR(l,r)<<endl;
	return 0;
}
