using namespace std;
#include <bits/stdc++.h>
int sizeSubarraySum ( vector <int>& nums, int sum){
    int ans = 0;
    unordered_map <int,int> hmap;
    vector <int> num(nums.size(),0);
    hmap[nums[0]] = 0;
    num[0] = nums[0];
    for ( int i = 1; i < nums.size(); i++ ) {
        num[i] = nums[i] + nums[i-1];
        if (hmap.find(num[i]) == hmap.end()) hmap[num[i]] = i;

        if ( num[i] == sum && i + 1> ans) {
            ans = i+1;
        }
        else if ( num[i] - sum > 0){
           auto jt = hmap.find(num[i] - sum);
           if (  jt != hmap.end() && (i - jt->second) > ans) {
               ans = i - jt->second;
           }
        }
    }
    
    return ans;
}
int main() {
    int size, element;
    scanf ("%d", &size);
    int sum;
    scanf ("%d", &sum);
    vector <int> nums;

    for ( int i = 0; i < size; i++) {
        scanf("%d", &element);
        nums.push_back(element);
    }
   
    printf ("%d", sizeSubarraySum(nums,sum));
    getchar();
    return 0;
}