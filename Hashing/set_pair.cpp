using namespace std;
#include <bits/stdc++.h>

bool isPairPossible ( vector <int>& nums, int sum) {
    bool answer = false;
    unordered_map <int,int> hmap;
    for ( int i = 0; i < nums.size(); i++) {
        hmap[nums[i]]++;
    }

    for ( int i = 0; i < nums.size(); i++) {
        if ( sum - nums[i] == nums[i] ){
            answer = ( hmap[nums[i]] > 1);
            if ( answer ) break;
        }
        else {
            answer = ( hmap.find(sum - nums[i]) != hmap.end());
            if ( answer ) break;
        }
    }

    return answer;
}
int main() {
    int size, element;
    scanf ( "%d", &size );

    vector <int> nums;
    
    for ( int i = 0; i < size; i++) {
        scanf ( "%d", &element );
        nums.push_back(element);
    }
    
    int sum;
    scanf( "%d", &sum);

    printf ( "%d", isPairPossible(nums,sum));
    getchar();
    return 0;
}