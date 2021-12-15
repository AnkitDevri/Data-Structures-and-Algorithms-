using namespace std;
#include<bits/stdc++.h>

int search(vector<int>& data,int left,int right,int& element){
   int mid=(left+right)/2;
    if(left>right) return -1;
     else if(left==right && data[mid]!=element) return -1;
     else{
        if(data[mid]==element) return mid;
         else if(element>data[mid]) return search(data,mid+1,right,element);
         else return search(data,left,mid,element);
    }

 }

pair<int,int> pairSum(vector<int>& arr,int& sum){
    int a=0,b=0;
  for(int i=0;i<arr.size();i++){
      a=arr[i];
      b=sum-arr[i];
      if(a!=b){
        if(!(search(arr,i,arr.size()-1,b)==-1)) return make_pair(a,b);
    }

  }
  return make_pair(INT_MIN,INT_MIN);
}
int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>ele;
        arr[i]=ele;
    }
    sort(arr.begin(),arr.end());
    cin>>ele;

    pair<int,int> ans = pairSum(arr,ele);
    cout<<ans.first<<"+"<<ans.second;

    getchar();
    return 0;
}