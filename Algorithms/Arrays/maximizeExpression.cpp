using namespace std;
#include<iostream>
#include<climits>

void premax(int premax[],int arr[],int size){
   premax[0]=arr[0];
   for(int i=1;i<size;i++)
   premax[i]=max(premax[i-1],arr[i]);
}

void sufmax(int sufmax[],int arr[],int size){
    sufmax[size-1]=arr[size-1];
    for(int i=size-2;i>=0;i--)
    sufmax[i]=max(sufmax[i+1],arr[i]);   
}
void maximize(int premax[],int arr[],int sufmax[],int size,int p,int q,int r){
    int maxo=INT_MIN;                                                                //this method is only applicable if positive integers are involved only
  for(int i=1;i<size-1;i++){
     maxo=max(maxo,(p*premax[i-1]+q*arr[i]+r*sufmax[i+1]));
  }
  cout<<endl<<maxo;
}
int main(){
    int p,q,r,size;
    cin>>size;
    int arr[size];
    cin>>p>>q>>r;
    for(int i=0;i<size;i++)
    cin>>arr[i];
    int lMax[size];
    premax(lMax,arr,size);
    int rMax[size];
    sufmax(rMax,arr,size);
    maximize(lMax,arr,rMax,size,p,q,r);
    getchar();
    return 0;
}