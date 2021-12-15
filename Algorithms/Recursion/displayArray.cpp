using namespace std;
#include<bits/stdc++.h>

void print(vector<int>& arr, int idx){
    if(idx == -1) return;
    print(arr,idx-1);
    cout<<arr[idx]<<endl;
    
}
void printReverse(vector<int>& arr, int idx){
    if(idx == -1) return;
    cout<<arr[idx]<<endl;
    printReverse(arr,idx-1);
}
int findMax(vector<int>& arr, int idx,int maxVal){
    if(idx == -1) return maxVal;
    maxVal = max(maxVal,arr[idx]);
    findMax(arr,idx-1,maxVal);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i < n ; i++) cin>>arr[i];
    print(arr,n-1);
    printReverse(arr,n-1);
    cout<<findMax(arr,n-1,INT_MIN);
    return 0;
}