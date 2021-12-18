using namespace std;
#include<bits/stdc++.h>
int getPeak(vector<int>& nums){
    for(int i = 1; i < nums.size(); i++)
        if(nums[i] < nums[i-1]) return i-1;
    return nums.size()-1;
}
int main(){
   #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> nums(size);
    for(int i = 0; i < size; i++) cin>>nums[i];
    cout<<getPeak(nums);
    return 0;
}