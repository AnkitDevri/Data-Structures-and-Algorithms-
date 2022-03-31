#include <bits/stdc++.h>
using namespace std;
    vector<pair<int,int>> ans;
    vector<pair<int,int>> temp;
    bool isSafe(int i,int j,vector<vector<int>>& maze){
         if(i<0 || i>=maze.size()) 
            return false;
         else if(j<0 || j>=maze[0].size()) 
            return false;
         else if(i==maze.size()-1 && j==maze.size()-1) 
            return true;
         return maze[i][j]>0;
     }
    bool help(vector<vector<int>>& matrix,int count,int i,int j){
         bool out;
         if(i==matrix.size()-1 && j==matrix.size()-1){
            if(ans.size()==0){
                ans=temp;
            }
             return true;
         }
         bool right;
         bool down;
         for(int k = 1; k<=count; k++){
             if(isSafe(i,j+k,matrix)){
                temp.push_back(make_pair(i,j+k));
                right = help(matrix,matrix[i][j+k],i,j+k);
                if(right) out=true;
                temp.pop_back();
             }
            
             if(isSafe(i+k,j,matrix)){
                temp.push_back(make_pair(i+k,j));
                down = help(matrix,matrix[i+k][j],i+k,j);
                if(left) out=true;
                temp.pop_back();
             }
         }
         return out;
     }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   if(help(matrix,matrix[0][0],0,0)) {
	       vector<vector<int>> vec(matrix.size(),vector<int>(matrix.size(),0));
	       for(auto i : ans) vec[i.first][i.second]=1;
           vec[0][0]=1;
	       return vec;
	   }
	   return {{-1}};
	}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for( int i = 0; i<n ; i++){
        for( int j = 0; j<n; j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> ans = ShortestDistance(v);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}