using namespace std;
#include<bits/stdc++.h>

int isPossible(vector<int>& arr,int& diff){
    int pointer1=0,pointer2=1;
    int count=0;
    while(pointer2!=arr.size()){
        if(arr[pointer2]-arr[pointer1]==diff || arr[pointer2]-arr[pointer1]==(diff*(-1))){ 
            if(pointer1!=pointer2) return 1;
            else pointer2++;
        }   
        else if(arr[pointer2]-arr[pointer1]<diff) pointer2++;
        else pointer1++;
    }
    return 0;
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