using namespace std;
#include<bits/stdc++.h>
 int checkMax(vector<int>&tem,int x){
        int res=tem[x-1];
		for(int i=x;i<tem.size();i++){
			res=max(res,tem[i]-tem[i-x]);  
		}
		return res;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0) return 0;
        int ans=0;
        vector<int> preSum(nums.size(),0);
        preSum[0]=nums[0];
        for(int i = 1; i < nums.size(); i++) preSum[i]=preSum[i-1]+nums[i];
        
        int left = 1,right = nums.size();
        while(left<=right){
            int mid = (left+right)/2;
            int mMax = checkMax(preSum,mid);
            if(mMax >=s){
                if(mid==1){
                    ans=mid;
                    break;
                }
                if(mid>=2 && checkMax(preSum,mid-1) < s){
                    ans=mid; 
                    break;
                }
            }
            if(mMax>=s) right = mid;
            else left = mid + 1;
        }
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> arr(size,0);
    for(int i = 0; i < arr.size(); i++) cin>>arr[i];
    int target;
    cin>>target;
    cout<<minSubArrayLen(target,arr);
    return 0;
}