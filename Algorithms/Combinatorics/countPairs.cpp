#include<bits/stdc++.h>
using namespace std;
int countPairs(vector<int>arr,int k){
    int count=0;
    vector<int>counts(k,0);
    for(int i=0;i<arr.size();i++)
        counts[arr[i]%k]++;
    for(int i=1;i<=k/2;i++){
        if(i==k-i)
        count=count+(counts[i]*(counts[i]-1))/2;
        
        else
        count=count+(counts[i]*counts[k-i]);
    }
        
    
     count=count+(counts[0]*(counts[0]-1))/2;

     return count;
}
int main(){
    int n,k,element;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>element;
        arr[i]=element;
    }
    cout<<countPairs(arr,k);
    getchar();
    return 0;
}