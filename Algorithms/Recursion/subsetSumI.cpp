using namespace std;
#include <bits/stdc++.h>

void calSums(vector<int>& sums,vector<int>& arr, int& sum, int idx){
        if(idx==arr.size()){
            sums.push_back(sum);
            return;
        }
        calSums(sums,arr,sum,idx+1);
        sum+=arr[idx];
        calSums(sums,arr,sum,idx+1);
        sum-=arr[idx];
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sums;
        int sum = 0;
        calSums(sums,arr,sum,0);
        return sums;
    }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    vector<int> ans = subsetSums(v,n);
    for(auto i : ans) cout<<i<<" ";
    return 0;
}