// Author : shubham Jain
// question link : http://codeforces.com/contest/86/problem/D
// topic : MO's Algorithm
// Time Complexity : O((N+Q)*sqrt(N))


#include <bits/stdc++.h>
#define ll long long
using namespace std;

// query node structure 
struct query {
    
    int left;
    int right;
    int index;
    ll ans;
};

int block_size;
int a[300001];
int n,no_of_queries,currentL,currentR,countDistinct,l,r;
query q[300001];
int freq[2000001];
ll res[300001];
ll currentAns=0;

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
    int currFrequency = freq[a[index]];
    
    currentAns = currentAns + ((1 + 2*currFrequency)*a[index]);
    freq[a[index]]++;
    return;
}

// remove function to remove elements from set 
void removeval(int index)
{
    int currFrequency = freq[a[index]];
    
    currentAns = currentAns + ((1 - 2*currFrequency)*a[index]);
    freq[a[index]]--;
    
    return;
  
}

void solveQueries()
{
    currentR = 0;
    currentL = 0;
    currentAns=0; 
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
        
        res[q[i].index] = currentAns;
    }
    
    
    
}


int main() {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int i,j,n;
	cin>>n>>no_of_queries;
	memset(freq,0,sizeof(freq));
	
	block_size = sqrt(n);
	for(i=1;i<=n;i++)
	  cin>>a[i];
	  
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
	   cout<<res[i]<<"\n";
	return 0;
}
