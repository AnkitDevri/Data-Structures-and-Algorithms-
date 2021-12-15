using namespace std;
#include <bits/stdc++.h>
int isSubarray0 ( vector <int>& nums){
    int ans = 0;
    unordered_map <int,int> hmap;
    vector <int> num(nums.size(),0);
    hmap[nums[0]] = 0;
    for ( int i = 1; i < nums.size(); i++ ) {
        num [i] =nums[i]+nums[i-1];
        if (hmap.find(num[i]) == hmap.end()) hmap[num[i]] = i;
    }
    for ( int i = 0; i < nums.size(); i++) {
        auto it = hmap.find(num[i]);
        if ( num[i] == 0 && (it->second + 1) > ans) {
            ans = it->second + 1;
        }
        else {
            if ( it != hmap.end()) {
                if( it->second != i && (i-it->second > ans)) 
                    ans = i - it->second;
            }
        }
    }
    return ans;
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