using namespace std;
#include<iostream>
#include<climits>
#include<conio.h>
int maxContinousSum(int arr[],int size){
    int max=INT_MIN,maxAt=0;
    for(int i=0;i<size;i++){
      maxAt=maxAt+arr[i];
      if(max<maxAt)
       max=maxAt;
      
      if(maxAt<0)
       maxAt=0;   
    }
 return max;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<maxContinousSum(arr,size);
    getch();
    return 0;
}