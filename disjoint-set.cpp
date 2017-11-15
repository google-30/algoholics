#include <iostream>
#include<algorithm>
using namespace std;
int a[1000001],size[1000001];
vector<int>res;

int root(int i)
{   // path compression technique 
	//directly jumping to the grandparent .
    while(a[i] != i)
       {  
           a[i] = a[a[i]];
           i = a[i];
       }
       
     return i;  
}


bool find(int u,int v)
{
    if(root(u) == root(v))   // connected
       return true;
    else
       return false;         // not connected
    
}

// union by rank algorithm
void weighted_union(int u,int v)
{
    int root_u = root(u);
    int root_v = root(v);
    if(root_u != root_v)
    
    {
    
      if(size[root_u] < size[root_v])
        {
          a[root_u] = root_v;
          
          size[root_v] += size[root_u];
          size[root_u] = 0;
        }
      else
       {
        a[root_v] = root_u;
        size[root_u] += size[root_v];
        size[root_v] =0;
       }
    }
}



void initialize(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {  a[i] = i;
       size[i] = 1;
    }
}

void print(int n)
{   int i;
    res.empty();
    res.clear();
    
    for(i=1;i<=n;i++)
     {   if(size[i]!=0)
           res.push_back(size[i]);
     }
     sort(res.begin(),res.end());
     
     for(i=0;i<res.size();i++)
       cout<<res[i]<<" ";
      cout<<endl;  
      
}
int main() {
	
	int t,n,i,u,v,m;
	cin>>n;
	
	initialize(n);
	cin>>m;
	while(m--)
	  {
	      cin>>u>>v;
	      weighted_union(u,v);
	      print(n);
	  }
	
	
	
	return 0;
}
