using namespace std;
#include<bits/stdc++.h>
 bool verify(vector<int>& data,int num,int& n){
     int sum=0;
     for(int j=0;j<num;j++) sum+=data[j];

      if(sum>n) return false;
     for(int i=num;i<data.size();i++){
        sum=sum-data[i-num];
        sum+=data[i];
        if(sum>n) return false;
     }
     return true;
 }
 int maximizeK(vector<int>& data,int left,int right,int& n){
     int mid=(left+right)/2;
     if(verify(data,mid,n)){
         if(mid==data.size()-1) return mid;
         if(!verify(data,mid+1,n)) return mid;
         else return maximizeK(data,mid+1,right,n);
      }
     else return maximizeK(data,left,mid-1,n);
 }
int main(){
    int n,ele;
    cin>>n;
    vector<int> data(n);
    for(int i=0;i<n;i++){
        cin>>ele;
        data[i]=ele;
    }
    int k;
    cin>>k;
    cout<<maximizeK(data,1,n,k);
    getchar();
    return 0;
}