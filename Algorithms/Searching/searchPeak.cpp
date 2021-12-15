using namespace std;
#include<bits/stdc++.h>
    int searchPeak(vector<int>& data,int left,int right){
 int mid=(left+right)/2;
 if(mid>0 && mid<data.size()-1){
   if(data[mid]>=data[mid+1] && data[mid]>=data[mid-1]) return mid;

    else{
      if(data[mid]<data[mid+1]) return searchPeak(data,mid+1,right);

      else return searchPeak(data,left,mid-1);
    }
 }
 else if(mid==0){
  if(data[mid]>=data[mid+1]) return 0;

   else if(data[mid+1]>data[mid]) return mid+1;

   else return -1;
 }
 else{
     if(data[mid]>=data[mid-1]) return data.size()-1;

      else return -1;
 }
}

    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        
       return searchPeak(nums,0,nums.size()-1); 
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,ele;
    cin>>n;
    vector<int> data(n,0);
    for(int i=0;i<n;i++){
        cin>>ele;
        data[i]=ele;
    }
    cout<<findPeakElement(data);
    getchar();
    return 0;
}
