using namespace std;
#include<bits/stdc++.h>
 int sumOfBeauties(vector<int>& nums) {
        int ans = 0;
        vector<int> suffMin(nums.size(),0);
        suffMin[nums.size()-1] = nums[nums.size()-1];
        
        for(int i = nums.size()-2; i>=0; i--){
            suffMin[i]=min(suffMin[i+1],nums[i]);
        }
        
        int maxm = nums[0];
        for(auto i : suffMin) cout<<i<<" ";
        for(int i = 1; i<nums.size()-1; i++){
            if(nums[i]>maxm && nums[i]<suffMin[i+1]) 
                ans+=2;
            else if(nums[i]>nums[i-1] && nums[i+1]>nums[i])
                ans+=1;
            maxm=max(maxm,nums[i]);
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
    vector<int> nums(size,0);
    for(int i = 0; i<size; i++) cin>>nums[i];
    cout<<sumOfBeauties(nums);
}