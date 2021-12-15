using namespace std;
#include <bits/stdc++.h>
vector <long long > next_greater_element( vector <long long >& nums ) {
    stack <long long> st;
    vector <long long> answer(nums.size(),0);
    st.push(0);
    for ( int i = 1; i < nums.size(); i++) {
        bool flag = true;
        while (!st.empty() && flag ){
            if (nums[ st.top()] < nums[i] ){
                answer [st.top()] = nums[i];
                st.pop();
            }
            else {
                st.push(i);
                flag = false;
            }
        }
        if( st.empty()) st.push(i);  
    }
    if ( st.empty()) return answer;
    else {
        while (!st.empty()){
            answer [st.top()] = -1;
            st.pop();
        }
        return answer;
    }
}
int main () {
    long long  size, ele; 
    scanf("%lld", & size);

    vector <long long> nums;

    for ( int i = 0; i < size; i++) {
        scanf("%lld", &ele);
        nums.push_back(ele);
    }

    vector <long long> answer = next_greater_element(nums);

    for ( auto i : answer) printf("%lld ", i);
    getchar(); 
    return 0;
}