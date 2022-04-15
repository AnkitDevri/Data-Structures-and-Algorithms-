using namespace std;
#include <bits/stdc++.h>
bool isFirst(vector<int>& arr,int idx){
    return arr[idx]==arr[idx+1]);
}
bool isCorrect(vector<int>& arr,int idx){ 
    return (arr[idx]!=arr[idx+1] && arr[idx]!=arr[idx-1]);
}
int searchSingle( vector<int>& arr){
    if(arr[0]!=arr[1]) 
        return arr[0];

    if(arr[arr.size()-1] != arr[arr.size()-2]) 
        return arr[arr.size()-1];

    int left  = 1, right = arr.size()-2, mid;

    while(left<=right){
        mid = (left+right)/2;
        if(isCorrect(arr,mid)) return arr[mid];
        else if(isFirst(arr,mid) && mid%2==0)  left=mid+1;
        else right=mid-1;
    }
}
int main(){
    int size;
    cin>>size;
    vector<int> arr(size,0);
    for(int i = 0; i < size; i++) cin>> arr[i];
    cout<<searchSingle(arr);
    return 0;
}