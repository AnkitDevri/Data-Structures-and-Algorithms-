using namespace std;
#include<iostream>
#include<conio.h>
void merge(int arr[],int left, int mid, int right){
  int i=left,j=mid+1,k=left;    
  int temp[right+1];      // taking temporary array to return the sorted values
  while(i<=mid && j<=right){      // starting case when both the list begin to sort
    if(arr[i]<=arr[j]){
      temp[k]=arr[i];             // in case the element of 1st list is smaller then the 2nd half
      i++;
    }
    else{
      temp[k]=arr[j];             // in case the element of 2nd list is smaller then the 1st half
      j++;
    }
    k++;                         
  }                              // while loop end next left the unequal lists case

  if(i>mid){                     // in case of unequal no. of elements in lists when 1st list exceeds its limit
    while(j<=right){             // traversing the 2nd list which is longer than 1st
      temp[k]=arr[j]; 
      j++;
      k++;
    } 
  }
   else {
      while(i<=mid){           // traversing the 1st list which in case is longer than 2nd
        temp[k]=arr[i];
        i++;
        k++;
      }
    }
    for(int z=left;z<=right;z++)  // assigning all sorted values to the orignal list from temporary list
      arr[z]=temp[z];
}

void mergeSort(int arr[],int left,int right){
    if(left==right)             // return the control to stop recursing further since one element is left
    return;
  int mid= (left+right)/2;      // mid value in every case
  mergeSort(arr,left,mid);      // left half traversal using recursion
  mergeSort(arr,mid+1,right);   // right half traversal using recursion
  merge(arr,left,mid,right);    // core sorting function
   
}
int main(){
    int size,left,right;
    cin>>size;
    int sample[size];
    left=0;
    right=size-1;
    for(int i=0;i<size;i++)
    cin>>sample[i];

    mergeSort(sample,left,right);
    for(int i=0;i<size;i++)
    cout<<sample[i]<<" ";
    getch();
    return 0;
}