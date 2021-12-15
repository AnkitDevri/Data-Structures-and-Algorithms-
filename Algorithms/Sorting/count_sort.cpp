using namespace std;
#include <bits/stdc++.h>
vector <int> countSort ( vector <int>& nums) {
    int minm = *min_element( nums.begin(), nums.end());
    int maxm = *max_element( nums.begin(), nums.end());

    vector <int> freq ( maxm - minm + 1, 0);
    vector <int> cfreq ( maxm - minm + 1, 0);

    for ( int i = 0 ; i < nums.size() ; i++) {
        freq[ nums[i] - minm ]++;
    }
    cfreq[0] = freq[0];
    for ( int i = 1; i < cfreq.size(); i++) {
        cfreq [i] = freq[i] + freq[ i - 1 ];
    }
    vector <int> ans (nums.size(),0);
    for ( int i = 0 ; i < ans.size(); i++) {
        if ( freq [nums[i] - minm] ) {
            ans [ cfreq [nums[i] - minm] - 1] = nums[i];
            cfreq [nums[i] - minm]--;
        }
    }
    return ans;
}
int main () {
    int size, element;
    scanf ( "%d", &size);
    vector <int> nums;
    for (int i = 0; i < size; i++ ) {
        scanf ( "%d", &element);
        nums.push_back(element);
    }
    nums = countSort(nums);
    for ( auto i : nums) printf ("%d ", i);
    getchar();
    return 0;
}