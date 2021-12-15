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
 int pathFinder(vector<vector<int>>& maze,vector<vector<int>>& track,int i,int j){
     if(maze[i][j]==-1)
       return 0;
    if(maze[i][j]==2){
        return 1;
    }
    int sum=0;
    track[i][j]=1;

    if(isSafe(i+1,j,maze) && !track[i+1][j]){
        sum+=pathFinder(maze,track,i+1,j);
    }

    if(isSafe(i,j+1,maze) && !track[i][j+1]){
    sum+=pathFinder(maze,track,i,j+1);
    }

    if(isSafe(i-1,j,maze) && !track[i-1][j]){
    sum+=pathFinder(maze,track,i-1,j);
    }

    if(isSafe(i,j-1,maze) && !track[i][j-1]){
    sum+=pathFinder(maze,track,i,j-1);
    }

    track[i][j]=0;
    return sum;
 }
int main(){
    int n,m,ele;
    cin>>n>>m;
    vector<vector<int>> maze(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        cin>>ele;
        maze[i][j]=ele;
    }
     
     vector<vector<int>> track(n,vector<int>(m,0));
    int a,b;
/*
     cout<<"Enter Initial co-ordinates: ";
     cin>>l>>m;
     maze[l][m]=1;
     cout<<endl;

    cout<<"Enter Destination co-ordinates: ";
    cin>>i>>j;
    maze[i][j]=2;
*/
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      if(maze[i][j]==1){
          a=i;
          b=j;
          break;
      }
    }
    cout<<pathFinder(maze,track,a,b);
    
    getchar();
    return 0;
}