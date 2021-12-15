using namespace std;
#include<bits/stdc++.h>
int ocurrings(vector<vector<int>>& data,int n){
    int count=0;
    for(int i=0;i<data.size();i++)
     for(int j=0;j<data.size();j++)
        if(data[i][j]<=n) count++;
    
    return count;
}
int findSmallk(vector<vector<int>>& data,int start,int end,int& k){
  int mid=(start+end)/2;
  int count=ocurrings(data,mid);
  if(count<k) return findSmallk(data,mid+1,end,k);
  else{
      int t_count=ocurrings(data,mid-1);
      if(t_count<count) return mid;
      else return findSmallk(data,start,mid-1,k);
  }
}
int main(){
    int n,ele;
    cin>>n;
    vector<vector<int>> data(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>ele;
        data[i][j]=ele;
    }
    int k;
    cin>>k;
    int MIN=INT_MAX,MAX=INT_MIN;
    for(int i=0;i<data.size();i++){
      MIN=min(MIN,*min_element(data[i].begin(),data[i].end()));
      MAX=max(MAX,*max_element(data[i].begin(),data[i].end()));
    }
    cout<<findSmallk(data,MIN,MAX,k);
    getchar();
    return 0;
}