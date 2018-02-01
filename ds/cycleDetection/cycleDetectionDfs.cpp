#include <bits/stdc++.h>
using namespace std;

int visited[300010];
vector < int > graph[300010];

void dfs(int i)
{
    visited[i] = 2;
    for(auto it: graph[i])     
      {   
          //cycle detected
          if(visited[it] == 2)
             {
                 cout<<-1;
                 exit(0);
             }
          
          if(visited[it] == 0)
              dfs(it);
         
      }
    
    visited[i] = 1; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,i,j,u,v,ans=0;
    cin>>n>>m;
       
    while(m--)
      {
          cin>>u>>v;
          
          //self loop
          if(u == v)
             {   
                 cout<<-1;
                 exit(0);
             }
          graph[u].push_back(v);
          
      }
      
      
     for(i=1;i<=n;i++) 
       {
           if(!visited[i])
              dfs(i);
       }
       
  
	return 0;
}
