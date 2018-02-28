#include <iostream>
#include<cstring>
#include<math.h>
#include<vector>
#include<stdio.h>
using namespace std;
 long int dp[1048578][21];
int allotement[100][100],n,allmasks,g=0;
vector < int > v[100];
long long int  solve(int mask , int task_id)
{
    //cout<<mask<<" "<<task_id<<endl;
    
    long long int ans = 0,i,j;
    // base case for checking whether all tasks are alloted or not
    
    if(mask == allmasks)
      {
          // all tasks alloted 
          //cout<<" jbkekdb";
          return 1;
      }
    
    //    
    if(task_id > n)
      {
          return 0;
      }
      
    if( task_id > (__builtin_popcount (mask) +1 ))
          return 0;
    
    if(dp[mask][task_id] != -1)
     {   
         return dp[mask][task_id];
     }
    
   for(j=0;j<v[task_id].size();j++)
     {   //cout<<"masks: "<<mask<<" tid: "<<task_id<<endl;
         //cout<<"mask and allote info "<<i<<" "<<allotement[i][task_id]<<" "<<(mask&(1<<(i-1)))<<endl;
         i = v[task_id][j];
        if((mask&(1<<(i-1))))
          continue;
        else  
          {  //cout<<"hii";
             
             ans += solve( mask|(1<<(i-1)) , task_id+1); 
              
          }
         
     }
    dp[mask][task_id] = ans;
    return ans;
    
}


int main() {
	
	
	 int i,j,mask,t;
	scanf("%d",&t);
	 while(t--)
	 {
	 scanf("%d",&n);
	 for(i=1;i<=n;i++)
	      v[i].clear();
	 memset(dp,-1,sizeof(dp));
	 
	 allmasks = ((1 << n) - 1);
	 //cout<<allmasks<<endl;
	 for(i=1;i<=n;i++)
	   {
	       
	       for(j=1;j<=n;j++)
	         {
	             
	            // filling the matrix that is storing allotment of respective tasks to the person 
	            scanf("%d",&allotement[i][j]);
	              if(allotement[i][j] == 1)
	               v[j].push_back(i);
	             
	         }
	       
	   }
	
	mask = 0;
	printf("%lld\n",solve(mask,1));
	  
	 }
	
	return 0;
}
