using namespace std;
#include <bits/stdc++.h>
int mergeCount(vector<int>& nums, int l, int r, int& k){
    int count = 0;
    int mid = l + (r-l)/2;
    vector<int> temp(r-l+1,0);
    int p1 = l,p2 = mid;
    while(p1<mid && p2<=r){
        int val = nums[p2]-nums[p1];
        if(val==k) {
            count++;
            p1++;
            p2++;
        }
        else if(val > k){
            p1++;
        }
        else p2++;
    }
    
    int idx = 0;
    p1 = l,p2 = mid;
    while(p1<mid && p2 <=r){
        if(nums[p1]<=nums[p2]){
            temp[idx] = nums[p1];
            p1++;
        }
        else {
            temp[idx] = nums[p2];
            p2++;
        }
        idx++;
    }
    while(p1<mid){
        temp[idx]= nums[p1];
        p1++;
        idx++;
    }
    while(p2<=r){
        temp[idx]=nums[p2];
        idx++;
        p2++;
    }

    for(int i = l; i <=r; i++){
        nums[i] = temp[i-l];
    }
    return count;
}
int divideAndConq(vector<int>& nums, int l, int r,int& k){
    int mid = l + (r-l)/2;
    if(l>=r || l==mid){
        if(nums[mid]==k)
         return 1;
        else 
        return 0;
    }
    int leftCount = divideAndConq(nums,l,mid-1,k);
    int rightCount = divideAndConq(nums,mid,r,k);
    return mergeCount(nums,l,r,k) + leftCount + rightCount;
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

    cout<<divideAndConq(nums,0,n-1,k)<<endl;

    for(auto i : nums) cout<<i<<" ";
    return 0;
}