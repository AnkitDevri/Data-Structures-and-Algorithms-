using namespace std;
#include<bits/stdc++.h>
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return intervals;
       vector<vector<int>>ans;
       vector<pair<int,int>> idx;
        
        for(int i = 0; i<intervals.size();i++)
            idx.push_back({intervals[i][0],intervals[i][1]});
        
        sort(idx.begin(),idx.end(),[&](pair<int,int> a,pair<int,int> b){return a.first<b.first;});
        int left=INT_MIN, right=INT_MIN;
        for(int i = 0; i<intervals.size()-1;i++){
            int left = max(left,idx[i].first);
            int maxEnd = max(maxEnd,idx[i].second);
            
            while(i<intervals.size()-1 && maxEnd>=idx[i+1].first){
                if(idx[i+1].second>maxEnd) maxEnd = idx[i+1].second;
                i++;
            }
            ans.push_back({left,maxEnd});
        }
        //if the final pair is not inserted
          if(ans[ans.size()-1][1]<idx[idx.size()-1].second)
              ans.push_back({idx[idx.size()-1].first,idx[idx.size()-1].second});
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<vector<int>> intervals(size,vector<int>(2,0));
    for(int i = 0 ; i < intervals.size(); i++)
        cin>>intervals[i][0]>>intervals[i][1];
    intervals = merge(intervals);
    for(int i = 0 ; i < intervals.size(); i++)
        cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    return 0;
}