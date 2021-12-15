using namespace std;
#include <bits/stdc++.h>
typedef long long ll;

int get_longest_consecutive_chunk( vector <ll>& nums) {
    unordered_map <ll,int> hmap;
    int count = 0;
    for ( ll i = 0; i < nums.size(); i++) {
        int left_streak = 0 , right_streak = 0;
        if ( hmap.find( nums[i]) == hmap.end()) {
            if( hmap.find(nums[i]-1) != hmap.end()) left_streak = hmap[nums[i]-1];
            if( hmap.find(nums[i]+1) != hmap.end()) right_streak = hmap[nums[i]+1];
            count = max(count, 1 + left_streak + right_streak);
            hmap[nums[i]] = 1 + left_streak +right_streak;
            hmap[nums[i]-left_streak] = 1 + left_streak + right_streak;
            hmap[nums[i]+right_streak] = 1 + left_streak + right_streak;
        }
    }
    return count;
}
int main() {
    ll size, element;
    scanf("%lld", &size);
    vector <ll> nums;
    
    for (ll i = 0; i < size; i++) {
        scanf("%lld", &element);
        nums.push_back(element);
    }

    printf("%d",get_longest_consecutive_chunk(nums));
    getchar();
    return 0;
}