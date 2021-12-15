using namespace std;
#include<bits/stdc++.h>
vector<vector<int>> subsets;
void getSubSet(int index,vector<int>& set,int subset[],int size){
  if(index==set.size()){
    vector<int>temp;
     for(int i=0;i<size;i++)
      temp.push_back(subset[i]);
      subsets.push_back(temp);
     return;
  }
  
  getSubSet(index+1,set,subset,size);
  subset[size]=set[index];
  getSubSet(index+1,set,subset,size+1);
  
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    
    int n,ele;
    cin>>n;
    vector<int> set;
    for(int i=0;i<n;i++){
         cin>>ele;
         set.push_back(ele);
    }
    int subset[n];
    getSubSet(0,set,subset,0);

    for(int i=0;i<subsets.size();i++){
     for(int j=0;j<subsets[i].size();j++)
        cout<<subsets[i][j]<<" ";
         cout<<endl;
    }
    return 0;
}