using namespace std;
#include <bits/stdc++.h>
typedef long long int ll;
ll calc_inversion( vector <ll>& nums, int left, int mid, int right) {
    ll p1 = left, p2 = mid + 1;
    ll count = 0;
    vector <ll> temp( right - left + 1, 0 );
    for ( int i = 0; i <= right-left ; i++){
        if ( p1 <= mid ){
            if( p2 <= right ){
                if ( nums[p1] > nums[p2]){
                    count += ( mid - p1 + 1);
                    temp[i] = nums[p2];
                    p2++;
                }
                else {
                    temp[i] = nums[p1];
                    p1++;
                }
            }
            else {
                temp[i] = nums[p1];
                p1++;
            }
        }
        else {
            temp[i] = nums[p2];
            p2++;
        }
        
    }

    for ( int i = 0; i <= right-left ; i++) nums[i + left] = temp[i];

    return count;
    
}
ll splitter( vector <ll>& nums, ll left, ll right) {
    if( left == right) return 0;
    else {
        ll mid = ( left + right ) / 2;
        ll count1 = splitter(nums, left, mid);
        ll count2 = splitter(nums, mid + 1, right);
        ll count3 = calc_inversion(nums, left, mid, right);

        return count1+count2+count3;
    }

}
int main() {
    ll size, element;
    scanf( "%lld", &size);
    vector <ll> nums;
    for ( ll i = 0; i < size; i++) {
        scanf( "%lld", &element);
        nums.push_back(element);
    }
    printf ( "%lld", splitter(nums,0,size-1));
    getchar();
    return 0;
}