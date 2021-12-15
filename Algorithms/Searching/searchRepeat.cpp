using namespace std;
#include<bits/stdc++.h>

int searchRepeat(vector<int>& data,int left,int right){
 int mid=(left+right)/2;
 if(mid==left && left==right){
     if(mid==0){
      if(data[mid]==data[mid+1])
        return mid;
     }
     else if(mid==data.size()-1){
        if(data[mid]==data[mid-1])
        return mid;
     }
     else{
         if(data[mid]==data[mid+1] || data[mid-1]==data[mid])
          return mid;
     }
 }
 if(data[mid]==mid && data[mid-1]==data[mid]){
     return mid;
 }
 else if(data[mid]==mid+1)
    return searchRepeat(data,mid+1,right);
 else 
    return searchRepeat(data,left,mid);
}


int main(){
    int n,ele;
    cin>>n;
    vector<int> data(n,0);
    for(int i=0;i<n;i++){
        cin>>ele;
        data[i]=ele;
    }
    int idx=searchRepeat(data,0,n-1);
    if(idx!=-1)
    cout<<data[idx];
    else
    cout<<"\nNot Found";
    getchar();
    return 0;
}