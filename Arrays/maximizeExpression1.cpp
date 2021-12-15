using namespace std;
#include<iostream>
#include<climits>

void premax(int premax[],int arr[],int size,int p){
   premax[0]=p*arr[0];
   for(int i=1;i<size;i++)
   premax[i]=max(premax[i-1],p*arr[i]);
}

void sufmax(int sufmax[],int arr[],int size,int r){
    sufmax[size-1]=r*arr[size-1];
    for(int i=size-2;i>=0;i--)
    sufmax[i]=max(sufmax[i+1],r*arr[i]);   
}
void maximize(int premax[],int arr[],int sufmax[],int size,int p,int q,int r){
    int maxo=INT_MIN;                                                               //this method is only applicable for all integers
  for(int i=1;i<size-1;i++){
     maxo=max(maxo,(premax[i-1]+q*arr[i]+sufmax[i+1]));
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
    premax(lMax,arr,size,p);
    int rMax[size];
    sufmax(rMax,arr,size,r);
    maximize(lMax,arr,rMax,size,p,q,r);
    getchar();
    return 0;
}