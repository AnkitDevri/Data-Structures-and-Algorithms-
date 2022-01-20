using namespace std;
#include<bits/stdc++.h>
// here the intuition is that before the single ocurring number all numbers at the even postion match the postion before them
// however after the single element the even positions no longer match the odd postions
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int left = 0, right = nums.size()-1;
        
        if(nums[left]!= nums[left+1]) return nums[left];
        else if(nums[right]!= nums[right-1]) return nums[right];
        
        while(left<=right){
            int mid = (left+right)/2;
            if(mid%2==0){
                if (nums[mid]==nums[mid-1]) right = mid -1;
                else if(nums[mid]!=nums[mid+1]) return nums[mid];
                else left = mid+1;
            }
            else{
                if(nums[mid]==nums[mid+1]) right = mid -1;
                else if(nums[mid]!=nums[mid-1]) return nums[mid-1];
                else left = mid+1;
            }
        }
        return -1;
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
    int val = singleNonDuplicate(data);
    if(val!=-1)
    cout<<val;
    else
    cout<<"\nNot Found";
    return 0;
}