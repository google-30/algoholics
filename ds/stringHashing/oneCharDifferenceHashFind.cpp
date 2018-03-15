// problem link : http://codeforces.com/problemset/problem/514/C
//TEst Case : 
2 3
aaaaa
acacaca
aabaa
ccacacc
caaac

#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long 

ll pow1[5000010], pow2[5000010];
map< pair< ll ,ll > , bool  > f;
string s;
ll hash1()
{   ll h=0;
    int n = s.length();
    for(int i=0;i<n;i++)
      {
          h = (h + ((s[i]-'a'+1)*pow1[i])%M )%M;
          
      }
     return h; 
}

ll hash2()
{   ll h=0;
    int n = s.length();
    for(int i=0;i<n;i++)
      {
          h = (h + ((s[i]-'a'+1)*pow2[i])%M )%M;
          
      }
     return h; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pow1[0] = 1;
    pow2[0] = 1;
    ll i,n,m,h1,h2,j,k,g,l;
    for(i=1;i<=5000000;i++)
       {
           pow1[i] = (pow1[i-1]*29)%M;
           pow2[i] = (pow2[i-1]*31)%M;
       }
    
    
    cin>>n>>m;
    
    for(i=1;i<=n;i++)
     {
         cin>>s;
         f[{hash1(),hash2()}] = 1;
     }
    
    while(m--)
    {
        cin>>s;
        h1 = hash1();
        h2 = hash2();
        l = s.length();
        g=0;
        for(i=0;i<l;i++)
          {
              
              for(k=0;k<3;k++)
                {
                    if('a'+k != s[i])
                      {
                          
                          h1 = (h1 - ((s[i]-'a'+1)*pow1[i])%M + ((k+1)*pow1[i])%M + M )%M;
                          h2 = (h2 - ((s[i]-'a'+1)*pow2[i])%M + ((k+1)*pow2[i])%M + M )%M;
                          if(f[{h1,h2}] == 1)
                            {
                                g=1;
                                break;
                            }
                          
                          h1 = (h1 + ((s[i]-'a'+1)*pow1[i])%M - ((k+1)*pow1[i])%M + M )%M;
                          h2 = (h2 + ((s[i]-'a'+1)*pow2[i])%M - ((k+1)*pow2[i])%M + M )%M;
                          
                      }
                    
                }
              if(g)
                break;
          }
          
          
         if(g)
           cout<<"YES"<<"\n";
           else
           cout<<"NO\n";
           
    }
    
    return 0;
}
