using namespace std;
#include<bits/stdc++.h>

int searchIndex(vector<int>&data,int left,int right){
 int mid=(left+right)/2;

 if(data[mid]>data[mid+1])  return mid;

 else if(data[0]<data[data.size()-1]) return -1;

 else if(data[mid]<=data[data.size()-1]) return searchIndex(data,left,mid-1);

 else return searchIndex(data,mid+1,right);

}
int rsearch(vector<int>& data,int left,int right,int& element){
  int mid=(left+right)/2; 
   if(left>right)  return -1;
    
    else{
    if(left==right && data[mid]!=element)  return -1;

    if(data[mid]==element) return mid;

    else if(element>data[mid]) return rsearch(data,mid+1,right,element);
    
    else return rsearch(data,left,mid-1,element);
    }

 }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(target==nums[0]) return 0;

            else return -1;
        }
       
     int idx=searchIndex(nums,0,nums.size()-1);

        if(target>nums[nums.size()-1]) return rsearch(nums,0,idx,target);

    else{
     if(idx==-1) return rsearch(nums,0,nums.size()-1,target);

     else return rsearch(nums,idx+1,nums.size()-1,target);
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
    int element;
    cin>>element;
    cout<<search(data,element);
    getchar();
    return 0;
}