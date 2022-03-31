using namespace std;
#include <bits/stdc++.h>
    bool isSafe(int i,int j,vector<vector<int>>& maze ){
         if(i<0 || i>=maze.size()) return false;
         else if(j<0 || j>=maze[0].size()) return false;
         return true;
     }
     int pathFinder(vector<vector<int>>& maze,vector<vector<int>>& track,int i,int j,int vacant){
        if(maze[i][j]==-1)
           return 0;
        if(maze[i][j]==2){
            if(vacant<0) 
                return 1;
            else return 0;
        }
        int sum=0;
        track[i][j]=1;

        if(isSafe(i+1,j,maze) && track[i+1][j]==0) 
            sum+=pathFinder(maze,track,i+1,j,vacant-1);

        if(isSafe(i,j+1,maze) && track[i][j+1]==0) 
            sum+=pathFinder(maze,track,i,j+1,vacant-1);

        if(isSafe(i-1,j,maze) && track[i-1][j]==0) 
            sum+=pathFinder(maze,track,i-1,j,vacant-1);

        if(isSafe(i,j-1,maze) && track[i][j-1]==0) 
            sum+=pathFinder(maze,track,i,j-1,vacant-1);
         
        track[i][j]=0;
         
        return sum;
     }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int a,b;
        vector<vector<int>> track(grid.size(),vector<int>(grid[0].size(),0));
        int vacant = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
              if(grid[i][j]==1){
                  a=i; b=j;
              }
              else if (grid[i][j]==0) vacant++;
            }
     return pathFinder(grid,track,a,b,vacant);
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    vector<vector<int>> maze = {{0,1},{2,0}};
    cout<<uniquePathsIII(maze);
    return 0;
}