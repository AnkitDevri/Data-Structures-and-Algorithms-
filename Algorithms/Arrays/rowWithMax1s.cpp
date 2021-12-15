using namespace std;
#include<bits/stdc++.h>

 int getMax1s(vector<vector<bool>> arr,int row,int col){
     bool status=true;
     int MAX=0;
     int k=-1;
     int i=0;
     int j=col-1;
     while(status){
         if(i>row-1 || j<0){
             status=0;
             continue;
         }
           
        
         if(arr[i][j]){
               MAX=j;
               k=i;
               j--;
          }
           
          else 
            i++;
      
     }
    return k;
 }
int main(){
    int row,col;
    bool element;
    cin>>row>>col;
    vector<vector<bool>> matrix(row,vector<bool>(col));
    for(int i=0;i<row;i++)
     for(int j=0;j<col;j++){
     cin>>element;
     matrix[i][j]=element;
     }
    cout<<getMax1s(matrix,row,col);
    getchar();
    return 0;
}