using namespace std;
#include<bits/stdc++.h>
 int searchSingle(vector<int>& data,int left,int right){
     int mid=(left+right)/2;
     if(mid==0){
         if(data[mid]!=data[mid+1]) return 0;
          else return -1;
     }
     else if(mid==data.size()-1){
         if(data[mid]!=data[mid-1]) return mid;
         else return -1;
     }
      if(data[mid]!=data[mid+1] && data[mid]!=data[mid-1]) return mid;
   
     
      if(mid%2==0){
       if(data[mid+1]==data[mid]) return searchSingle(data,mid+1,right);
       else return searchSingle(data,left,mid-1);
      }
      else{
      if(data[mid-1]==data[mid]) return searchSingle(data,mid+1,right);
       else return searchSingle(data,left,mid-1);
      }
 }
int main(){
    int n,ele;
    cin>>n;
    vector<int> data(n,0);
    for(int i=0;i<n;i++){
        cin>>ele;
        data[i]=ele;
    }
    int idx=searchSingle(data,0,n-1);
    if(idx!=-1)
    cout<<data[idx];
    else
    cout<<"\nNot Found";
    getchar();
    return 0;
}