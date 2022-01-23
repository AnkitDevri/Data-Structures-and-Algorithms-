using namespace std;
#include<bits/stdc++.h>
     void utl(vector<vector<int>>& ans,vector<int>& single,vector<int>& cand,int target,int idx){
        if(target<0) return;
        if(target==0){
            ans.push_back(single);
            return;
        }
        if(idx==cand.size()) return;
        for(int i = idx; i < cand.size(); i++){
            single.push_back(cand[i]);
            utl(ans,single,cand,target-cand[i],i);
            single.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> single;
        utl(ans,single,candidates,target,0);
        return ans;
    }
int main(){
  #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,ele;
    vector<int> set;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ele;
        set.push_back(ele);
    }
    int sum;
    cin>>sum;
    vector<vector<int>> ans = combinationSum(set,sum);
    
    for(int i = 0; i < ans.size(); i++){
      for(int j = 0; j < ans[i].size(); j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}