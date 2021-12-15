#include<iostream>
using namespace std;
bool checkChunks(int arr[],int i,int j){
 int count=0;
 for(int k=i;k<=j;k++){
   if(arr[k]>=i && arr[k]<=j)
    count++;
 }
 if(count==j-i+1)
 return true;
 else
 return false;
}
   void getChunks(int arr[],int size){
       int i=0,answer=0;
       int j;
       while(i<size){
           for(j=i;j<size;j++){
               if(checkChunks(arr,i,j))
                 break;
           }
           i=j+1;
           answer++;
       }
       cout<<answer;
   }
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    getChunks(arr,size);
    getchar();
    return 0;
}