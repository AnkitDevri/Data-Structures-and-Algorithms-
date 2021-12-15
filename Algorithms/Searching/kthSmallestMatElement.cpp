using namespace std;
#include<bits/stdc++.h>
int ocurrings(vector<vector<int>>& data,int n){
    int count=0;
  /*  for(int i=0;i<data.size();i++)
     for(int j=0;j<data.size();j++){
        if(data[i][j]<=n) count++;
        else break;
     }
     */
    for(int i=0; i<data.size();i++){
        int left=0,right=data[i].size()-1;
        while(left<=right){
          int mid=(left+right)/2;
          if(data[i][mid]<=n && data[i][mid+1]>n){ count+=mid+1; break;}
          else if(data[i][mid]<=n) left=mid+1;
          else right=mid-1;
        }
    }
    
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
    vector<vector<int>> data(n,vector<int>(n,0));             // sub vector should be sorted i.e. the 2d vector should be sorted row wise only
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>ele;
        data[i][j]=ele;
    }
    int k;
    cin>>k;
    int MIN=INT_MAX,MAX=INT_MIN;
    for(int i=0;i<data.size();i++){
      MIN=min(MIN,data[i][0]);
      MAX=max(MAX,data[i][n-1]);
    }
    cout<<findSmallk(data,MIN,MAX,k);
    getchar();
    return 0;
}