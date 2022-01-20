using namespace std;
#include<bits/stdc++.h>
//only works for 2D matrix where last element of a row is smaller than first element of next row
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int idx,jdx;
        vector<int> col(matrix.size(),0);
        for(int i = 0 ; i < matrix.size(); i++) col[i]=matrix[i][0];
        idx=lower_bound(col.begin(),col.end(),target)-col.begin()-1;
        if(idx<0) idx++;
        if(idx!=matrix.size()-1 && matrix[idx+1][0]==target) return true;
        jdx = lower_bound(matrix[idx].begin(),matrix[idx].end(),target)-matrix[idx].begin();
        if(jdx<0 || jdx == matrix[0].size()) return false;
        if(matrix[idx][jdx]==target) return true;
        return false;
        
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int colSize,rowSize;
    cin>>rowSize>>colSize;

    vector<vector<int>> mat(rowSize,vector<int>(colSize,0));
    for(int i = 0 ; i < rowSize; i++)
        for(int j = 0; j < colSize; j++)
            cin>>mat[i][j];
    
    int target;
    cin>>target;
    cout<<searchMatrix(mat,target);
    return 0;
}