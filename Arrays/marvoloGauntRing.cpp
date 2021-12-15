using namespace std;
typedef long long int ll;
#include<iostream>
#include<climits>
 void preMax(ll temp[],ll arr[],ll p,ll size){
     temp[0]=p*arr[0];
     for(int i=1;i<size;i++)
     temp[i]=max(temp[i-1],p*arr[i]);
 }

  void sufMax(ll temp[],ll arr[],ll r,ll size){
      temp[size-1]=r*arr[size-1];
      for(int i=size-2;i>=0;i--)
      temp[i]=max(temp[i+1],r*arr[i]);
  }
 void countPotions(ll arr[],ll p,ll q,ll r,ll size){
  ll count=LLONG_MIN;
  ll pre[size];
  preMax(pre,arr,p,size);
  ll suf[size];
  sufMax(suf,arr,r,size);
  for(int i=0;i<size;i++){
   count=max(count,pre[i]+q*arr[i]+suf[i]);
  }
  cout<<count;
 }
int main(){
    ll size,p,q,r;
    cin>>size>>p>>q>>r;
    ll arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    countPotions(arr,p,q,r,size);
    getchar();
    return 0;
}