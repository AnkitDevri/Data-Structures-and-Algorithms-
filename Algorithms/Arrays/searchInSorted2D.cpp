using namespace std;
#include<bits/stdc++.h>
    void binary2D(vector<vector<int>> arr,vector<int> &answer,int element){
      bool status=true;
      int i=0,j=arr[0].size()-1;
      int temp;
      while(status){
        if(i==arr.size() || j==arr[i].size())
          break;
         temp=arr[i][j];
        if(element==temp){
         answer[0]=i;
         answer[1]=j;
         status=false;
        }
         else if(element<temp)
          j--;
         else
          i++;
       }
         
    }
int main(){
    int row,col,element;
    cin>>row>>col;
    vector<vector<int>> arr(row,vector<int>(col));
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++){
    cin>>element;
    arr[i][j]=element;
    }
    cin>>element;
    vector<int> answer(2,-1);
    binary2D(arr,answer,element);
    cout<<answer[0]<<" "<<answer[1];
    getchar();
    return 0;
}