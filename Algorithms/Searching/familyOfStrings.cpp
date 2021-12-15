using namespace std;
#include<bits/stdc++.h>
 int getChar(int& n,int& k,int left,int right,int bit){
     int mid=(left+right)/2;
      if(k<mid) return getChar(n,k,left,mid-1,bit);
      else if(k>mid) return getChar(n,k,mid+1,left,1-bit);
      else return bit;
 }
int main(){
    int n,k;
    cin>>n>>k;
    int size=pow(2,n+1)-1;
    cout<<getChar(size,k,0,size-1,0);
    getchar();
    return 0;
}