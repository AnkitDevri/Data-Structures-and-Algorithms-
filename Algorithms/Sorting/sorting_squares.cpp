using namespace std;
#include <bits/stdc++.h>

vector <int> sortSquares ( vector <int>& nums ) {
    vector <int> ans(nums.size(),0);
    int index = 0;
    for( int i = 0 ; i < nums.size(); i++) {
        nums[i] = nums[i]*nums[i];
        if( i!=0 && nums[i] < nums[i-1]){
            index = i-1;
        }
    }
    int i = 0;
    int p1 = index + 1, p2 = index;
    while ( i < nums.size()){
        if( p1 < nums.size()){
            if( p2 >= 0 ) {
                if( nums [p1] < nums[p2]){
                    ans[i] = nums[p1];
                    p1++;
                }
                else{
                    ans[i] = nums[p2];
                    p2--;
                }
            }
            else {
                ans[i] = nums[p1];
                p1++;
            }
        }
        else{
            ans[i] = nums[p2];
            p2--;
        }
        i++;
    }
    return ans;
}
int main(){
    int size, element;
    scanf( "%d", &size);

    vector <int> nums;
    
    for ( int i = 0; i < size; i++) {
        scanf( "%d", &element);
        nums.push_back(element);
    }

    vector <int> sorted_nums = sortSquares(nums);
    
    for (int i = 0 ; i < size; i++){
        printf( "%d ", sorted_nums[i]);
    }
    getchar();
    return 0;
}