// PROBLEM LINK ----  http://codeforces.com/contest/369/problem/C
// TOPIC ----- DFS-ON-TREES

#include <bits/stdc++.h>
using namespace std;
bool visited[100011];
vector < pair < int , int > > graph[100011];
vector < int > ans;
int dfs(int node)
{
    visited[node] = true;
    int count=0,type,child,below,i;
   
    for(auto it : graph[node])
      {
          
          child = it.first;
          type =  it.second;
          
        
          if(!visited[child])
          {
          below = dfs(child);
          
            if(below == 0 && type==2)
              {
               
                  ans.push_back(child);
                  count++;
            
              }
            else
              count+=below;
            
          }
      }
    
      return count;
}

int main() {

    
    
    int n,i,u,v,type;
    cin>>n;
    
    for(i=1;i<n;i++)
      {
          cin>>u>>v>>type;
          
          graph[u].push_back({v,type});
          graph[v].push_back({u,type});
      }
    
     cout<<dfs(1)<<endl;
     
     for(int nodes : ans)
     {
         cout<<nodes<<" ";
     }
	return 0;
}

/*  INPUT 
5
1 2 1
2 3 2
2 4 1
4 5 1
*/

/*  OUTPUT
1
3
*/
