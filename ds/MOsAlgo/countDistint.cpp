#include <bits/stdc++.h>
#define ll long long
using namespace std;

// query node structure 
struct query {
    
    int left;
    int right;
    int index;
    int ans;
};

int block_size;
int a[300001];
int n,no_of_queries,currentL,currentR,countDistinct,l,r;
query q[300001];
int freq[2000001] , res[300001];

// comparator to sort in block size condition
bool compare(query a , query b)
{
    if(a.left/block_size != b.left/block_size)
        return a.left/block_size < b.left/block_size;
    
    return a.right < b.right;
}

// adding function to add elements in set 
void addvalue(int index)
{
    freq[a[index]]++;
    
    if(freq[a[index]] == 1)
      countDistinct++;
    
    return;
}

// remove function to remove elements from set 
void removeval(ll index)
{
    freq[a[index]]--;
    
    if(freq[a[index]] == 0)
      countDistinct--;
     
     return; 
    
}

void solveQueries()
{
    currentR = 0;
    currentL = 0;
    countDistinct =0 ;  
    for(int i=0;i<no_of_queries;i++)
    {
        l = q[i].left;
        r = q[i].right;
        
       // cout<<l<<" "<<r<<endl;
        while(currentL>l)
         {
             currentL--;
             addvalue(currentL);
         }
        
        while(currentR<r)
        {
            currentR++;
            addvalue(currentR);
        }
        while(currentL<l)
          {
              removeval(currentL);
              currentL++;
          }
        
        while(currentR>r)
        {
            removeval(currentR);
            currentR--;
        }
        
       // cout<<currentL<<" "<<currentR<<endl;
        
        q[i].ans = countDistinct;
    }
    
    
    
}


int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int i,j,n;
	cin>>n;
	memset(freq,0,sizeof(freq));
	
	block_size = sqrt(n);
	for(i=1;i<=n;i++)
	  cin>>a[i];
	  
	cin>>no_of_queries;  
	for(i=0;i<no_of_queries;i++)
	  {
	      cin>>q[i].left>>q[i].right;
          q[i].index = i;
	  }
	  
	 sort(q,q+no_of_queries,compare);
	 
	// for(i=1;i<=no_of_queries;i++)
	//    cout<<(q[i].left/block_size)<<" "<<q[i].left<<" "<<q[i].right<<endl;
	    
	    
	currentL = 0;
	currentR = 0;
	
	
	solveQueries();
	
	//cout<<"solution of queries "<<endl;
	
	for(i=0;i<no_of_queries;i++)
	  {
	    //  cout<<q[i].left<<" "<<q[i].right<<" "<<q[i].ans<<endl;
	      
	      res[q[i].index] = q[i].ans;
	      
	  }
	
	for(i=0;i<no_of_queries;i++)
	   cout<<res[i]<<"\n";
	return 0;
}
