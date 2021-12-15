using namespace std;
#include<bits/stdc++.h>


int main(){
    int n,m,t;
    cin>>n>>m>>t;
    long long PascalT[n+m+1][n+m+1];
    PascalT[0][0]=1;
    for(int i=1;i<=n+m;i++)
    for(int j=0;j<=i;j++)
     if(j==0 || j==i)
     PascalT[i][j]=1;
     else{
      PascalT[i][j]=PascalT[i-1][j-1]+PascalT[i-1][j];
     }

/*
      for(int i=0;i<n+m;i++){
           for(int j=0;j<=i;j++)
            cout<<PascalT[i][j]<<" ";
            cout<<endl;
      }
 */        

    long long ans=PascalT[n+m][t];
    if(t<=m)
    ans-=PascalT[m][t];
    if(t-1<=m)
    ans-=PascalT[n][1]*PascalT[m][t-1];
    if(t-2<=m)
    ans-=PascalT[n][2]*PascalT[m][t-2];
    if(t-3<=m)
    ans-=PascalT[n][3]*PascalT[m][t-3];
    if(t<=n)
    ans-=PascalT[n][t]*PascalT[m][0];
   
    cout<<ans;
    getchar();
    return 0;
}