using namespace std;
#include <bits/stdc++.h>
void getSubsets(vector<vector<int>>& combs,vector<int>& nums,vector<int>& temp,int& sum,int& curr,int idx){
    if(idx==nums.size()) return;
    if(curr>sum) return;
    if(curr==sum){
        combs.push_back(temp);
        return;
    }
    for(int i = idx; i<nums.size(); i++){
        temp.push_back(nums[i]);
        curr+=nums[i];
        getSubsets(combs,nums,temp,sum,curr,i);
        curr-=nums[i];
        temp.pop_back();
        //getSubsets(combs,nums,temp,sum,curr,i+1);     not needed this call
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size,sum;
    cin>>size;
    vector<int> v(size,0);
    cin>>sum;
    for(int i = 0; i<size; i++) 
        cin>>v[i];
    vector<vector<int>>combs;
    vector<int>temp;
    int curr = 0;
    getSubsets(combs,v,temp,sum,curr,0);
    for(auto i : combs){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}