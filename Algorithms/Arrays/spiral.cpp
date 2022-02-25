using namespace std;
#include<bits/stdc++.h>
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int cnt = 1;
        int i = 0,j = 0;
        while(cnt<=n*n){
            while(j<n && ans[i][j]==0){
                ans[i][j]=cnt;
                cnt++;
                j++;
            }
            if(j==n || ans[i][j]!=0) j--;
            if(ans[i][j]!=0) i++;
            while(i<n && ans[i][j]==0){
                ans[i][j]=cnt;
                cnt++;
                i++;
            }
            if(i==n || ans[i][j]!=0) i--;
            if(ans[i][j]!=0) j--;
            while(j>=0 && ans[i][j]==0){
                ans[i][j]=cnt;
                cnt++;
                j--;
            }
            if(j==-1 || ans[i][j]!=0) j++;
            if(ans[i][j]!=0) i--;
            while(i>=0 && ans[i][j]==0){
                ans[i][j]=cnt;
                cnt++;
                i--;
            } 
            if(i==-1 || ans[i][j]!=0) i++;
            if(ans[i][j]!=0) j++;
        }
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<vector<int>> ans = generateMatrix(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans.size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}