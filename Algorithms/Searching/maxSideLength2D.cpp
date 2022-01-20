using namespace std;
#include<bits/stdc++.h>
void prefix2D(vector<vector<int>>& mat, vector<vector<int>>& pre2D){
 for(int i = 0; i < mat.size(); i++){
     pre2D[i][0]=mat[i][0];
    for(int j = 1; j < mat.size(); j++){
        pre2D[i][j] = pre2D[i][j-1] + mat[i][j];
    }
}
for(int i = 0; i < mat[0].size(); i++){
     pre2D[0][i]=mat[0][i];
    for(int j = 1; j < mat.size(); j++){
        pre2D[j][i] = pre2D[j-1][i] + mat[j][i];
    }
}
}
int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
    }
int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> mat(row,vector<int>(col,0));
    for(int i = 0; i < mat.size(); i++)
        for(int j = 0; j < mat.size(); j++)
            cin>>mat[i][j];

    int num;
    cin>>num;
    vector<vector<int>> pre2D(row,vector<int>(col,0));
    prefix2D(mat,pre2D);
    

    return 0;
}