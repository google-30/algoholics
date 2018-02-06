#include <iostream>
#include<cstring>
#include<vector>
using namespace std;

vector< int > graph[400000];
int n,col[400000];
void dfs(int curr, int prev)
{
     int c=1;
    
     for(auto it: graph[curr])
      {
          if(it == prev)
            continue;
            
          while(c==col[curr] || (prev!=-1 && col[prev] == c))
            c++;
          
          col[it] = c;
          
          dfs(it,curr);
          c++;
      }

    
}

int main() {

    int u,v,i,j,ans=0;
    cin>>n;
    memset(col,-1,sizeof(col));
    for(i=1;i<n;i++)
      {
          cin>>u>>v;
          graph[u].push_back(v);
          graph[v].push_back(u);
      }
    col[1] = 1;
    dfs(1,-1);
      
    for(i=1;i<=n;i++)
      {
          int temp = graph[i].size();
          ans = max(ans,temp);
      }
      
      cout<<ans<<endl;
      
      for(i=1;i<=n;i++)
        cout<<col[i]<<" ";
        cout<<endl;
	return 0;
}
