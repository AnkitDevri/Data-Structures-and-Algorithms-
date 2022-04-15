using namespace std;
#include <bits/stdc++.h>
int getAns(vector<int>& arr){
    int ans= 0;
    int diff = 0;
    int LDiff = 0;
    sort(arr.begin(),arr.end());
    for(int i = 1 ; i<arr.size(); i+=2){
        diff=abs(arr[i]-arr[i-1]);
        LDiff = max(diff,LDiff);
        ans+=diff;
    }
    return ans-LDiff;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++) cin>>arr[i];
    cout<<getAns(arr);
    return 0;
}