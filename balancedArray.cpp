using namespace std;
#include<bits/stdc++.h>
int sumPivot(vector<int>& arr,vector<int>& suff){
    int sum = arr[0];
    int ans = 0;
    int small = INT_MAX;
    for(int i = 1; i<arr.size()-1; i++){
        if(sum==suff[i+1]){
            if(small>arr[i]) {
                ans=i;
                small=arr[ans];
            }
        }
        sum+=arr[i];
    }
    return ans;
}
int main(){
     #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> SuffArr(n,0);
    for(int i = 0; i < n; i++) cin>>arr[i];
    SuffArr[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--) SuffArr[i]=arr[i]+SuffArr[i+1];
    cout<<sumPivot(arr,SuffArr);
    return 0;
}