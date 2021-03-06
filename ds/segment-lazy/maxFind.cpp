#include <bits/stdc++.h>
using namespace std;
#define MIN 0
int segtree[4000000],a[1000000],lazy[4000000],n;

void build_tree(int ss , int se , int node)
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
     segtree[node] = max( segtree[node*2+1] , segtree[node*2+2]);
     
 }

void update_tree(int ss, int se, int l , int r, int val , int node)
 {
     
     if(lazy[node] != 0)
      {
          
          segtree[node] += lazy[node];
          //not a child node
          if(ss != se)
          {
              lazy[node*2+1] += lazy[node];
              lazy[node*2+2] += lazy[node];
          }
          
          lazy[node] = 0;
      }
     
     
     // no overlap
     if(se<l || ss>r)  
        return;
     
     // full overlap
     if(ss>=l && se<=r)
      {
          segtree[node] += val;
          if(ss!=se)
           {
               
               lazy[node*2+1] += val;
               lazy[node*2+2] += val;
               
           }
           
           return;
         
      }
     
     
     // partial overlap
     
     int mid = (ss+se)/2;
     update_tree(ss,mid,l,r,val,node*2+1);
     update_tree(mid+1,se,l,r,val,node*2+2);
     
     segtree[node] = max(segtree[node*2+1] , segtree[node*2+2]);
     
     
 }

int query_tree(int ss, int se, int l , int r, int node)
{
    
    if(lazy[node] != 0)
      {
          
          segtree[node] += lazy[node];
          //not a child node
          if(ss != se)
          {
              lazy[node*2+1] += lazy[node];
              lazy[node*2+2] += lazy[node];
          }
          
          lazy[node] = 0;
      }
     
     // no overlap
     if(se<l || ss>r)  
        return MIN;
     
     // full overlap
     if(ss>=l && se<=r)
          return segtree[node];
     
     
     
     // partial overlap
     
     int mid = (ss+se)/2;
     int r1 = query_tree(ss,mid,l,r,node*2+1);
     int r2 = query_tree(mid+1,se,l,r,node*2+2);
     
     
     return max(r1,r2);
}

void print_tree()
{
    
    for(int i=0;i<13;i++)
      cout<<segtree[i]<<" ";
    
    cout<<endl;
    
    for(int i=0;i<13;i++)
      cout<<lazy[i]<<" ";
    
    cout<<endl;
}

int main() {
	
	   ios_base::sync_with_stdio(false);
       cin.tie(NULL);
	   char ch;
	   int n,i,j,l,r,val,q;
	   cin>>n>>q;
	   memset(lazy, 0 ,sizeof(lazy));
	   // adding the values in array
	   for(i=0;i<n;i++)
	     cin>>a[i];
	     
       
       //build the tree	     
	   build_tree(0,n-1,0);
	   
	  // print_tree();
	   while(q--)
	    {
	        cin>>ch;
	        if(ch == 'U')
	          {
	              cin>>l>>r>>val;
	               update_tree(0,n-1,l-1,r-1,val,0);
	             
	          }
	        else
	        {
	            cin>>l>>r;
	            cout<<query_tree(0,n-1,l-1,r-1,0)<<endl;
	            
	          
	        }
	        
	        
	    }
	
	return 0;
}
