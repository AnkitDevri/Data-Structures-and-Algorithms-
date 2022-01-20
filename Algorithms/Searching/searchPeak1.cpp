using namespace std;
#include<bits/stdc++.h>
  int findPeakElement(vector<int>& nums) {
        int ans = 0;
        if(nums.size()==1) return 0;
        int left = 0 , right = nums.size()-1;
        if(nums[0]>nums[1]) return 0;
        else if(nums[nums.size()-1]>nums[nums.size()-2]) return nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]) return mid;
            else if(nums[mid+1]>nums[mid]) left = mid+1;
            else right = mid -1;
        }
        return ans;
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
