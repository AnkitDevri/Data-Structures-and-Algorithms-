using namespace std;
#include<iostream>
    void printSubArraySum(int arr[],int size,int k){
        int sum=0;
        for(int i=0;i<k;i++)
           sum=sum+arr[i];
    
        for(int i=k;i<size;i++){
             cout<<sum<<" ";
            sum=sum+arr[i]-arr[i-k];
        } 
        cout<<sum<<" ";
    }
int main(){
    int size,k;
    cin>>k;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    printSubArraySum(arr,size,k);
    getchar();
    return 0;
}