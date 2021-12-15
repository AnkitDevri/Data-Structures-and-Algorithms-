using namespace std;
#include <bits/stdc++.h>
int Func ( int a , int b , int c , int x){
    return (a*(x*x))+(b*x)+c;
}
vector <int> sortFunc ( vector <int>& nums, int& a, int& b ,int& c ) {
    vector <int> ans(nums.size(),0);
    int index = 0;
    for( int i = 0 ; i < nums.size(); i++) {
        nums[i] = Func(a, b, c, nums[i]);
        if( a>0 && (i!=0 && nums[i] < nums[i-1])){
            index = i-1;
        }
        if( a<0 && (i!=0 && nums[i] > nums[i-1])){
            index = i;
        }
    }
    int i = 0;
    int p1, p2;
    if(a<0){
        p1 = 0;
        p2 = index;
        for ( int i=0 ; i<index ;i++) ans[i] = nums[i];
        for ( int i = nums.size(); i >= index ; i--){
            ans[p2] = nums[i];
            p2++;
        }
            
    }
    else{
         p1 = index + 1;
         p2 = index;
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
    }
    
    return ans;
}
int main(){
    int size, a, b, c, element;
    scanf( "%d", &size);
    scanf( "%d", &a);
    scanf( "%d", &b);
    scanf( "%d", &c);

    vector <int> nums;
    
    for ( int i = 0; i < size; i++) {
        scanf( "%d", &element);
        nums.push_back(element);
    }

    vector <int> sorted_nums = sortFunc(nums, a, b ,c);
    
    for (int i = 0 ; i < size; i++){
        printf( "%d ", sorted_nums[i]);
    }
    getchar();
    return 0;
}