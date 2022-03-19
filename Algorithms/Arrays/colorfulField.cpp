using namespace std;
#include <bits/stdc++.h>
 bool cmp(pair<int,int>& a, pair<int,int>& b){
     if(a.first < b.first) return true;
     else if(a.first==b.first){
         return a.second<b.second;
     }
     else return false;
 }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    vector<unordered_map<int,int>> mp(n+1);
    vector<pair<int,int>> loc;
    while(k--){
        int i, j;
        cin>>i>>j;
        loc.push_back(make_pair(i,j));
    }

    sort(loc.begin(),loc.end(),cmp);       // sorting the waste blocks

    for(int i = 0 ; i < loc.size(); i++){
        mp[loc[i].first][0]++;           // stores total waste of row  i in map as 0 will never be accessed
        int val = mp[loc[i].first][0];
        mp[loc[i].first][loc[i].second]=val;    // stores which how many waste has appeared till itself
    }
    
    for(int i = 1; i < n; i++){
        mp[i][0]+=mp[i-1][0];          // adding all the waste till row i to check for waste that appeared before the ith row
    }
    while(t--){
        int i, j;
        cin>>i>>j;
        int count = mp[i-1][0];             // counting all previous waste before row i
        if(mp[i].find(j)==mp[i].end()){
            int cnt = 0;
            auto k = mp[i].begin();
            while(k!=mp[i].end() && k->first<j){                 // counting the wastes in row i till j
                if(k->first < j)  cnt = k->second;
                k++;
            }
            count+=cnt;                               // adding previous wastes and wastes in current row
            int def = ((m*(i-1))+j);                 // total blocks till i,j
            int ans = (def-count)%3;                 

            if(ans==1)cout<<"Carrots"<<endl;
            else if (ans==2) cout<<"Kiwis"<<endl;
            else cout<<"Grapes"<<endl;
        }
        else cout<<"Waste"<<endl;

    }

    return 0;
}