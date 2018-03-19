//problem link --- https://www.hackerearth.com/challenge/competitive/airtel-crack-the-code/algorithm/longest-path-fecb5ecc/

#include <bits/stdc++.h>
using namespace std;
vector< int > graph[100010];
int visited[100010];
vector<int> v[100010];
int dp[100010],a[100010];

void dfs(int i)
{
    visited[i] = 1;
    //cout<<i<<endl;
    for(auto it:graph[i])
      {   
          if(visited[it])
             continue;
             
          if(!visited[it])
           dfs(it);
          
          //updating current node from childs
          if(a[i]==0)
             dp[i]=0;
         else
         {
          dp[i] = max(dp[i] , dp[it]+1);
          v[i].push_back(dp[it]+1);                
         }
          
      }
      
    //cout<<i<<"th "<<dp[i]<<endl;  
}
int main() {
	
	memset(visited,0,sizeof(visited));
	int n,k,i,j,t,u,vv,ans;
	cin>>n>>k;
	for(i=1;i<=n;i++) 
	  {
	      cin>>t;
	      if(t%k==0)
	        a[i]=1,dp[i]=1;
	      else
	        a[i]=0,dp[i]=0;
	  }
	

	for(i=1;i<n;i++)
	 {
	     cin>>u>>vv;
	     graph[u].push_back(vv);
	     graph[vv].push_back(u);
	     
	     
	 }
	 
	 dfs(1);
	 ans=0;
	 for(i=1;i<=n;i++)
	   {
	       //cout<<i<<" "<<dp[i]<<" vector-->";
	       sort(v[i].begin(),v[i].end(),greater<int>());
	       if(v[i].size()==1)
	          ans = max(ans,v[i][0]-1);
	       else if(v[i].size()>=2)
	         {
	             ans = max(ans, v[i][0]+v[i][1]-2);
	         }
	   }
	 cout<<ans<<endl;
	return 0;
}
