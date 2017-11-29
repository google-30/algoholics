#include <iostream>
#include<algorithm>
using namespace std;
int vis[1000][1000];

void initialize(int n , int m)
{  int i,j;
    for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
             vis[i][j] = 0;
      }
      
    
}

void print(int n , int m)
{  int i,j;
    for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
             cout<<vis[i][j]<<" ";
             cout<<endl;
      }
}
bool isSafe(int n,int m,int r,int c)
{
    if(r<0 || c<0 || r>=n || c>=m)
       return false;
     
    return true;   
    
}
void countCellsUtility(int mat[1000][1000],int n,int m , int r , int c)
{
    int i,j;
    int x[] = { 1 , -1 , 0 , 0 };
    int y[] = { 0 , 0 , 1, -1};
       
    vis[r][c] = 1;
    
    for(i=0;i<4;i++)
      {
              if(isSafe(n,m,r+x[i],c+y[i]) == true)
                {
                    
                    if(vis[r+x[i]][c+y[i]] == 0 && mat[r][c]>=mat[r+x[i]][c+y[i]])
                       {
                          // cout<<r+x[i]<<" "<<c+y[i]<<endl;
                           countCellsUtility(mat , n, m , r+x[i] , c+y[i] );
                       }
                    
                }
        
      }
    
    
}

int countCells(int mat[1000][1000],int n,int m ,pair<int, pair<int , int>> cells[2000001] , int size)
{
    int i,j,count=0,k;
    
    for(k=size-1;k>=0;k--)
      {
          i = cells[k].second.first;
          j = cells[k].second.second;
          
           if(vis[i][j] == 0 )
                {
                    //cout<<"hello"<<endl;
                    countCellsUtility(mat,n,m,i,j); 
                    
                    //print(n,m);
                    //cout<<endl;
                    count++;
                }
                
                
        
      }
    
    return count;
    
    
}

int main() {
	
	int n,m,i,j,t,mat[1000][1000],k;
	
	pair< int , pair<int , int>> cells[2000001];
	
	cin>>t;
	while(t--)
	{
	    
	
	cin>>n>>m;
	initialize(n,m);
	k = 0;
	for(i=0;i<n;i++)
	  {
	      for(j=0;j<m;j++)
	        {
	            cin>>mat[i][j];
	            cells[k].first = mat[i][j];
	            cells[k].second.first = i;
	            cells[k].second.second = j;
	            k++;
	        }
	  }
	
	sort(cells,cells+k);
	
//	for(i=k-1;i>=0;i--)
//	  cout<<cells[i].first<<" "<<cells[i].second.first<<" "<<cells[i].second.second<<endl;
	
	
	cout<<countCells(mat,n,m,cells,k)<<endl;
	
	}
	return 0;
}
