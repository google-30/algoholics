#include <iostream>
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
    if(r<0 || c<0 || r>n || c>m)
       return false;
     
    return true;   
    
}
void countIslandsUtility(int mat[1000][1000],int n,int m , int r , int c)
{
    int i,j;
    int x[] = {0 , 0 , 1 , 1 , 1 , -1 , -1 , -1};
    int y[] = {1 , -1 , -1 , 0 , 1 , 1  , 0 , -1};
       
    vis[r][c] = 1;
    
    for(i=0;i<8;i++)
      {
              if(isSafe(n,m,r+x[i],c+y[i]) == true)
                {
                    
                    if(vis[r+x[i]][c+y[i]] == 0 && mat[r+x[i]][c+y[i]] == 1)
                       {
                           cout<<r+x[i]<<" "<<c+y[i]<<endl;
                           countIslandsUtility(mat , n, m , r+x[i] , c+y[i] );
                       }
                     else
                       vis[r+x[i]][c+y[i]] =1;
                }
        
      }
    
    
}

int countIslands(int mat[1000][1000],int n,int m)
{
    int i,j,islands=0;
    for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && mat[i][j] == 1)
                {
                    //cout<<"hello"<<endl;
                    countIslandsUtility(mat,n,m,i,j); 
                    
                    //print(n,m);
                    //cout<<endl;
                    islands++;
                }
                
                
            }
      }
    
    return islands;
    
    
}

int main() {
	
	int n,m,i,j,mat[1000][1000];
	cin>>n>>m;
	initialize(n,m);
	for(i=0;i<n;i++)
	  {
	      for(j=0;j<m;j++)
	         cin>>mat[i][j];
	  }
	
	cout<<"No of island is/are : "<<countIslands(mat,n,m);
	
	
	return 0;
}
