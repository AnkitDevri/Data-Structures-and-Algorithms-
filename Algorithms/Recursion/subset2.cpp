using namespace std;
#include <bits/stdc++.h>
void getSubset(vector<vector<int>>& subsets,vector<int>& values,int index,vector<int>& temp){
    if(index == values.size()) {
        subsets.push_back(temp);
        return;
    }
    //call for putting no item in temp 
    getSubset(subsets,values,index+1,temp);
    //putting item in temp
    temp.push_back(values[index]);
    //call after putting the item in temp
    getSubset(subsets,values,index+1,temp);

    temp.pop_back();
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int  size;
    cin>>size;
    vector<int> values(size,0);
    for(int i = 0; i < size; i++) cin>>values[i];
    vector<vector<int>> subsets;
    vector<int> temp;
    getSubset(subsets,values,0,temp);
    
    for(int i = 0; i < subsets.size(); i++){
        for(int j = 0; j < subsets[i].size(); j++)
            cout<<subsets[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}