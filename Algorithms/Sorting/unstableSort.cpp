using namespace std;
#include <bits/stdc++.h>
bool compare(pair<int,int> x, pair<int,int> y){
    if(x.first == y.first){
        if(x.second > y.second) return true;
        else return false;
    }
    else return x.first < y.first;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> arr(size,0);
    vector<pair<int,int>> pairs;
    for( int i = 0 ; i < arr.size(); i++){
        cin>>arr[i];
        pairs.push_back(make_pair(arr[i],i));
    }
    sort(pairs.begin(),pairs.end(),compare);

    for ( int i = 0 ; i < pairs.size(); i++){
        cout<<pairs[i].second+1<<" ";
    }
    return 0;
}