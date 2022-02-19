using namespace std;
#include<bits/stdc++.h>

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<pair<int,string>> dataset[m];
    string name;
    int region;
    int marks;
    while(n--){
        cin>>name>>region>>marks;
        dataset[region-1].push_back(make_pair(marks,name));
    }
    int z = 0;
    while(z<m){
        sort(dataset[z].begin(),dataset[z].end());
        reverse(dataset[z].begin(),dataset[z].end());
        if(dataset[z].size()>2 && dataset[z][1].first==dataset[z][2].first) cout<<"?"<<endl;
        else cout<<dataset[z][0].second<<" "<<dataset[z][1].second<<endl;
        z++;
    }
    return 0;
}