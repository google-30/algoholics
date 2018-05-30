// DETECT AND PRINT CYCLE IN UNDIRECTED GRAPH

#include <iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long int 
#define INF 1e18
int parent[300100],visited[300100];
vector<int>cycle;
vector<int>graph[300100];
vector<ll> dist(300100,INF);
queue<int>q;


void dfs(int i)
{
    visited[i]=1;
    for(auto it:graph[i])
      {
          if(visited[it]==0)
             {
                 parent[it] = i;
                 dfs(it);
             }
          else if(visited[it]==1 && parent[i]!=it){
              
              int curr_node = i;
              while(curr_node != it)
                {
                    cycle.push_back(curr_node);
                    curr_node = parent[curr_node];
                }
              cycle.push_back(it);    
          }
          
      }
    
    visited[i]=2;
}


int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	    int n,i,j,u,v;
	    cin>>n;
	    for(i=1;i<=n;i++)
	      {
	          cin>>u>>v;
	          graph[u].push_back(v);
	          graph[v].push_back(u);
	      }
	    
	    dfs(1);
	    for(auto it:cycle)
	      dist[it]=0;
      
		return 0;
}
