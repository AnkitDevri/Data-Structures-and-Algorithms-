using namespace std;
#include <bits/stdc++.h>
bool isConsecutive( vector <long long>& nums) {
   unordered_map <long long,long long> hmap;
    long long MIN = LONG_LONG_MAX;
    for ( long long i = 0; i < nums.size(); i++) {
        MIN = min( MIN, nums[i]);
        hmap[nums[i]]++;
    }
    for ( long long i = MIN; i< MIN + nums.size() ; i++){
        if ( hmap.find(i) == hmap.end()) return false;
    }
    return true;


}
int main(){
    long long size, element;
    scanf( "%d", &size);

    vector <long long> nums;
    
    for ( int i = 0; i < size; i++ ) {
        scanf ("%d", &element);
        nums.push_back(element);
    }

    printf("%d",isConsecutive(nums));
    getchar();
    return 0;
}