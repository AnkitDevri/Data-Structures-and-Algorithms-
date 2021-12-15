using namespace std;
#include<bits/stdc++.h>
 int getSubSum(int arr[],int size,int m){
     int sum=0;
   for(int i=0;i<size;i++)
      sum=(sum%m+((arr[i]%m*(i+1)%m)%m%m*(size-i)%m)%m%m)%m;

    return sum;
 }
int main(){
  int size;
  cin>>size;
  int m;
  cin>>m;
  int arr[size];
  for(int i=0;i<size;i++)
  cin>>arr[i];
  cout<<endl<<getSubSum(arr,size,m);

 getchar();
 return 0;
}