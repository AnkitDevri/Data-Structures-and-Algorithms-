using namespace std;
#include<bits/stdc++.h>
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i , j;
        i = 0;
        j = matrix[0].size()-1;
        while(i !=matrix.size() && j !=-1){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;   
        }
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