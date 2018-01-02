#include <bits/stdc++.h>
using namespace std;
#define MIN 0
#define ll long long
ll segtree[4000000],a[1000000],lazy[4000000],n;

void build_tree(ll ss , ll se , ll node)
 {
     
     if(ss == se)
       {
          
           segtree[node] = a[ss];
           return;
       }
     
     int mid = (ss+se)/2;
     
     // recursively move to left tree
     build_tree(ss,mid,node*2+1);
     
     //recursively move to right tree
     build_tree(mid+1,se,node*2+2);
     
     // updating parent
     segtree[node] = segtree[node*2+1] + segtree[node*2+2];
     
 }

void update_tree(ll ss, ll se, ll l , ll r, ll node)
 {
     
     if(lazy[node] != 0)
      {
          
          segtree[node] = (se-ss+1) - segtree[node];
          //not a child node
          if(ss != se)
          {   int l = (se-ss+1);
              lazy[node*2+1] = 1 - lazy[node*2+1];
              lazy[node*2+2] = 1 - lazy[node*2+2];
          }
          
          lazy[node] = 0;
      }
     
     
     // no overlap
     if(se<l || ss>r)  
        return;
     
     // full overlap
     if(ss>=l && se<=r)
      {
          segtree[node] = (se-ss+1) - segtree[node];
          if(ss!=se)
           {
              int l = (se-ss+1);
              lazy[node*2+1] = 1 - lazy[node*2+1];
              lazy[node*2+2] = 1 - lazy[node*2+2];
           }
           
           return;
         
      }
     
     
     // partial overlap
     
     int mid = (ss+se)/2;
     update_tree(ss,mid,l,r,node*2+1);
     update_tree(mid+1,se,l,r,node*2+2);
     
     segtree[node] = segtree[node*2+1] + segtree[node*2+2];
     
     
 }

ll  query_tree(ll ss, ll se, ll l , ll r, ll node)
{
    
    if(lazy[node] != 0)
      {
          
          segtree[node] = (se-ss+1) - segtree[node];
          //not a child node
          if(ss != se)
          {
              int l = (se-ss+1);
              lazy[node*2+1] = 1 - lazy[node*2+1];
              lazy[node*2+2] = 1 - lazy[node*2+2];
          }
          
          lazy[node] = 0;
      }
     
     // no overlap
     if(se<l || ss>r)  
        return 0;
     
     // full overlap
     if(ss>=l && se<=r)
          return segtree[node];
     
     
     
     // partial overlap
     
     int mid = (ss+se)/2;
     int r1 = query_tree(ss,mid,l,r,node*2+1);
     int r2 = query_tree(mid+1,se,l,r,node*2+2);
     
     
     return r1+r2;
}

void print_tree()
{
    
    for(int i=0;i<7;i++)
      cout<<segtree[i]<<" ";
    
    cout<<endl;
    
    for(int i=0;i<7;i++)
      cout<<lazy[i]<<" ";
    
    cout<<endl;
}

int main() {
	
	   ios_base::sync_with_stdio(false);
       cin.tie(NULL);
	   char ch;
	  ll n,i,j,l,r,val,q,type;
	   cin>>n>>q;
	   memset(lazy, 0 ,sizeof(lazy));
	   // adding the values in array
	   for(i=0;i<n;i++)
	     a[i] = 0;
	     
       
       //build the tree	     
	   build_tree(0,n-1,0);
	   
	 // print_tree();
	   while(q--)
	    {
	        cin>>type;
	        if(type == 0)
	          {
	              cin>>l>>r;
	              update_tree(0,n-1,l-1,r-1,0);
	            //  print_tree();
	          }
	        else
	        {
	            cin>>l>>r;
	            cout<<query_tree(0,n-1,l-1,r-1,0)<<endl;
	            // print_tree();
	          
	        }
	        
	        
	    }
	
	return 0;
}
