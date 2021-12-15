using namespace std;
#include <bits/stdc++.h>
void getSubset(vector<string>& subsets,string& str,int index,string temp){
    if(index == str.size()) {
        subsets.push_back(temp);
        return;
    }
    //call for putting no item in temp 
    getSubset(subsets,str,index+1,temp);
    //putting item in temp
    temp = temp + str[index];
    //call after putting the item in temp
    getSubset(subsets,str,index+1,temp);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string str;
    cin>>str;
    string temp;
    vector<string> subsets;
    getSubset(subsets,str,0,temp);
    for(auto i : subsets) cout<<i<<endl;
    return 0;
}