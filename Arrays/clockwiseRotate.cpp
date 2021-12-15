using namespace std;
#include<iostream>
  void reverse(int arr[], int start,int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
  void clockwiseRotate(int arr[],int size,int k){
       if(k>size)
        k=k%size;
      reverse(arr,0,size-1);
       
      reverse(arr,0,k-1);
      
      reverse(arr,k,size-1);
      
      cout<<endl;
      for(int i=0;i<size;i++)
       cout<<arr[i]<<" ";
  }
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];
    cout<<"Enter the rotations: ";
    int k;
    cin>>k;
    clockwiseRotate(arr,size,k);
    getchar();
    return 0;
}