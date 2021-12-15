using namespace std;
#include<bits/stdc++.h>
 int getSum(vector<vector<int>> sample){
  int r=sample.size();
  int c=sample[0].size();
  int sum=0;
  for(int i=0;i<r;i++)
   for(int j=0;j<c;j++){
       int topLefts=(i+1)*(j+1);
       int bottomRights=(r-i)*(c-j);
        sum=sum+topLefts*bottomRights*sample[i][j];
   }
    return sum;
 }
int main(){
    int row,col,element;
    cin>>row>>col;

    vector<vector<int>> matrix(row,vector<int>(col));
    for(int i=0;i<row;i++)
     for(int j=0;j<col;j++){
       cin>>element;
        matrix[i][j]=element;
     }
     cout<<endl<<getSum(matrix); 
    getchar();
    return 0;
}