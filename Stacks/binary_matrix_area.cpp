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

int max_area ( vector<vector<int>>& matrix) {
    vector <int> histogram(matrix[0].size(),0);
    int arr[matrix[0].size()];
    for (int i = 0; i < histogram.size(); i++){
        int j = matrix.size()-1;
        int count = 0;
        while ( matrix[j][i] && j>=0){
            count++;
            j--;
        } 
        histogram[i] = count;
    }
    return get_largest_area(histogram);
}
int main() {
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);

    vector <vector <int>> matrix(row,vector<int>(col,0));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d",&matrix[i][j]);

    printf("%d", max_area(matrix));
    getchar();
    return 0;
}