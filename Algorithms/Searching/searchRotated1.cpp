using namespace std;
#include <bits/stdc++.h>
// here the intution is that we divide the search space while checking that the number is present before the pivot or after the pivot
// it is first deteremined at which section we are
// then we check if target is in the given section if it is then we narrow our search to that section if not then we move it away
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[left]){
                if(target>=nums[left] && target<nums[mid]) right = mid-1;
                else left = mid+1;
            }
            else{
                if(target<=nums[right] && target>nums[mid]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
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