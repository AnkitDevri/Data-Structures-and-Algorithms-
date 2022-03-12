using namespace std;
#include<bits/stdc++.h>
vector<int> findDisappearedNumbers(vector<int>& nums) {
   vector<int> ans;
       for(int i = 0; i<nums.size(); i++){
           int num;
           if(nums[i]<nums.size()+1) 
               num = nums[i];
           else 
               num = nums[i]/(nums.size()+1);
           
                int idx = num-1;
                if(nums[idx]<=nums.size()) 
                    nums[idx] = (nums.size()+1)*nums[idx] + num;   
       }
        for(auto i : nums) cout<<i<<" ";
        for(int i = 0; i<nums.size();i++){
            if(nums[i]%(nums.size()+1)==i+1) continue;
            else ans.push_back(i+1);
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
    for(int i = 0; i < nums.size(); i++) 
        cin>>nums[i];
    vector <int> arr = findDisappearedNumbers(nums);
    //for(auto i : arr) cout<<i<<" ";
    return 0;
}