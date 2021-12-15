using namespace std;
#include<bits/stdc++.h>
 void lexSubset(vector<vector<int>>& subsets,vector<int>& set,int arr[],int size,int index){
      vector<int> temp;
      for(int i=0;i<size;i++)
       temp.push_back(arr[i]);
     subsets.push_back(temp);

  if(index==set.size())
      return;

  for(int i=index;i<set.size();i++){
    arr[size]=set[i];
    lexSubset(subsets,set,arr,size+1,i+1);
  }
   
 }
int main(){
    vector<int> set;
    vector<vector<int>> subsets;
    int n,ele;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>ele;
        set.push_back(ele);
    }
    lexSubset(subsets,set,arr,0,0);
    for(int i=0;i<subsets.size();i++){
     for(int j=0;j<subsets[i].size();j++)
      cout<<subsets[i][j]<<" ";
      cout<<endl;
    }
    getchar();
    return 0;
}