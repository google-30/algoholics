#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pii pair < ll , ll > 
ll n,m,D[400000],predecessor[400000];
vector<pii> graph[400000];

void dijkstras()
{
    ll u,dist;
    priority_queue <pii, vector<pii> , greater<pii>> pq; 
    for(ll i=1;i<=n;i++)
       D[i] = 1e18;
    
    D[1] = 0;
    pq.push({0,1});
    predecessor[1] = 0;
    
    while(!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        //cout<<"node == "<<p.second<<" dist==" <<p.first<<endl;
        dist = p.first;
        u = p.second;
        if(D[u] < dist)
           continue;
           
        for(auto it: graph[u])
         {
             if(dist+it.second < D[it.first])
              {
                  D[it.first] = dist+it.second;
                  pq.push({D[it.first] , it.first});
                  predecessor[it.first] = u;
              }
         }
    }
    
}

void print(int i)
{
    
    if(i)
      {
          print(predecessor[i]);
          cout<<i<<" ";
      }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll u,v,w;
    cin>>n>>m;
    
    for(ll i=1;i<=m;i++)
      {
          cin>>u>>v>>w;
          
          graph[u].push_back({v,w});
          graph[v].push_back({u,w});
          
      }
     
    dijkstras();
    if(D[n] == 1e18)
      cout<<-1;
    else
    print(n);
    cout<<endl;
     
    return 0;
}
