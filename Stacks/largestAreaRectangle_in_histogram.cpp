using namespace std;
#include <bits/stdc++.h>
int get_largest_area ( vector <int>& histogram) {
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
         while( !st.empty() && histogram [i] < histogram[st.top()]) {
                prev_smaller_element[st.top()] = i;
                st.pop();
            }
            st.push(i);
        
        }

    while( !st.empty()){
            prev_smaller_element[st.top()] = -1;
            st.pop();
        }

    int largest_area = INT_MIN;
    for (int i = 0; i < histogram.size(); i++) {
        largest_area = max( largest_area, (next_smaller_element[i]-prev_smaller_element[i]-1)*histogram[i]);
    }
    return largest_area;
    
}
int main () {
    int size, ele;
    scanf("%d", &size);

    vector <int> histogram;

    for ( int i = 0; i < size; i++) {
        scanf("%d", &ele);
        histogram.push_back(ele);
    }
    printf ("%d", get_largest_area(histogram));
    getchar();
    return 0;
}