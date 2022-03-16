using namespace std;
#include <bits/stdc++.h>
int subarraysDivisible( vector<long long>& arr){
    int ans = 0;
    int n = arr.size();
    vector<long long> psum(n,0);

    for(int i = 1; i <n; i++){
        arr[i]=arr[i]+arr[i-1];
    }
    long long sum = 0;
    for(int i = 0; i <n; i++){
        sum = arr[i];
        int mod= (sum%n + n)%n;
        if(sum!=0 && mod==0) ans++;
        else ans+=psum[mod];
        psum[mod]++;
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
    vector<long long> arr(n,0);
    for(int i = 0; i < arr.size(); i++) 
        cin>>arr[i];
    cout<<subarraysDivisible(arr);
    return 0;
}