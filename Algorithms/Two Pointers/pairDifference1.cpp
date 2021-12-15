using namespace std;
#include<bits/stdc++.h>

int isPossible(vector<int>& arr,int& diff){
    int pointer1=0,pointer2=1;
    int count=0;
    while(pointer2<arr.size()){
        if(arr[pointer2]-arr[pointer1]==diff || arr[pointer2]-arr[pointer1]==(diff*(-1))){ 
           if(diff==0){
             if(pointer1==pointer2) pointer2++;
             int element_count=1;

             while(arr[pointer1]==arr[pointer2]){
                  element_count++;
                  pointer1++;
                  pointer2++;
                }
                
             count+=(element_count*(element_count-1))/2;
           }
           else{
             int element1=arr[pointer1],element2=arr[pointer2];
             int count1=0,count2=0;

             while(arr[pointer1]==element1){
                  count1++;
                  pointer1++;
                }

             while(arr[pointer2]==element2){
                  count2++;
                  pointer2++;
                }

             count+=count1*count2;
           }
        }   
        else if(arr[pointer2]-arr[pointer1]<diff) pointer2++;
        else pointer1++;
    }
    return count;
}

int main(){
    int total_elements,element,difference;
    cin>>total_elements;
    cin>>difference;
    
    vector<int> arr(total_elements);
    for(int i=0;i<total_elements;i++){
        cin>>element;
        arr[i]=element;
    }
    
    cout<<isPossible(arr,difference);
    getchar();
    return 0;
}