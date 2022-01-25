using namespace std;
#include<bits/stdc++.h>
vector<int> calcTeams(vector<vector<int>>& tc){
    vector<int> ans;
    for(int i = 0 ; i < tc.size(); i++){
        int count = 0;
        int limit = tc[i][0];
        int p1 = 1, p2 = limit*2;
        int lastSum;
            while(p1<p2){
            int sum = tc[i][p1] + tc[i][p2];
            
        }
         ans.push_back(count);
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    vector<vector<int>>tc;
    for(int i = 0 ; i < t; i++){
        int ele;
        cin>>ele;
        vector<int> arr(ele+1,0);
        arr[0]=ele;
        for(int i = 1; i<=ele; i++) cin>>arr[i];
        sort(arr.begin()+1,arr.end());
        tc.push_back(arr);
    }
    vector<int> ans = calcTeams(tc);
    for(auto i: ans)cout<<i<<endl;
    return 0;
}