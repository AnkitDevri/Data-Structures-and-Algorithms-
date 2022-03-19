using namespace std;
#include<bits/stdc++.h>
void swap(vector<int>& arr,int idx){
    int temp = arr[idx];
    arr[idx]=arr[idx-1];
    arr[idx-1]=temp;
}
void merge(vector<int>& arr,int l,int r,int &k){
    if(k==0 || l>=r-1) return;
    int mid = (l+r)/2;
    swap(arr,mid);
    k-=2;
    merge(arr,l,mid,k);
    merge(arr,mid,r,k);
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i = 0; i<n; i++) arr[i]=i+1;
    if(k%2==0) cout<<-1;
    else {
        k--;
        merge(arr,0,n-1,k);
        for(auto i : arr) cout<<i<<" ";
    }
    
    return 0;
}