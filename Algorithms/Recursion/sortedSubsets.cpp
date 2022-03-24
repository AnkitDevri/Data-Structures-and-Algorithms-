#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets;
void getSubset(vector<int>& v,vector<int>& temp,int idx){
    if(idx==v.size()){
        return;
    }
    for(int i = idx; i<v.size(); i++){
        temp.push_back(v[i]);
        subsets.push_back(temp);
        getSubset(v,temp,i+1);
        temp.pop_back();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> v(size,0);
    for(int i = 0; i<size; i++) cin>>v[i];
    
    vector<int> temp;
    getSubset(v,temp,0);

    for( auto i : subsets){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
