using namespace std;
#include <bits/stdc++.h>
 int maximumGap(vector<int>& nums) {
        int ans = 0;
      //calculate size of buckets
        int gaps = nums.size()-1;
        int MAX = INT_MIN, MIN = INT_MAX;
        for( auto i : nums){
            MAX = max(MAX,i);
            MIN = min(MIN,i);
        }
        if(nums.size()<=2) return MAX-MIN;
        int bucketSize = ceil((float)(MAX-MIN)/gaps);

      //calculate max and min values of each bucket
        vector<int> maxVals(nums.size(),-1);
        vector<int> minVals(nums.size(),INT_MAX);
        
        for(int i = 0; i<nums.size(); i++){
            int idx = (nums[i]-MIN)/bucketSize;
            maxVals[idx] = max(maxVals[idx],nums[i]);
            minVals[idx] = min(minVals[idx],nums[i]);
        }
      //  for(auto g : minVals) cout<<g<<" ";
      //  for(auto f : maxVals) cout<<f<<" ";
        
      //calculate max gap between two non empty buckets in the same arrangement
        int b1=0,b2=1;
        while(b2<nums.size()){
            while(minVals[b2]==INT_MAX){
               b2++;
            }
            while(b1<b2 && maxVals[b1]==-1){
               b1++;
            }
            ans = max(ans,minVals[b2]-maxVals[b1]);
            b1++;
            b2++;
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
    for(int i = 0; i<size; i++) 
        cin>>arr[i];
    cout<<maximumGap(arr);
    return 0;
}