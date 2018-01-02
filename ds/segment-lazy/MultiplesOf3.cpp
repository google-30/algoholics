#include <bits/stdc++.h>
using namespace std;
#define MIN 0
#define ll long long
struct seg_node {
    
    ll mod0;
    ll mod1;
    ll mod2;
    
};

seg_node segtree[4000000];
ll lazy[1000000],n;

seg_node merge_node(seg_node s1 , seg_node s2)
{
    
    seg_node s;
   // cout<<s1.mod0<<" "<<s1.mod1<<" "<<s1.mod2<<endl;
    // cout<<s2.mod0<<" "<<s2.mod1<<" "<<s1.mod2<<endl;
    
    s.mod0 = s1.mod0 + s2.mod0;
    s.mod1 = s1.mod1 + s2.mod1;
    s.mod2 = s1.mod2 + s2.mod2;
    return s;
    
}

void build_tree(ll ss, ll se, ll node)
{
     if(ss>se)
      return;
      
    if(ss == se)
      {
          segtree[node].mod0 = 1;
          segtree[node].mod1 = 0;
          segtree[node].mod2 = 0;
          
          return;
      }
    ll mid = (ss+se)/2;
    build_tree(ss,mid,node*2+1);
    build_tree(mid+1,se,node*2+2);
    
    segtree[node] = merge_node(segtree[2*node+1] , segtree[2*node+2]);
}



void update_tree(ll ss , ll se , ll l , ll r, ll node)
{
    
    if(ss>se)
      return;
    
    if(lazy[node]!=0)
      {
            ll val = lazy[node];
            ll a ,b,c;
            
            a = segtree[node].mod0;  // 3 6 9
            b = segtree[node].mod1;  // 4 7 10
            c = segtree[node].mod2;  // 5 8 11
          
            if(val%3 == 0)
              {
                  // do nothing ; 
              }
            else if(val%3 ==1 )
            {
                segtree[node].mod0 = c;
                segtree[node].mod1 = a;
                segtree[node].mod2 = b;
            }
            else
            {
                
                segtree[node].mod0 = b;
                segtree[node].mod1 = c;
                segtree[node].mod2 = a;
            }
            
            
            if(ss != se)
             {
                lazy[node*2+1] += lazy[node];
                lazy[node*2+2] += lazy[node];
             }
           lazy[node] = 0;
            
      }
    
    //no overlap
    if(se<l || ss>r) 
       return;
    
    //full overlap update
    
    if(ss>=l && se<=r)
      {
         // cout<<"tree euhuhe"<<endl;
          ll a ,b,c;
          a = segtree[node].mod0;
          b = segtree[node].mod1;
          c = segtree[node].mod2;
          
          
          segtree[node].mod0 = c;                  
          segtree[node].mod1 = a;
          segtree[node].mod2 = b;
          
          
          if(ss!=se)
            {
                lazy[node*2+1] += 1;
                lazy[node*2+2] += 1;
            }
           
           return;
      }
    
    ll mid = (ss+se)/2;
    update_tree(ss,mid,l,r,node*2+1);
    update_tree(mid+1,se,l,r,node*2+2);
    
    segtree[node] = merge_node(segtree[2*node+1] , segtree[2*node+2]);
    
}

ll query_tree(ll ss , ll se , ll l , ll r , ll node)
{
    //cout<<"ss = "<<ss<<" se= "<<se<<" l= "<<l<<" r= "<<r<<" node = "<<node<<endl;
    if(ss>se)
      return 0;
      
      
    if(lazy[node]!=0)
      {
            ll val = lazy[node];
            ll a ,b,c;
            
            a = segtree[node].mod0;  // 3 6 9
            b = segtree[node].mod1;  // 4 7 10
            c = segtree[node].mod2;  // 5 8 11
          
            if(val%3 == 0)
              {
                  // do nothing ; 
              }
            else if(val%3 ==1 )
            {
                segtree[node].mod0 = c;
                segtree[node].mod1 = a;
                segtree[node].mod2 = b;
            }
            else
            {
                
                segtree[node].mod0 = b;
                segtree[node].mod1 = c;
                segtree[node].mod2 = a;
            }
            
            
            if(ss != se)
             {
                lazy[node*2+1] += lazy[node];
                lazy[node*2+2] += lazy[node];
             }
           lazy[node] = 0;
            
      }
    
    //no overlap
    if(se<l || ss>r) 
       return 0;
    
    // full overlap
    if(ss>=l && se<=r)
      return segtree[node].mod0;
    
    
    // partial overlap
    
    ll mid = (ss+se)/2;
    ll r1 = query_tree(ss,mid,l,r,node*2+1);
    ll r2 = query_tree(mid+1,se,l,r,node*2+2);
    
    return r1+r2 ; 
    
}
void print_tree()
{
    
    for(int i=0;i<7;i++)
      cout<<i<<" " <<segtree[i].mod0<<" "<<segtree[i].mod1<<" "<<segtree[i].mod2<<endl;
    
    cout<<endl;
    
    for(int i=0;i<7;i++)
      cout<<lazy[i]<<" ";
    
    cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,q,i,type,l,r;
	cin>>n>>q;
	//cout<<n<<" "<<q;
	memset(lazy,0,sizeof(lazy));
	
	build_tree(0,n-1,0);
	//cout<<endl<<"treebuild"<<endl;
	while(q--)
	  {
	      cin>>type;
	      if(type == 0)
	        {
	            cin>>l>>r;
	           // cout<<"update tree" <<l <<" to "<<r<<endl;
	            update_tree(0,n-1,l,r,0);
	            //print_tree();
	           // cout<<l<<" "<<r<<" upadteed"<<endl;
	        }
	      else
	        {
	            cin>>l>>r;
	            
	            
	           // cout<<"query tree" <<l <<" to "<<r<<endl;
	            cout<<query_tree(0,n-1,l,r,0)<<endl;
	           // print_tree();
	           // cout<<l<<" "<<r<<" queries"<<endl;
	        }
	      
	  }
	
	return 0;
}
