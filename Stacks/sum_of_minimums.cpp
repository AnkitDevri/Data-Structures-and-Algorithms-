using namespace std;
#include <bits/stdc++.h>
int m = 1e9 +7;
int get_sum_of_mins( vector <int>& histogram ) {
  stack<int> st;
    vector <int> next_smaller_element(histogram.size(),0);
    vector <int> prev_smaller_element(histogram.size(),0);

    st.push(0);
    for(int i = 1; i < histogram.size(); i++){
        while( !st.empty() && histogram [i] < histogram[st.top()]) {
                next_smaller_element[st.top()] = i;
                st.pop();
            }
            st.push(i);
        
    }
    
    while( !st.empty()){
        next_smaller_element[st.top()] = histogram.size();
        st.pop();
    }

    st.push(histogram.size()-1);
    for(int i = histogram.size() - 2; i >= 0; i--){
         while( !st.empty() && histogram [i] <= histogram[st.top()]) {
                prev_smaller_element[st.top()] = i;
                st.pop();
            }
            st.push(i);
        
        }

    while( !st.empty()){
            prev_smaller_element[st.top()] = -1;
            st.pop();
        }

    int answer = 0;
    int x = 0;

    for ( int i = 0; i < histogram.size(); i++) {
        x = (((long long)(i-prev_smaller_element[i])%m *(next_smaller_element[i]-i)%m)%m * histogram[i]%m)%m;
        answer = (answer%m + x%m)%m;
    }
    return answer;
}
int main() {
    int size, ele;
    scanf("%d",&size);
    vector <int> nums;

    for (int i = 0; i < size; i++) {
        scanf("%d",&ele);
        nums.push_back(ele);
    }

    printf("%d",get_sum_of_mins(nums));
    getchar();
    return 0;
}