using namespace std;
#include<bits/stdc++.h>
 void getCom(vector<vector<int>>& combinations,vector<int>&set,int& k,int arr[],int index,int size){
  if(size==k){
     vector<int> temp;
     for(int i=0;i<size;i++)
        temp.push_back(arr[i]);
     combinations.push_back(temp);
     return;
  }
  for(int i=index;i<set.size();i++){
      arr[size]=set[i];
     getCom(combinations,set,k,arr,i+1,size+1);
  }
   
 }
int main(){
    int n,k;
    cin>>n>>k;
    int arr[k];
    vector<vector<int>> combinations;
    vector<int> set(n);
    for(int i=0;i<n;i++)
      set[i]=i+1;
    int setIndex=0;
    getCom(combinations,set,k,arr,0,setIndex);
    for(int i=0;i<combinations.size();i++){
    for(int j=0;j<combinations[i].size();j++)
        cout<<combinations[i][j]<<" ";
        cout<<endl;
    }

    getchar();
    return 0;
}