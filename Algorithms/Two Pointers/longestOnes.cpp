using namespace std;
#include<bits/stdc++.h>
int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int p1 = 0, p2 = 1;
        if(nums[p1]==0)k--;
        if(nums[p2]==0)k--;
        while(p2<nums.size()){ 
            while(k<0 && p1<nums.size()){
                if(nums[p1]==0) k++;
                p1++;
                ans = max(ans,p2-p1);
            }
            p2++;
            if(nums[p2]==0)k--;
            ans = max(ans,p2-p1);
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
    for(int i = 0; i < size; i++) cin>>arr[i];
    int k;
    cin>>k;
    cout<<longestOnes(arr,k);
    return 0;
}