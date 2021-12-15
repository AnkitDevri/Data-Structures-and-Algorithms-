using namespace std;
#include<bits/stdc++.h>
void rearrange(vector<int>& arr){
    int size=arr.size();
    for(int i=0;i<arr.size();i++){
     int oldVal=arr[i]%size;                  // since all values are less than size there will be no change if the values had not been altered       
     arr[oldVal]=size*i+arr[oldVal];         // we use the formula value=size*newVal+oldVal as our identification base for all values
    }
    for(int i=0;i<size;i++)
     arr[i]=arr[i]/size;
}

int main(){
    int n,element;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
         cin>>element;
         arr[i]=element;
    }
    rearrange(arr);
     for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
    getchar();
    return 0;
}