using namespace std;
#include<bits/stdc++.h>

void rotate90(vector<vector <int>> arr){
 int size=arr.size();
 for(int i=0;i<size;i++)
  for(int j=0;j<size;j++)
      if(i>j)
      swap(arr[i][j],arr[j][i]);

    for(int i=0;i<size;i++)
      reverse(arr[i].begin(),arr[i].end());
      
   for(int i=0;i<size;i++){
     for(int j=0;j<size;j++)  
       cout<<arr[i][j]<<" ";
       cout<<endl;
   }
 
      
}
int main(){
    int size;
    cin>>size;
   vector<vector<int>> arr(size, vector<int> (size));
    for(int i=0;i<size;i++)
     for(int j=0;j<size;j++)
      cin>>arr[i][j];
    rotate90(arr);
    getchar();
    return 0;
}