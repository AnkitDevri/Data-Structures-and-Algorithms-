using namespace std;
#include <bits/stdc++.h>
 int helper(vector<int>& nums,int n){
       if(n==0) return 0;
        if(n==1) return 1;
        int v1=-1,v2=-1;
        
        if(nums[n-1]!=-1) v1=nums[n-1];
        else {
            v1 = helper(nums,n-1);
            nums[n-1] = v1;
        }
        
        if(nums[n-2]!=-1) v2=nums[n-2];
        else {
            v2 = helper(nums,n-2);
            nums[n-2] = v2;
        }
        return v1 + v2;
        
    }
    int fib(int n) {
        vector<int>nums(n+1,-1);
        nums[0]=0;
        if(n==0) return 0;
        nums[1]=1;
        return helper(nums,n);
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}