using namespace std;
#include <bits/stdc++.h>
int merge(vector<int>& nums, int l, int r, int& k){
    int count = 0;
    int mid = l+r/2;
    vector<int> temp(r-l+1,0);
    int p1 = l,p2 = mid;
    for(int i = l; i<=r; i++){
        if(nums[p2]>=nums[p1]){
            nums[i]=nums[p1];
            p1++;
        }
        else{
            nums[i]=nums[p2];
            p2++;
        }
    }
    return count;
}
int divideAndConq(vector<int>& nums, int l, int r,int& k){
    int mid = (l+r)/2;
    if(l>=r){
        if(nums[mid]==k)
         return 1;
        else return 0;
    }
    int leftCount = divideAndConq(nums,l,mid-1,k);
    int rightCount = divideAndConq(nums,mid,r,k);
    return merge(nums,l,r,k) + leftCount + rightCount;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    vector<int> nums(n,0);

    for(int i = 0; i < nums.size(); i++) 
        cin>>nums[i];
    
    for(int i = 1; i<nums.size(); i++) 
        nums[i]+=nums[i-1];

    cout<<divideAndConq(nums,0,n-1,k);
    return 0;
}