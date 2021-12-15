#include<iostream>
using namespace std;
   void preMax(int temp[],int arr[],int size){
     temp[0]=arr[0];
     for(int i=1;i<size;i++)
      temp[i]=max(temp[i-1],arr[i]);
   }
   void sufMax(int temp[],int arr[],int size){
       temp[size-1]=arr[size-1];
       for(int i=size-2;i>=0;i--)
        temp[i]=max(temp[i+1],arr[i]);
   }
   void calculateWater(int lMax[],int arr[],int rMax[],int size){
       int water=0;
     for(int i=1;i<size-1;i++){
         if(lMax[i-1]>arr[i] && rMax[i+1]>arr[i])
         water=water+min(lMax[i-1],rMax[i+1])-arr[i];
     }
     cout<<endl<<water;
   }
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    int lMax[size],rMax[size];
    preMax(lMax,arr,size);
    sufMax(rMax,arr,size);
    calculateWater(lMax,arr,rMax,size);
    getchar();
    return 0;
}