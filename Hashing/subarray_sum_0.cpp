using namespace std;
#include <bits/stdc++.h>
bool isSubarray0 ( vector <int>& nums){
    unordered_map <int,int> hmap;
    hmap[nums[0]]++;
    for ( int i = 1; i < nums.size(); i++ ) {
        nums [i] += nums[i-1];
        hmap[nums[i]]++;
    }
    for ( auto it = hmap.begin(); it!= hmap.end(); it++) {
        if ( !it->first ) return true;
        if ( it->second > 1) return true;
    }
    return false;
}
int main() {
    int size, element;
    scanf ("%d", &size);

    vector <int> nums;

    for ( int i = 0; i < size; i++) {
        scanf("%d", &element);
        nums.push_back(element);
    }
    printf ("%d", isSubarray0(nums));
    getchar();
    return 0;
}