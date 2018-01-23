#include <iostream>
#include<cstring>
#include<vector>
using namespace std;
vector < int > employees[200000];
vector< int> lang[200000];
int visited_emp[200000],visited_lang[200000];
void dfsonlan(int i);

void dfsonemp(int i)
{
    visited_emp[i] = 1;
    
    for(auto it : employees[i])
     {
         if(!visited_lang[it])
            dfsonlan(it);
     }
    
}
void dfsonlan(int i)
{
    visited_lang[i] = 1;
    
    for(auto it: lang[i])
    {
        if(!visited_emp[it])
           dfsonemp(it);
    }
}
int main() {
	
	int n,m,i,j,k,l,connected_component=0,flag=0;
	memset(visited_emp,0,sizeof(visited_emp));
	memset(visited_lang,0,sizeof(visited_lang));
	
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
	    cin>>k;
	    for(j=1;j<=k;j++)
	     {   flag=1;
	         cin>>l;
	         employees[i].push_back(l);
	         lang[l].push_back(i);
	     }
	    
	}
	
	for(i=1;i<=n;i++)
	  {
	      if(visited_emp[i] == 0)
	         connected_component++ , dfsonemp(i);
	  }
	  
	  if(flag)
	  cout<<connected_component-1<<endl;
	  else
	  cout<<n<<endl;
	return 0;
}
