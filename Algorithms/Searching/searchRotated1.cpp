using namespace std;
#include <bits/stdc++.h>
  int utility(vector<int>&nums,int left,int right,int target){
        if(left>right) return -1;
        int mid = (left+right)/2;
        if(nums[mid]==target) return mid;
        else if(target < nums[mid]) return utility(nums,left,mid-1,target);
        else return utility(nums,mid+1,right,target);
    }
    int search(vector<int>& nums, int target) {
        int pivot = -1;
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            else return -1;
        }
        if(nums[0]>nums[1]) pivot = 1;
        else if(nums[nums.size()-1]<nums[nums.size()-2]) pivot = nums.size()-1;
        int l = 0, r = nums.size()-1;
        while(l<=r && pivot==-1){
            int m = (l+r)/2;
            if(nums[m]<nums[m+1] && nums[m]<nums[m-1]) {
                pivot=m;
                break;
            }
            if(nums[m]>nums[0]) l=m+1;
            else r=m-1;
        }
        if(pivot==-1) return utility(nums,0,nums.size()-1,target);
        else return(max(utility(nums,0,pivot-1,target),utility(nums,pivot,nums.size()-1,target)));
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> nums(size,0);
    for(int i = 0 ; i < size; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    cout<<search(nums,target);
    return 0;
}