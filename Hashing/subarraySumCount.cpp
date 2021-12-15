using namespace std;
#include <bits/stdc++.h>
int subarraySumCount( vector <int>& nums, int sum) {
    int count = 0;
    vector <int> psum(nums.size(),0);
    psum[0] = nums[0];
    for ( int i = 1; i < nums.size(); i++) {
        psum[i] = nums[i] + psum[i-1];
    }
    unordered_map <int,int> hmap;
    hmap[0] = 1;

    for (int i = 0; i < psum.size(); i++) {
            auto at = hmap.find(psum[i]-sum);
            if( at != hmap.end()) {
                count += at->second;
            }
        hmap[psum[i]]++;
    }
    return count;
}
int main() {
    int size, element, sum;
    scanf ("%d", &size);
    scanf ("%d", &sum);
    vector <int> nums;
    for ( int i = 0; i < size; i++) {
        scanf ("%d", &element);
        nums.push_back(element);
    }
    printf("%d",subarraySumCount(nums,sum));
    getchar();
    return 0;
}
