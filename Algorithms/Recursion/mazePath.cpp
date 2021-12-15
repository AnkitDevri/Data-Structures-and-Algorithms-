using namespace std;
#include<bits/stdc++.h>
 void pathFinder(vector<vector<pair<int,int>>>& paths,vector<pair<int,int>>& path,vector<vector<int>>& maze,int i,int j){
     if(maze[i][j]==1)
       return;
    if(i==maze.size()-1 && j==maze[0].size()-1){
        path.push_back(make_pair(i,j));
        paths.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(make_pair(i,j));
    if(i==maze.size()-1)
      pathFinder(paths,path,maze,i,j+1);
    else if(j==maze[0].size()-1)
       pathFinder(paths,path,maze,i+1,j);
    else{
    pathFinder(paths,path,maze,i+1,j);
    pathFinder(paths,path,maze,i,j+1);
     }
    path.pop_back();
 }
int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n,0));
    vector<vector<pair<int,int>>> paths;
    vector<pair<int,int>>path;
    pathFinder(paths,path,maze,0,0);
    for(int i=0;i<paths.size();i++){
    for(int j=0;j<paths[i].size();j++)
      cout<<"("<<paths[i][j].first<<","<<paths[i][j].second<<")"<<" ";
      cout<<endl;
    }
    getchar();
    return 0;
}