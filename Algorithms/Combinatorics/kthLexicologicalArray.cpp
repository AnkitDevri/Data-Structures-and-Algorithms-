using namespace std;
#include<bits/stdc++.h>
 void getRank(vector<int>& arr,int k){
  rotate(arr.begin(),arr.begin()+3,arr.end());
  //rotate(arr.begin()+1,arr.begin()+1+3,arr.end());
 }
int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=1;i<=n;i++)
        arr[i-1]=i;
    cin>>k;
    getRank(arr,k);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    getchar();
    return 0;
}