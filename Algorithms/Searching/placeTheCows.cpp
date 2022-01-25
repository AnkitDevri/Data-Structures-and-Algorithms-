using namespace std;
#include<bits/stdc++.h>
bool verify(vector<int>& stalls,int n,int& cows){
  int cowCount=1;
  int dist=stalls[0];
  for(int i=1;i<stalls.size();i++){
     if(stalls[i]-dist>=n){
         cowCount++;
         dist=stalls[i];
     } 
  }
  if(cowCount>=cows) return true;
  else return false;
}

int MAXplace(vector<int>& stalls,int& cows,int start,int end){
    int mid=(start+end)/2;
    if(start>end) return mid;
    if(verify(stalls,mid,cows)){
        if(!verify(stalls,mid+1,cows)) return mid;
        else return MAXplace(stalls,cows,mid+1,end);
    }
    else return MAXplace(stalls,cows,start,mid-1);
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,ele;
        int cows;
        cin>>n;
        vector<int> stalls(n,0);
        for(int i=0;i<stalls.size();i++){
            cin>>ele;
            stalls[i]=ele;
        }
        int MIN,MAX;
        MIN=INT_MAX;
        cout<<MAXplace(stalls,cows,MIN,MAX)<<endl;
    }

      return 0;
}