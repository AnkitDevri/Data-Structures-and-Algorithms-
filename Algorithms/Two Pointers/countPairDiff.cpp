using namespace std;
#include <bits/stdc++.h>
	int TotalPairs(vector<int>nums, int k){
	    int ans = 0;
	    unordered_map<int,int> freqMap;
	    unordered_map<int,int> isVisited;
	   
	   for(int i = 0; i < nums.size(); i++) freqMap[nums[i]]++;
	   
	   for(int i = 0; i < nums.size();i++){
	   if(isVisited.find(nums[i])!= isVisited.end()) continue;
	   if(k%2==0){
	       if(nums[i]==k/2 || k==0){
	           int n = freqMap[nums[i]];
	           ans+= (n*(n-1))/2;
               isVisited[nums[i]]++;
	           continue;
	       }
	   }
	    int diff1 = nums[i] - k;
	    int diff2 = nums[i] + k;
	    
	    if(freqMap.find(diff1) != freqMap.end() && k != 0){
	        ans+= freqMap[nums[i]]*freqMap[diff1];
            isVisited[diff1]++;
	    }
	    
	    if(freqMap.find(diff2) != freqMap.end() && k != 0){
	        ans+= freqMap[nums[i]]*freqMap[diff2];
            isVisited[diff2]++;
	    }
	    
	    isVisited[nums[i]]++;
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
    int diff;
    cin>>diff;
    vector<int> nums(size,0);
    for(int i = 0; i < size; i++){
        cin>>nums[i];
    }
    cout<<TotalPairs(nums,diff);
    return 0;
}