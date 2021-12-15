using namespace std;
#include<bits/stdc++.h>
 typedef long long int ll;
 ll subMatrixSum(vector<vector<ll>> arr,vector<ll> query){
     ll i1=query[0],j1=query[1],i2=query[2],j2=query[3],sum;
     
     if(i1!=0 && j1!=0)
      sum=arr[i2][j2]-arr[i2][j1-1]-arr[i1-1][j2]+arr[i1-1][j1-1];
     else if(i1==0)
      sum=arr[i2][j2]-arr[i2][j1-1];
     else if(i2==0)
      sum=arr[i2][j2]-arr[i1-1][j2];
     else
      sum=arr[i2][j2];

     return sum;
 }
 void preSum(vector<vector<ll>> &arr){
     ll sum=0;
   for(int i=0;i<arr.size();i++)
    for(int j=0;j<arr[i].size();j++){
      sum=sum+arr[i][j];
      arr[i][j]=sum;
    }
    sum=0;
   for(int i=0;i<arr[0].size();i++)
    for(int j=0;j<arr.size();j++){
       sum=sum+arr[j][i];
       arr[j][i]=sum;
    }
 }
int main(){
    long row,col,element,total;
    cin>>row;
    cin>>col;
    vector<vector<ll>> arr(row,vector<ll>(col));
    for(int i=0;i<row;i++)
     for(int j=0;j<col;j++){
     cin>>element;
     arr[i][j]=element;    
     }
     preSum(arr);
     cin>>total;

     vector<vector<ll>> query(total,vector<ll>(4));
     for(int i=0;i<total;i++)
     for(int j=0;j<4;j++){
     cin>>element;
     query[i][j]=element;
     }
     for(int i=0;i<total;i++)
     for(int j=0;j<4;j++){
      cout<<subMatrixSum(arr,query[i]);
     }

    getchar();
    return 0;
}