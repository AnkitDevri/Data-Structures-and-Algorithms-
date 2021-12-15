using namespace std;
#include<bits/stdc++.h>
int ocurrings(vector<int>& data,int n){
    int count=0;
    for(int i=0;i<data.size();i++)
      if(data[i]<=n) count++;
    return count;
}
int findSmallk(vector<int>& data,int start,int end,int& k){
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
    vector<int> data(n);
    for(int i=0;i<n;i++){
        cin>>ele;
        data[i]=ele;
    }
    int k;
    cin>>k;
    cout<<findSmallk(data,*min_element(data.begin(),data.end()),*max_element(data.begin(),data.end()),k);
    getchar();
    return 0;
}