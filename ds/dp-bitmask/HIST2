#include <iostream>
using namespace std;
long long int allmask,n,h[100];

long long int solve(int mask ,int i, int rect_id)
{
     long long int prev,curr,ans=0;
      cout<<"mask = "<<mask<<" i= "<<i<<" rect_id = "<<rect_id<<endl;
      if(mask == allmask)
        {
            return h[i];
        }
      if(rect_id > n)    
        return 0;  
        
      prev = i;    
      curr=0;
      for(i=1;i<=n;i++)
       {
            if(mask&(1<<(i-1)))
               continue;
            else
            { 
                
             curr =  max(curr , solve(mask|(1<<(i-1)) ,i, rect_id+1) + abs( h[i] - h[prev] ));
             cout<<"current perimeter "<<   curr<<endl;
             
            }
       }
       cout<<" returning answer of node is"<<curr<<endl;
       return curr;
}

int main() {
	
	 int i,mask;
	 cin>>n;
	 allmask = ((1<<n) - 1);
	 cout<<allmask<<endl;
	 h[0]=0;
	 for(i=1;i<=n;i++)
	    cin>>h[i];
	
	 mask =0 ;
	 cout<<solve(mask,0,1);
	  
	return 0;
}
