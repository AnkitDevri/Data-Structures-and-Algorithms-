using namespace std;
#include <bits/stdc++.h>
 bool isSafe(int i,int j,vector<vector<int>>& maze){
         if(i<0 || i>=maze.size()) return false;
         else if(j<0 || j>=maze[0].size()) return false;
         return maze[i][j]==1;
     }
void getPaths(vector<string>& ans, string &temp, vector<vector<int>>& maze,int i,int j){
    if(i==maze.size()-1 && j==maze.size()-1){
        ans.push_back(temp);
        return;
    }
    //down
    if(isSafe(i+1,j,maze)){
        maze[i+1][j]=0;
        temp+='D';
        getPaths(ans,temp,maze,i+1,j);
        temp.pop_back();
        maze[i+1][j]=1;
    }
    //left
    if(isSafe(i,j-1,maze)){
        maze[i][j-1]=0;
        temp+='L';
        getPaths(ans,temp,maze,i,j-1);
        temp.pop_back();
        maze[i][j-1]=1;
    }
    //right
    if(isSafe(i,j+1,maze)){
        maze[i][j+1]=0;
        temp+='R';
        getPaths(ans,temp,maze,i,j+1);
        temp.pop_back();
        maze[i][j+1]=1;
    }
    //up
    if(isSafe(i-1,j,maze)){
        maze[i-1][j]=0;
        temp+='D';
        getPaths(ans,temp,maze,i-1,j);
        temp.pop_back();
        maze[i-1][j]=1;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<vector<int>> maze(n,vector<int>(n,0));
        vector<string> ans;
        string temp="";

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cin>>maze[i][j];
            }
        }

        getPaths(ans,temp,maze,0,0);
        for( auto i : ans) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}