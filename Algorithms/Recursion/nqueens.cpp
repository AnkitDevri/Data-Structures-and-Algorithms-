using namespace std;
#include<bits/stdc++.h>
bool isSafe(int i,int j,vector<vector<int>>& board){
  bool check=true;
   for(int it=0;it<=i;it++){
       if(board[i-it][j]==0)
         check=true;
         else
         return false;

       if(j-it>=0 && j+it<board.size()){
         if(board[i-it][j-it]==0 && board[i-it][j+it]==0){
          check=true;
          continue;
         }
         else
         return false;
       }
       if(j-it>=0){
           if(board[i-it][j-it]==0)
           check=true;
           else
           return false;
       }
       if(j+it<board.size()){
           if(board[i-it][j+it]==0)
           check=true;
           else
           return false;
       }
        
   }
      return check;
}
void nqeens(vector<vector<pair<int,int>>>&allPos,vector<vector<int>>& board,vector<pair<int,int>>& positions,int i){
 if(i==board.size()){
      allPos.push_back(positions);
      return;
 }
 
 for(int it=0;it<board.size();it++){
    if(isSafe(i,it,board)){
        board[i][it]=1;
        positions.push_back(make_pair(i,it));
        nqeens(allPos,board,positions,i+1);
        positions.pop_back();
        board[i][it]=0;
    }
     
 }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<pair<int,int>> postions;
    vector<vector<pair<int,int>>> allPos;
    nqeens(allPos,board,postions,0);
     for(int i=0;i<allPos.size();i++){
      for(int j=0;j<allPos[i].size();j++)
      cout<<"("<<allPos[i][j].first<<","<<allPos[i][j].second<<")"<<" ";
      cout<<endl;
    }
    getchar();
    return 0;
}