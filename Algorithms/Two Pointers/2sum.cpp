using namespace std;
#include<bits/stdc++.h>
 vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0;
        int p2 = numbers.size()-1;
        while(p1<numbers.size()-1 && p1<p2){
            int sum = numbers[p1]+numbers[p2];
            if(sum==target)return {p1+1,p2+1};
            if(sum>target)p2--;
            else p1++;
        }
        return {};
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> nums(size,0);
    for(int i = 0; i < nums.size(); i++) cin>>nums[i];
    int target;
    cin>>target;
    vector<int> ans = twoSum(nums,target);
    for( auto i : ans) cout<<i<<" ";
    return 0;
}