using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
    vector<vector<ll>> final(vector<vector<ll>> arr,int m,int n,int k){
       ll i1,j1,i2,j2,sum;
       vector<vector<ll>> a(m,vector<ll>(n));
     for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        i1=i-k; j1=j-k; i2=i+k; j2=j+k;
        if(i1<0)
         i1=0;
       
        if(j1<0)
         j1=0;
       
        if(i2>m-1)
         i2=m-1;
        
        if(j2>n-1)
         j2=n-1;

    if(i1!=0 && j1!=0)
      sum=arr[i2][j2]-arr[i2][j1-1]-arr[i1-1][j2]+arr[i1-1][j1-1];
     else if(i1==0)
      sum=arr[i2][j2]-arr[i2][j1-1];
     else if(i2==0)
      sum=arr[i2][j2]-arr[i1-1][j2];
     else
      sum=arr[i2][j2];

      arr[i][j]=sum;
         
    }
    return arr;
    }
  vector<vector<ll>> preSum(vector<vector<ll>> matrix,int m,int n){
    vector<vector<ll>> arr= matrix;
      ll sum=0;
   for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
      sum=sum+arr[i][j];
      arr[i][j]=sum;
    }
    sum=0;
   for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
       sum=sum+arr[j][i];
       arr[j][i]=sum;
    }

    return arr;
  }
int main(){
    int m,n,k;
    ll element;
    cin>>m>>n;
    vector<vector<ll>> matrix;
    for(ll i=0;i<m;i++)
     for(ll j=0;j<n;j++){
        cin>>element;
        matrix[i][j]=element;     
     }
     cin>>k;
    vector<vector<ll>> ready= preSum(matrix,m,n);
    ready=final(ready,m,n,k);

     for(ll i=0;i<m;i++){
          for(ll j=0;j<n;j++){
             cout<<ready[i][j]<<" ";
             }
         cout<<endl;
        }
    
    getchar();
    return 0;
}