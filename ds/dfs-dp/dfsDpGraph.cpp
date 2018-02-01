// problem link -- http://codeforces.com/contest/919/problem/D
// dfs + dp on graphs ( along with cycle detection )

#include <bits/stdc++.h>
using namespace std;

int visited[300010];
int dp[300010][27];
vector < int > graph[300010];
string s;
    

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
        
          //updating current node from its child nodes
          for(int j=0;j<26;j++)      
            dp[i][j] = max(dp[i][j] , dp[it][j]);     
      }
      
    //update current node
    dp[i][s[i]-'a']++;
    
    visited[i] = 1; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,i,j,u,v,ans=0;
    cin>>n>>m;
    cin>>s;
    s = '#' + s;
 
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
       
     for(i=1;i<=n;i++)
     {
         for(j=0;j<26;j++)
           ans = max(ans,dp[i][j]);
     }
     
     cout<<ans;  
	return 0;
}
