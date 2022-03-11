using namespace std;
#include <bits/stdc++.h>
 bool find132pattern(vector<int>& nums) {
        vector<int> pMin(nums.size(),0);
        pMin[0]=nums[0];
        for(int i = 1; i<nums.size(); i++){
            pMin[i] = min(pMin[i-1],nums[i]);
        }
        
        vector<int> pGreater(nums.size(),0);
        stack<int> st;
        for(int i = nums.size()-1; i>=0; i--){
                while(!st.empty() && nums[st.top()]<nums[i]){
                    pGreater[st.top()] = nums[i];
                    st.pop();
                }
            st.push(i);
        }
        while(!st.empty()){
            pGreater[st.top()]=-1;
            st.pop();
        }
        
        for(int i = nums.size()-1; i>=2; i--){
            if(pMin[i-2]<pGreater[i-1] && pMin[i-2]<nums[i]) return true;
        }
        return false;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> arr(size,0);
    for(int i = 0; i<size; i++) cin>>arr[i];
    cout<<find132pattern(arr);
    return 0;
}