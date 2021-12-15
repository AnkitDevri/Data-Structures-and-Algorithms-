using namespace std;
#include <bits/stdc++.h>
int firstOccurence(vector<int>& arr, int idx, int target){
    if( idx == arr.size()) return -1;
    if( arr[idx] == target) return idx;
    return firstOccurence(arr,idx+1,target);
}
int lastOccurence(vector<int>& arr, int idx, int target){
    if(idx == -1) return idx;
    if(arr[idx] == target ) return idx;
    return lastOccurence(arr,idx-1,target);
    
}

vector<int> allIndices(vector<int>& arr, int idx, int target,vector<int>& answer){
    if(idx == arr.size()) return answer;
    if(arr[idx] == target) answer.push_back(idx);
    allIndices(arr,idx+1,target,answer);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    
    int size,target;
    cin>>size;
    int idx = 0;
    vector<int> arr(size,0);
    for(int i = 0; i < size; i++) cin>>arr[i];
    cin>>target;
    cout<<firstOccurence(arr,idx,target)<<endl;
    cout<<lastOccurence(arr,arr.size()-1,target)<<endl;

    vector<int> ans;
    allIndices(arr,idx,target,ans);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}