using namespace std;
#include<bits/stdc++.h>
 bool isSafe(int i,int j,vector<vector<int>>& maze ){
     if(i<0 || i>=maze.size())
      return false;
     else if(j<0 || j>=maze[0].size())
      return false;
     else
      return true;
 }
 void pathFinder(vector<vector<pair<int,int>>>& paths,vector<pair<int,int>>& path,vector<vector<int>>& maze,vector<vector<int>>& track,int i,int j){
     if(maze[i][j]==-1)
       return;
    if(maze[i][j]==2){
        path.push_back(make_pair(i,j));
        paths.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(make_pair(i,j));
    track[i][j]=1;

    if(isSafe(i+1,j,maze) && !track[i+1][j])
    pathFinder(paths,path,maze,track,i+1,j);

    if(isSafe(i,j+1,maze) && !track[i][j+1])
    pathFinder(paths,path,maze,track,i,j+1);

    if(isSafe(i-1,j,maze) && !track[i-1][j])
    pathFinder(paths,path,maze,track,i-1,j);

    if(isSafe(i,j-1,maze) && !track[i][j-1])
    pathFinder(paths,path,maze,track,i,j-1);
     
    path.pop_back();
    track[i][j]=0;
 }
int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n,0));
     vector<vector<int>> track(n,vector<int>(n,0));
    int i,j,l,m;

     cout<<"Enter Initial co-ordinates: ";
     cin>>l>>m;
     maze[l][m]=1;
     cout<<endl;

    cout<<"Enter Destination co-ordinates: ";
    cin>>i>>j;
    maze[i][j]=2;

    vector<vector<pair<int,int>>> paths;
    vector<pair<int,int>>path;

    pathFinder(paths,path,maze,track,l,m);
    for(int i=0;i<paths.size();i++){
    for(int j=0;j<paths[i].size();j++)
      cout<<"("<<paths[i][j].first<<","<<paths[i][j].second<<")"<<" ";
      cout<<endl;
    }
    getchar();
    return 0;
}