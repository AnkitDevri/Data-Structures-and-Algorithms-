using namespace std;
#include<iostream>
  void printfrequency(int arr[],int size,int num,int k){
      int freq=0;
      for(int i=0;i<k;i++)
       if(arr[i]==num)
        freq++;
      cout<<freq<<" ";
      
     for(int i=k;i<size;i++){
         if(arr[i-k]==num)
         freq--;
         if(arr[i]==num)
         freq++;

      cout<<freq<<" ";
     }
       
  }
int main(){
    int k,num,total;
    cin>>k;
    cin>>num;
    cin>>total;
    int arr[total];
    for(int i=0;i<total;i++)
     cin>>arr[i];
    printfrequency(arr,total,num,k);
    getchar();
    return 0;
}