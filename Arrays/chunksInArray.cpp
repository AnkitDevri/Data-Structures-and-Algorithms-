#include<iostream>
using namespace std;
 void preMax(int temp[],int arr[],int size){
  temp[0]=arr[0];
  for(int i=1;i<size;i++)
   temp[i]=max(temp[i-1],arr[i]);
 }
  void getchunks(int arr[],int size){
   int sample[size];
   int count=0;
   preMax(sample,arr,size);
   for(int i=0;i<size;i++)
   if(i==sample[i])
    count++;
    cout<<endl<<count;
  }
int main(){
    int size;
    cin>> size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    getchunks(arr,size);
    getchar();
    return 0;
}